#include "PersistentStorage.h"

PersistentStorage::DatabaseHelper::DatabaseHelper(OsIndependentContext* context, OsIndependentString* name)
{
  helper = FactorySQLiteOpenHelper::GetInstance()
    ->CreateNewHelper(context, name, nullptr, DATABASE_VERSION);
}
//@Override
void PersistentStorage::DatabaseHelper::OnCreate(OsIndependentSQLiteDatabase* db)
{
  db->ExecSQL((OsIndependentString*)DATABASE_CREATE);
}
//@Override
void PersistentStorage::DatabaseHelper::OnUpgrade(OsIndependentSQLiteDatabase* db, int oldVersion, int newVersion)
{ }
//@Override
OsIndependentSQLiteDatabase* PersistentStorage::DatabaseHelper::GetWritableDatabase()
{
  return this->helper->GetWritableDatabase();
}
//@Override
OsIndependentSQLiteDatabase* PersistentStorage::DatabaseHelper::GetReadableDatabase()
{
  return this->helper->GetReadableDatabase();
}

PersistentStorage::PersistentStorage(OsIndependentContext* context, OsIndependentString* name,
  JobSerializer* serializer,
  AggregateDependencyInjector* dependencyInjector)
{
  this->databaseHelper = new DatabaseHelper(context, FactoryString::GetInstance()->CreateNewString("_jobqueue-")->Append(name));
    //FactorySQLiteOpenHelper::GetInstance()->CreateNewHelper();
    // new OsIndependentSQLiteOpenHelper(context, "_jobqueue-" + name);
  this->context = context;
  this->jobSerializer = serializer;
  this->dependencyInjector = dependencyInjector;
}
void PersistentStorage::Store(Job* job) /*throws IOException*/
{
  OsIndependentContentValues* contentValues = FactoryContentValues::GetInstance()->CreateNewContentValues();
  contentValues->Put((OsIndependentString*)ITEM, jobSerializer->Serialize(job));
  contentValues->Put((OsIndependentString*)ENCRYPTED, job->GetEncryptionKeys() != nullptr);

  long id = databaseHelper->GetWritableDatabase()->Insert((OsIndependentString*)TABLE_NAME, nullptr, contentValues);
  job->SetPersistentId(id);
}
List<Job*>* PersistentStorage::GetAllUnencrypted()
{
  return PersistentStorage::GetJobs(nullptr, ENCRYPTED->Append(FactoryString::GetInstance()->CreateNewString(" = 0")));
}
List<Job*>* PersistentStorage::GetAllEncrypted(EncryptionKeys* keys)
{
  return GetJobs(keys, ENCRYPTED->Append(FactoryString::GetInstance()->CreateNewString(" = 1")));
}
List<Job*>* PersistentStorage::GetJobs(EncryptionKeys* keys, OsIndependentString* where)
{
  List<Job*>* results = new LinkedList<Job*>();
  OsIndependentSQLiteDatabase* database = databaseHelper->GetReadableDatabase();
  OsIndependentCursor* cursor = nullptr;
  try
  {
    cursor = database->Query((OsIndependentString*)TABLE_NAME, nullptr, where, nullptr, nullptr, nullptr, ID->Append(FactoryString::GetInstance()->CreateNewString(" ASC")), nullptr);
    while (cursor->MoveToNext())
    {
      long id = cursor->GetLong(cursor->GetColumnIndexOrThrow((OsIndependentString*)ID));
      OsIndependentString* item = cursor->GetString(cursor->GetColumnIndexOrThrow((OsIndependentString*)ITEM));
      bool encrypted = cursor->GetInt(cursor->GetColumnIndexOrThrow((OsIndependentString*)ENCRYPTED)) == 1;
      try
      {
        Job* job = jobSerializer->Deserialize(keys, encrypted, item);
        job->SetPersistentId(id);
        job->SetEncryptionKeys(keys);
        dependencyInjector->InjectDependencies(context, job);
        results->Add(job);
      }
      catch (IOException e)
      {
        // Log.w("PersistentStore", e);
        Remove(id);
      }
    }
  }
  catch (IOException e)
  {
  }
  if (cursor != nullptr)
    cursor->Close();
  return results;
}
void PersistentStorage::Remove(long id)
{
  List<OsIndependentString*>* list = new List<OsIndependentString*>();
  list->Add(FactoryString::GetInstance()->CreateNewString(id));
  databaseHelper->GetWritableDatabase()->Delete((OsIndependentString*)TABLE_NAME, ID->Append(FactoryString::GetInstance()->CreateNewString(" = ?")), list);
}
