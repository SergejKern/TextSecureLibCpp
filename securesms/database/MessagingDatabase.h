#pragma once
/*
Port of class MessagingDatabase from TextSecure-android
*/

// [ ] done
// TFS ID: 472

#include "Database.h"
#include "MmsSmsColumns.h"
#include "documents\Document.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentSQLiteOpenHelper.h"
#include "..\..\osindependent\OsIndependentSQLiteDatabase.h"
#include "..\..\otherproject\IdentityKey.h"

class MessagingDatabase :
  public Database, public MmsSmsColumns
{
private:
  static const unsigned char* TAG;
public:
  virtual ~MessagingDatabase();

  MessagingDatabase(OsIndependentContext* context, OsIndependentSQLiteOpenHelper* databaseHelper);
  virtual unsigned char* GetTableName() = 0;
  void SetMismatchedIdentity(long messageId, const long recipientId, IdentityKey* identityKey);
  void AddMismatchedIdentity(long messageId, long recipientId, IdentityKey* identityKey);
  void RemoveMismatchedIdentity(long messageId, long recipientId, IdentityKey* identityKey);
  /* BIG TODO <D extends Document<I>, I> void RemoveFromDocument(long messageId, String column, I object, Class<D> clazz); */
  /* BIG TODO <T extends Document<I>, I> void addToDocument(long messageId, String column, final I object, Class<T> clazz) throws IOException */
  /* BIG TODO <T extends Document<I>, I> void addToDocument(long messageId, String column, List<I> objects, Class<T> clazz) throws IOException */

private:
  template<typename T> void SetDocument(OsIndependentSQLiteDatabase* database, long messageId, unsigned char* column, Document<T>* document) /*throws IOException*/;
  /* BIG TODO <D extends Document> D getDocument(SQLiteDatabase database, long messageId,String column, Class<D> clazz);*/
};

const unsigned char* TAG = (unsigned char*)"MessagingDatabase";
