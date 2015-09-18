#pragma once
/*
Port of class MessagingDatabase from TextSecure-android
*/

// [ ] done
// TFS ID: 472

#include "Database.h"
#include "MmsSmsColumns.h"
#include "documents\Document.h"

class MessagingDatabase :
  public Database, MmsSmsColumns
{
private:
  static const unsigned char* TAG; // TODO = MessagingDatabase.class.getSimpleName();
public:
  virtual ~MessagingDatabase();

  MessagingDatabase(/* TODO OS SPECIFIC Context*/ void* context, /* TODO OS SPECIFIC SQLiteOpenHelper*/ void* databaseHelper);
  virtual unsigned char* GetTableName() = 0;
  void SetMismatchedIdentity(long messageId, const long recipientId, const /* TODO other lib IdentityKey*/ void* identityKey);
  void AddMismatchedIdentity(long messageId, long recipientId, /* TODO other lib IdentityKey*/ void* identityKey);
  void RemoveMismatchedIdentity(long messageId, long recipientId, /* TODO other lib IdentityKey*/ void* identityKey);
  /* BIG TODO <D extends Document<I>, I> void RemoveFromDocument(long messageId, String column, I object, Class<D> clazz); */
  /* BIG TODO <T extends Document<I>, I> void addToDocument(long messageId, String column, final I object, Class<T> clazz) throws IOException */
  /* BIG TODO <T extends Document<I>, I> void addToDocument(long messageId, String column, List<I> objects, Class<T> clazz) throws IOException */

private:
  void setDocument(/* TODO OS SPECIFIC SQLiteDatabase*/ void* database, long messageId, unsigned char* column, Document* document) /*throws IOException*/;
  /* BIG TODO <D extends Document> D getDocument(SQLiteDatabase database, long messageId,String column, Class<D> clazz);*/
};

