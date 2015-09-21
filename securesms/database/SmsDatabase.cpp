#include "SmsDatabase.h"
/*
Port of class MessagingDatabase from TextSecure-android
*/

// [ ] done
// TFS ID: 486

SmsDatabase::~SmsDatabase()
{
}
SmsDatabase::Reader::Reader(OsIndependentCursor* cursor, OsIndependentContext* context)
{
  this->cursor = cursor;
  this->context = context;
}
SmsMessageRecord* SmsDatabase::Reader::GetNext()
{
  if (this->cursor == nullptr || !this->cursor->MoveToNext())
    return nullptr;

  return GetCurrent();
}
int SmsDatabase::Reader::GetCount()
{
  if (this->cursor == nullptr)
    return 0;
  else
    return this->cursor->GetCount();
}
SmsMessageRecord* SmsDatabase::Reader::GetCurrent()
{
  long messageId = cursor->GetLong(cursor->GetColumnIndexOrThrow((unsigned char*)(SmsDatabase::ID)));
  unsigned char* address = cursor->GetString(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::ADDRESS));
  int addressDeviceId = cursor->GetInt(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::ADDRESS_DEVICE_ID));
  long type = cursor->GetLong(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::TYPE));
  long dateReceived = cursor->GetLong(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::NORMALIZED_DATE_RECEIVED));
  long dateSent = cursor->GetLong(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::NORMALIZED_DATE_SENT));
  long threadId = cursor->GetLong(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::THREAD_ID));
  int status = cursor->GetInt(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::STATUS));
  int receiptCount = cursor->GetInt(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::RECEIPT_COUNT));
  unsigned char* mismatchDocument = cursor->GetString(cursor->GetColumnIndexOrThrow((unsigned char*)SmsDatabase::MISMATCHED_IDENTITIES));

  IdentityKeyMismatch* mismatches = GetMismatches(mismatchDocument);
  Recipients* recipients = GetRecipientsFor(address);
  DisplayRecord::Body body = GetBody(this->cursor);

  return new SmsMessageRecord(context, messageId, body, recipients,
    recipients->GetPrimaryRecipient(),
    addressDeviceId,
    dateSent, dateReceived, receiptCount, type,
    threadId, status, mismatches);
}
Recipients* SmsDatabase::Reader::GetRecipientsFor(unsigned char* address)
{
  if (address != nullptr) {
    Recipients recipients = RecipientFactory.getRecipientsFromString(context, address, true);

    if (recipients == nullptr || recipients->IsEmpty()) {
      return RecipientFactory.getRecipientsFor(context, Recipient::GetUnknownRecipient(), true);
    }

    return recipients;
  }
  else {
    Log.w(TAG, "getRecipientsFor() address is null");
    return RecipientFactory.getRecipientsFor(context, Recipient::GetUnknownRecipient(), true);
  }
}
void SmsDatabase::Reader::Close()
{
  this->cursor->Close();
}
DisplayRecord::Body SmsDatabase::Reader::GetBody(OsIndependentCursor* cursor)
{
  long type = cursor->GetLong(cursor->GetColumnIndexOrThrow(SmsDatabase::TYPE));
  unsigned char* body = cursor->GetString(cursor->GetColumnIndexOrThrow(SmsDatabase::BODY));

  if (Types::IsSymmetricEncryption(type)) {
    return new DisplayRecord::Body(body, false);
  }
  else {
    return new DisplayRecord::Body(body, true);
  }
}
IdentityKeyMismatch* SmsDatabase::Reader::GetMismatches(unsigned char* document)
{
  /*
  try {
    if (!TextUtils.isEmpty(document)) {
      return JsonUtils.fromJson(document, IdentityKeyMismatchList.class).getList();
    }
  }
  catch (IOException e) {
    Log.w(TAG, e);
  }

  return new LinkedList<>();
  */
}
SmsDatabase::SmsDatabase(OsIndependentContext* context, OsIndependentSQLiteOpenHelper* databaseHelper)
  :MessagingDatabase(context, databaseHelper)
{
  this->jobManager = ApplicationContext::GetInstance(context)->GetJobManager();
}
void SmsDatabase::UpdateTypeBitmask(long id, long maskOff, long maskOn)
{
  /*
  Log.w("MessageDatabase", "Updating ID: " + id + " to base type: " + maskOn);

  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  db.execSQL("UPDATE " + TABLE_NAME +
    " SET " + TYPE + " = (" + TYPE + " & " + (Types.TOTAL_MASK - maskOff) + " | " + maskOn + " )" +
    " WHERE " + ID + " = ?", new String[] {id + ""});

  long threadId = getThreadIdForMessage(id);

  DatabaseFactory.getThreadDatabase(context).update(threadId);
  notifyConversationListeners(threadId);
  notifyConversationListListeners();
  */
}
long SmsDatabase::GetThreadIdForMessage(long id)
{
  /*
  String sql = "SELECT " + THREAD_ID + " FROM " + TABLE_NAME + " WHERE " + ID + " = ?";
  String[] sqlArgs = new String[] {id + ""};
  SQLiteDatabase db = databaseHelper.getReadableDatabase();

  Cursor cursor = null;

  try {
    cursor = db.rawQuery(sql, sqlArgs);
    if (cursor != null && cursor.moveToFirst())
      return cursor.getLong(0);
    else
      return -1;
  }
  finally {
    if (cursor != null)
      cursor.close();
  }
  */
}
int SmsDatabase::GetMessageCount()
{
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  Cursor cursor = null;

  try {
    cursor = db.query(TABLE_NAME, new String[] {"COUNT(*)"}, null, null, null, null, null);

    if (cursor != null && cursor.moveToFirst()) return cursor.getInt(0);
    else                                        return 0;
  }
  finally {
    if (cursor != null)
      cursor.close();
  }
}
int SmsDatabase::GetMessageCountForThread(long threadId)
{
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  Cursor cursor = null;

  try {
    cursor = db.query(TABLE_NAME, new String[] {"COUNT(*)"}, THREAD_ID + " = ?",
      new String[] {threadId + ""}, null, null, null);

    if (cursor != null && cursor.moveToFirst())
      return cursor.getInt(0);
  }
  finally {
    if (cursor != null)
      cursor.close();
  }

  return 0;
}
void SmsDatabase::MarkStatus(long id, int status)
{
  Log.w("MessageDatabase", "Updating ID: " + id + " to status: " + status);
  ContentValues contentValues = new ContentValues();
  contentValues.put(STATUS, status);

  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  db.update(TABLE_NAME, contentValues, ID_WHERE, new String[] {id + ""});
  notifyConversationListeners(getThreadIdForMessage(id));
}
void SmsDatabase::IncrementDeliveryReceiptCount(unsigned char* address, long timestamp)
{
  SQLiteDatabase database = databaseHelper.getWritableDatabase();
  Cursor         cursor = null;

  try {
    cursor = database.query(TABLE_NAME, new String[] {ID, THREAD_ID, ADDRESS, TYPE},
      DATE_SENT + " = ?", new String[] {String.valueOf(timestamp)},
      null, null, null, null);

    while (cursor.moveToNext()) {
      if (Types.isOutgoingMessageType(cursor.getLong(cursor.getColumnIndexOrThrow(TYPE)))) {
        try {
          String theirAddress = canonicalizeNumber(context, address);
          String ourAddress = canonicalizeNumber(context, cursor.getString(cursor.getColumnIndexOrThrow(ADDRESS)));

          if (ourAddress.equals(theirAddress)) {
            database.execSQL("UPDATE " + TABLE_NAME +
              " SET " + RECEIPT_COUNT + " = " + RECEIPT_COUNT + " + 1 WHERE " +
              ID + " = ?",
              new String[] {String.valueOf(cursor.getLong(cursor.getColumnIndexOrThrow(ID)))});

            notifyConversationListeners(cursor.getLong(cursor.getColumnIndexOrThrow(THREAD_ID)));
          }
        }
        catch (InvalidNumberException e) {
          Log.w("SmsDatabase", e);
        }
      }
    }
  }
  finally {
    if (cursor != null)
      cursor.close();
  }
}
void SmsDatabase::SetMessagesRead(long threadId)
{
  SQLiteDatabase database = databaseHelper.getWritableDatabase();
  ContentValues contentValues = new ContentValues();
  contentValues.put(READ, 1);

  database.update(TABLE_NAME, contentValues,
    THREAD_ID + " = ? AND " + READ + " = 0",
    new String[] {threadId + ""});
}
void SmsDatabase::SetAllMessagesRead()
{
  SQLiteDatabase database = databaseHelper.getWritableDatabase();
  ContentValues contentValues = new ContentValues();
  contentValues.put(READ, 1);

  database.update(TABLE_NAME, contentValues, null, null);
}
/* TODO Pair<Long, Long>*/void* SmsDatabase::UpdateMessageBodyAndType(long messageId, unsigned char* body, long maskOff, long maskOn)
{
  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  db.execSQL("UPDATE " + TABLE_NAME + " SET " + BODY + " = ?, " +
    TYPE + " = (" + TYPE + " & " + (Types.TOTAL_MASK - maskOff) + " | " + maskOn + ") " +
    "WHERE " + ID + " = ?",
    new String[] {body, messageId + ""});

  long threadId = GetThreadIdForMessage(messageId);

  DatabaseFactory.getThreadDatabase(context).update(threadId);
  notifyConversationListeners(threadId);
  notifyConversationListListeners();

  return new Pair<>(messageId, threadId);
}
/* TODO Pair<Long, Long>*/void* SmsDatabase::CopyMessageInbox(long messageId)
{
  Reader           reader = readerFor(getMessage(messageId));
  SmsMessageRecord record = reader.getNext();

  ContentValues contentValues = new ContentValues();
  contentValues.put(TYPE, (record.getType() & ~Types.BASE_TYPE_MASK) | Types.BASE_INBOX_TYPE);
  contentValues.put(ADDRESS, record.getIndividualRecipient().getNumber());
  contentValues.put(ADDRESS_DEVICE_ID, record.getRecipientDeviceId());
  contentValues.put(DATE_RECEIVED, System.currentTimeMillis());
  contentValues.put(DATE_SENT, record.getDateSent());
  contentValues.put(PROTOCOL, 31337);
  contentValues.put(READ, 0);
  contentValues.put(BODY, record.getBody().getBody());
  contentValues.put(THREAD_ID, record.getThreadId());

  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  long           newMessageId = db.insert(TABLE_NAME, null, contentValues);

  DatabaseFactory.getThreadDatabase(context).update(record.getThreadId());
  notifyConversationListeners(record.getThreadId());

  jobManager.add(new TrimThreadJob(context, record.getThreadId()));
  reader.close();

  return new Pair<>(newMessageId, record.getThreadId());
}
/* TODO Pair<Long, Long>*/void* SmsDatabase::InsertMessageInbox(IncomingTextMessage* message, long type)
{
  if (message.isPreKeyBundle()) {
    type |= Types.KEY_EXCHANGE_BIT | Types.KEY_EXCHANGE_BUNDLE_BIT;
  }
  else if (message.isSecureMessage()) {
    type |= Types.SECURE_MESSAGE_BIT;
  }
  else if (message.isGroup()) {
    type |= Types.SECURE_MESSAGE_BIT;
    if (((IncomingGroupMessage)message).isUpdate()) type |= Types.GROUP_UPDATE_BIT;
    else if (((IncomingGroupMessage)message).isQuit())   type |= Types.GROUP_QUIT_BIT;
  }
  else if (message.isEndSession()) {
    type |= Types.SECURE_MESSAGE_BIT;
    type |= Types.END_SESSION_BIT;
  }

  if (message.isPush()) type |= Types.PUSH_MESSAGE_BIT;

  Recipients recipients;

  if (message.getSender() != null) {
    recipients = RecipientFactory.getRecipientsFromString(context, message.getSender(), true);
  }
  else {
    Log.w(TAG, "Sender is null, returning unknown recipient");
    recipients = RecipientFactory.getRecipientsFor(context, Recipient.getUnknownRecipient(), false);
  }

  Recipients groupRecipients;

  if (message.getGroupId() == null) {
    groupRecipients = null;
  }
  else {
    groupRecipients = RecipientFactory.getRecipientsFromString(context, message.getGroupId(), true);
  }

  boolean    unread = org.thoughtcrime.securesms.util.Util.isDefaultSmsProvider(context) ||
    message.isSecureMessage() || message.isPreKeyBundle();

  long       threadId;

  if (groupRecipients == null) threadId = DatabaseFactory.getThreadDatabase(context).getThreadIdFor(recipients);
  else                         threadId = DatabaseFactory.getThreadDatabase(context).getThreadIdFor(groupRecipients);

  ContentValues values = new ContentValues(6);
  values.put(ADDRESS, message.getSender());
  values.put(ADDRESS_DEVICE_ID, message.getSenderDeviceId());
  values.put(DATE_RECEIVED, System.currentTimeMillis());
  values.put(DATE_SENT, message.getSentTimestampMillis());
  values.put(PROTOCOL, message.getProtocol());
  values.put(READ, unread ? 0 : 1);

  if (!TextUtils.isEmpty(message.getPseudoSubject()))
    values.put(SUBJECT, message.getPseudoSubject());

  values.put(REPLY_PATH_PRESENT, message.isReplyPathPresent());
  values.put(SERVICE_CENTER, message.getServiceCenterAddress());
  values.put(BODY, message.getMessageBody());
  values.put(TYPE, type);
  values.put(THREAD_ID, threadId);

  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  long messageId = db.insert(TABLE_NAME, null, values);

  if (unread) {
    DatabaseFactory.getThreadDatabase(context).setUnread(threadId);
  }

  DatabaseFactory.getThreadDatabase(context).update(threadId);
  notifyConversationListeners(threadId);
  jobManager.add(new TrimThreadJob(context, threadId));

  return new Pair<>(messageId, threadId);
}
/* TODO Pair<Long, Long>*/void* SmsDatabase::InsertMessageInbox(IncomingTextMessage* message)
{
  return InsertMessageInbox(message, Types::BASE_INBOX_TYPE);
}
long SmsDatabase::InsertMessageOutbox(long threadId, OutgoingTextMessage* message, long type, bool forceSms, long date)
{
  if (message.isKeyExchange())   type |= Types.KEY_EXCHANGE_BIT;
  else if (message.isSecureMessage()) type |= Types.SECURE_MESSAGE_BIT;
  else if (message.isEndSession())    type |= Types.END_SESSION_BIT;
  if (forceSms)                  type |= Types.MESSAGE_FORCE_SMS_BIT;

  ContentValues contentValues = new ContentValues(6);
  contentValues.put(ADDRESS, PhoneNumberUtils.formatNumber(message.getRecipients().getPrimaryRecipient().getNumber()));
  contentValues.put(THREAD_ID, threadId);
  contentValues.put(BODY, message.getMessageBody());
  contentValues.put(DATE_RECEIVED, date);
  contentValues.put(DATE_SENT, date);
  contentValues.put(READ, 1);
  contentValues.put(TYPE, type);

  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  long           messageId = db.insert(TABLE_NAME, ADDRESS, contentValues);

  DatabaseFactory.getThreadDatabase(context).update(threadId);
  notifyConversationListeners(threadId);
  jobManager.add(new TrimThreadJob(context, threadId));

  return messageId;
}
OsIndependentCursor* SmsDatabase::GetMessages(int skip, int limit)
{
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  return db.query(TABLE_NAME, MESSAGE_PROJECTION, null, null, null, null, ID, skip + "," + limit);
}

OsIndependentCursor* SmsDatabase::GetOutgoingMessages()
{
  String outgoingSelection = TYPE + " & " + Types.BASE_TYPE_MASK + " = " + Types.BASE_OUTBOX_TYPE;
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  return db.query(TABLE_NAME, MESSAGE_PROJECTION, outgoingSelection, null, null, null, null);
}

OsIndependentCursor* SmsDatabase::GetDecryptInProgressMessages()
{
  String where = TYPE + " & " + (Types.ENCRYPTION_ASYMMETRIC_BIT) + " != 0";
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  return db.query(TABLE_NAME, MESSAGE_PROJECTION, where, null, null, null, null);
}

OsIndependentCursor* SmsDatabase::GetEncryptedRogueMessages(Recipient* recipient)
{
  String selection = TYPE + " & " + Types.ENCRYPTION_REMOTE_NO_SESSION_BIT + " != 0" +
    " AND PHONE_NUMBERS_EQUAL(" + ADDRESS + ", ?)";
  String[] args = { recipient.getNumber() };
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  return db.query(TABLE_NAME, MESSAGE_PROJECTION, selection, args, null, null, null);
}

OsIndependentCursor* SmsDatabase::GetMessage(long messageId)
{
  SQLiteDatabase db = databaseHelper.getReadableDatabase();
  Cursor         cursor = db.query(TABLE_NAME, MESSAGE_PROJECTION, ID_WHERE, new String[]{messageId + ""},
    null, null, null);
  setNotifyConverationListeners(cursor, getThreadIdForMessage(messageId));
  return cursor;
}
bool SmsDatabase::DeleteMessage(long messageId)
{
  Log.w("MessageDatabase", "Deleting: " + messageId);
  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  long threadId = getThreadIdForMessage(messageId);
  db.delete(TABLE_NAME, ID_WHERE, new String[] {messageId + ""});
  boolean threadDeleted = DatabaseFactory.getThreadDatabase(context).update(threadId);
  notifyConversationListeners(threadId);
  return threadDeleted;
}

/*package */void SmsDatabase::DeleteThread(long threadId)
{
  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  db.delete(TABLE_NAME, THREAD_ID + " = ?", new String[] {threadId + ""});
}

/*package*/void SmsDatabase::DeleteMessagesInThreadBeforeDate(long threadId, long date)
{
  SQLiteDatabase db = databaseHelper.getWritableDatabase();
  String where = THREAD_ID + " = ? AND (CASE " + TYPE;

  for (long outgoingType : Types.OUTGOING_MESSAGE_TYPES) {
    where += " WHEN " + outgoingType + " THEN " + DATE_SENT + " < " + date;
  }

  where += (" ELSE " + DATE_RECEIVED + " < " + date + " END)");

  db.delete(TABLE_NAME, where, new String[] {threadId + ""});
}
/*package*/ void SmsDatabase::DeleteThreads(/* TODO Set<Long>*/ void* threadIds)
{
  OsIndependentSQLiteDatabase* db = databaseHelper->GetWritableDatabase();
  String where = "";

  for (long threadId : threadIds) {
    where += THREAD_ID + " = '" + threadId + "' OR ";
  }

  where = where.substring(0, where.length() - 4);

  db->Delete(TABLE_NAME, where, null);
}
/*package */ void SmsDatabase::DeleteAllThreads()
{
  OsIndependentSQLiteDatabase* db = databaseHelper->GetWritableDatabase();
  db->Delete(TABLE_NAME, null, null);
}

/*package*/ OsIndependentSQLiteDatabase* SmsDatabase::BeginTransaction()
{
  OsIndependentSQLiteDatabase* database = databaseHelper->GetWritableDatabase();
  database->BeginTransaction();
  return database;
}

/*package*/ void SmsDatabase::EndTransaction(OsIndependentSQLiteDatabase* database)
{
  database->SetTransactionSuccessful();
  database->EndTransaction();
}
/*package*/ OsIndependentSQLiteStatement* SmsDatabase::CreateInsertStatement(OsIndependentSQLiteDatabase* database)
{
  return database->compileStatement("INSERT INTO " + TABLE_NAME + " (" + ADDRESS + ", " +
    PERSON + ", " +
    DATE_SENT + ", " +
    DATE_RECEIVED + ", " +
    PROTOCOL + ", " +
    READ + ", " +
    STATUS + ", " +
    TYPE + ", " +
    REPLY_PATH_PRESENT + ", " +
    SUBJECT + ", " +
    BODY + ", " +
    SERVICE_CENTER +
    ", " + THREAD_ID + ") " +
    " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
}
