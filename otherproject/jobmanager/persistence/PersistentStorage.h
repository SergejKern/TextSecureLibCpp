#pragma once
/*
Port of class PersistentStorage from jobmanager-android
*/

// [x] done
// TFS ID: 775

//import android.content.ContentValues;
#include "..\..\..\Factory\Factory.h"
//import android.util.Log;

#include "JobSerializer.h"
#include "..\EncryptionKeys.h"
#include "..\Job.h"
#include "..\dependencies\AggregateDependencyInjector.h"
//
#include "..\..\..\javastuff\IOException.h"
#include <list>

class PersistentStorage
{
private:
  class DatabaseHelper
    /* sollte von OsIndependentSQLiteOpenHelper abgeleitet sein,
       kann aber nicht, weil OsIndependentXY explizit 
       auf Zielplattformen abgeleitet werden sollen */
  {
  private :
    OsIndependentSQLiteOpenHelper* helper;
  public:
    DatabaseHelper(OsIndependentContext* context, OsIndependentString* name);
    void OnCreate(OsIndependentSQLiteDatabase* db) /*override*/;
    void OnUpgrade(OsIndependentSQLiteDatabase* db, int oldVersion, int newVersion) /*override*/;
    OsIndependentSQLiteDatabase* GetWritableDatabase();
    OsIndependentSQLiteDatabase* GetReadableDatabase();
  };
private:
  static const int DATABASE_VERSION = 1;

  static const OsIndependentString* TABLE_NAME;
  static OsIndependentString* ID;
  static const OsIndependentString* ITEM;
  static OsIndependentString* ENCRYPTED;
  static const OsIndependentString* DATABASE_CREATE;
  OsIndependentContext* context;
  DatabaseHelper* databaseHelper;
  JobSerializer* jobSerializer;
  AggregateDependencyInjector* dependencyInjector;
public:
  PersistentStorage(OsIndependentContext* context, OsIndependentString* name,
    JobSerializer* serializer,
    AggregateDependencyInjector* dependencyInjector);
  void Store(Job* job) /*throws IOException*/;
  std::list<Job*>* GetAllUnencrypted();
  std::list<Job*>* GetAllEncrypted(EncryptionKeys* keys);
  std::list<Job*>* GetJobs(EncryptionKeys* keys, OsIndependentString* where);
  void Remove(long id);
};

const OsIndependentString* PersistentStorage::TABLE_NAME = FactoryString::GetInstance()->CreateNewString("queue");
OsIndependentString* PersistentStorage::ID = FactoryString::GetInstance()->CreateNewString("_id");
const OsIndependentString* PersistentStorage::ITEM = FactoryString::GetInstance()->CreateNewString("item");
OsIndependentString* PersistentStorage::ENCRYPTED = FactoryString::GetInstance()->CreateNewString("encrypted");

// TODO: May be it it nesessary to use plattform specific SQL!!!
const OsIndependentString* PersistentStorage::DATABASE_CREATE = FactoryString::GetInstance()->CreateNewString("CREATE TABLE queue (%_id INTEGER PRIMARY KEY, item TEXT NOT NULL, encrypted INTEGER DEFAULT 0);");
