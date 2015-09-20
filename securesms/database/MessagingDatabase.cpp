#include "MessagingDatabase.h"

MessagingDatabase::~MessagingDatabase()
{
}

MessagingDatabase::MessagingDatabase(/* TODO OS SPECIFIC Context*/ void* context, /* TODO OS SPECIFIC SQLiteOpenHelper*/ void* databaseHelper) : Database(context, databaseHelper)
{
}

void MessagingDatabase::SetMismatchedIdentity(long messageId, const long recipientId, const /* TODO other lib IdentityKey*/ void* identityKey)
{
  /* TODO 
  List<IdentityKeyMismatch> items = new ArrayList<IdentityKeyMismatch>() {
    {
      add(new IdentityKeyMismatch(recipientId, identityKey));
    }
  };

  IdentityKeyMismatchList document = new IdentityKeyMismatchList(items);

  SQLiteDatabase database = databaseHelper.getWritableDatabase();
  database.beginTransaction();

  try {
    setDocument(database, messageId, MISMATCHED_IDENTITIES, document);

    database.setTransactionSuccessful();
  }
  catch (IOException ioe) {
    Log.w(TAG, ioe);
  }
  finally {
    database.endTransaction();
  }
  */
}

void MessagingDatabase::AddMismatchedIdentity(long messageId, long recipientId, /* TODO other lib IdentityKey*/ void* identityKey)
{
  /* TODO
  try {
    addToDocument(messageId, MISMATCHED_IDENTITIES,
      new IdentityKeyMismatch(recipientId, identityKey),
      IdentityKeyMismatchList.class);
  }
  catch (IOException e) {
    Log.w(TAG, e);
  }
  */
}

void MessagingDatabase::RemoveMismatchedIdentity(long messageId, long recipientId, /* TODO other lib IdentityKey*/ void* identityKey)
{
  /* TODO
  try {
    removeFromDocument(messageId, MISMATCHED_IDENTITIES,
      new IdentityKeyMismatch(recipientId, identityKey),
      IdentityKeyMismatchList.class);
  }
  catch (IOException e) {
    Log.w(TAG, e);
  }
  */
}

/* BIG TODO <D extends Document<I>, I> void MessagingDatabase::RemoveFromDocument(long messageId, String column, I object, Class<D> clazz)
{
SQLiteDatabase database = databaseHelper.getWritableDatabase();
database.beginTransaction();

try {
D           document = getDocument(database, messageId, column, clazz);
Iterator<I> iterator = document.getList().iterator();

while (iterator.hasNext()) {
I item = iterator.next();

if (item.equals(object)) {
iterator.remove();
break;
}
}

setDocument(database, messageId, column, document);
database.setTransactionSuccessful();
}
finally {
database.endTransaction();
}
}
*/

/* BIG TODO <T extends Document<I>, I> void MessagingDatabase::AddToDocument(long messageId, String column, final I object, Class<T> clazz) throws IOException{
List<I> list = new ArrayList<I>() {
{
add(object);
}
};

addToDocument(messageId, column, list, clazz);
} */

/* BIG TODO <T extends Document<I>, I> void MessagingDatabase::AddToDocument(long messageId, String column, List<I> objects, Class<T> clazz) throws IOException{
SQLiteDatabase database = databaseHelper.getWritableDatabase();
database.beginTransaction();

try {
T document = getDocument(database, messageId, column, clazz);
document.getList().addAll(objects);
setDocument(database, messageId, column, document);

database.setTransactionSuccessful();
}
finally {
database.endTransaction();
}
}
*/

void MessagingDatabase::SetDocument(/* TODO OS SPECIFIC SQLiteDatabase*/ void* database, long messageId, unsigned char* column, Document* document) /*throws IOException*/
{
  /* TODO OS SPECIFIC ContentValues contentValues = new ContentValues();

  if (document == null || document.size() == 0) {
    contentValues.put(column, (String)null);
  }
  else {
    contentValues.put(column, JsonUtils.toJson(document));
  }

  database.update(getTableName(), contentValues, ID_WHERE, new String[] {String.valueOf(messageId)});
  */
}

/* BIG TODO <D extends Document> D getDocument(SQLiteDatabase database, long messageId,
String column, Class<D> clazz)
{
Cursor cursor = null;

try {
cursor = database.query(getTableName(), new String[] {column},
ID_WHERE, new String[] {String.valueOf(messageId)},
null, null, null);

if (cursor != null && cursor.moveToNext()) {
String document = cursor.getString(cursor.getColumnIndexOrThrow(column));

try {
if (!TextUtils.isEmpty(document)) {
return JsonUtils.fromJson(document, clazz);
}
}
catch (IOException e) {
Log.w(TAG, e);
}
}

try {
return clazz.newInstance();
}
catch (InstantiationException e) {
throw new AssertionError(e);
}
catch (IllegalAccessException e) {
throw new AssertionError(e);
}

}
finally {
if (cursor != null)
cursor.close();
}
}*/
