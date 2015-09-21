#pragma once
/*
Port of class SmsDatabase from TextSecure-android
*/

// [ ] done
// TFS ID: 486

#include "MessagingDatabase.h"
#include "..\..\osindependent\OsIndependentCursor.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentSQLiteOpenHelper.h"
#include "..\..\osindependent\OsIndependentSQLiteStatement.h"
#include "..\..\otherproject\JobManager.h"
#include "model\SmsMessageRecord.h"
#include "..\sms\IncomingTextMessage.h"
#include "..\sms\OutgoingTextMessage.h"

class SmsDatabase :
  public MessagingDatabase
{
public:
  class Reader
  {
  private:
    OsIndependentCursor* cursor;
  protected:
    DisplayRecord::Body GetBody(OsIndependentCursor* cursor);
  public:
    Reader(OsIndependentCursor* cursor);
    SmsMessageRecord* GetNext();
    int GetCount();
    SmsMessageRecord* GetCurrent();
  private:
    Recipients* GetRecipientsFor(unsigned char* address);
    IdentityKeyMismatch* GetMismatches(unsigned char* document);
  public:
    void Close();
  };
  class Status
  {
  public:
    static const int STATUS_NONE = -1;
    static const int STATUS_COMPLETE = 0;
    static const int STATUS_PENDING = 0x20;
    static const int STATUS_FAILED = 0x40;
  };
public:
  virtual ~SmsDatabase();
  Reader* readerFor(OsIndependentCursor* cursor) { return new Reader(cursor); }

private:
  static const unsigned char* TAG;
  static const unsigned char* MESSAGE_PROJECTION[];
  JobManager* jobManager;
public:
  static const unsigned char* TABLE_NAME;
  static const unsigned char* PERSON;
  static const unsigned char* DATE_RECEIVED;
  static const unsigned char* DATE_SENT;
  static const unsigned char* PROTOCOL;
  static const unsigned char* STATUS;
  static const unsigned char* TYPE;
  static const unsigned char* REPLY_PATH_PRESENT;
  static const unsigned char* SUBJECT;
  static const unsigned char* SERVICE_CENTER;
  static const unsigned char* CREATE_TABLE;
  static const unsigned char* CREATE_INDEXS[];
  SmsDatabase(OsIndependentContext* context, OsIndependentSQLiteOpenHelper* databaseHelper);
protected:
  unsigned char* GetTableName() { return (unsigned char*)TABLE_NAME; }
private:
  void UpdateTypeBitmask(long id, long maskOff, long maskOn);
public:
  long GetThreadIdForMessage(long id);
  int GetMessageCount();
  int GetMessageCountForThread(long threadId);
  void MarkAsEndSession(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::KEY_EXCHANGE_MASK, MmsSmsColumns::Types::END_SESSION_BIT); }
  void MarkAsPreKeyBundle(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::KEY_EXCHANGE_MASK, MmsSmsColumns::Types::KEY_EXCHANGE_BIT | MmsSmsColumns::Types::KEY_EXCHANGE_BUNDLE_BIT); }
  void MarkAsInvalidVersionKeyExchange(long id) { UpdateTypeBitmask(id, 0, MmsSmsColumns::Types::KEY_EXCHANGE_INVALID_VERSION_BIT); }
  void MarkAsSecure(long id) { UpdateTypeBitmask(id, 0, MmsSmsColumns::Types::SECURE_MESSAGE_BIT); }
  void MarkAsInsecure(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::SECURE_MESSAGE_BIT, 0); }
  void MarkAsPush(long id) { UpdateTypeBitmask(id, 0, MmsSmsColumns::Types::PUSH_MESSAGE_BIT); }
  void MarkAsForcedSms(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::PUSH_MESSAGE_BIT, MmsSmsColumns::Types::MESSAGE_FORCE_SMS_BIT); }
  void MarkAsDecryptFailed(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::ENCRYPTION_MASK, MmsSmsColumns::Types::ENCRYPTION_REMOTE_FAILED_BIT); }
  void MarkAsDecryptDuplicate(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::ENCRYPTION_MASK, MmsSmsColumns::Types::ENCRYPTION_REMOTE_DUPLICATE_BIT); }
  void MarkAsNoSession(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::ENCRYPTION_MASK, MmsSmsColumns::Types::ENCRYPTION_REMOTE_NO_SESSION_BIT); }
  void MarkAsLegacyVersion(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::ENCRYPTION_MASK, MmsSmsColumns::Types::ENCRYPTION_REMOTE_LEGACY_BIT); }
  void MarkAsOutbox(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::BASE_TYPE_MASK, MmsSmsColumns::Types::BASE_OUTBOX_TYPE); }
  void MarkAsPendingInsecureSmsFallback(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::BASE_TYPE_MASK, MmsSmsColumns::Types::BASE_PENDING_INSECURE_SMS_FALLBACK); }
  void MarkAsSending(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::BASE_TYPE_MASK, MmsSmsColumns::Types::BASE_SENDING_TYPE); }
  void MarkAsSent(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::BASE_TYPE_MASK, MmsSmsColumns::Types::BASE_SENT_TYPE); }
  void MarkStatus(long id, int status);
  void MarkAsSentFailed(long id) { UpdateTypeBitmask(id, MmsSmsColumns::Types::BASE_TYPE_MASK, MmsSmsColumns::Types::BASE_SENT_FAILED_TYPE); }
  void IncrementDeliveryReceiptCount(unsigned char* address, long timestamp);
  void SetMessagesRead(long threadId);
  void SetAllMessagesRead();
  /* TODO Pair<Long, Long>*/void* UpdateMessageBodyAndType(long messageId, unsigned char* body, long maskOff, long maskOn);
  /* TODO Pair<Long, Long>*/void* CopyMessageInbox(long messageId);
  /* TODO Pair<Long, Long>*/void* InsertMessageInbox(IncomingTextMessage* message, long type);
  /* TODO Pair<Long, Long>*/void* InsertMessageInbox(IncomingTextMessage* message);
  long InsertMessageOutbox(long threadId, OutgoingTextMessage* message, long type, bool forceSms, long date);
  OsIndependentCursor* GetMessages(int skip, int limit);
  OsIndependentCursor* GetOutgoingMessages();
  OsIndependentCursor* GetDecryptInProgressMessages();
  OsIndependentCursor* GetEncryptedRogueMessages(Recipient* recipient);
  OsIndependentCursor* GetMessage(long messageId);
  bool DeleteMessage(long messageId);
  /*package */void DeleteThread(long threadId);
  /*package*/void DeleteMessagesInThreadBeforeDate(long threadId, long date);
  /*package*/ void DeleteThreads(/* TODO Set<Long>*/ void* threadIds);
  /*package */ void DeleteAllThreads();
  /*package*/ OsIndependentSQLiteDatabase* BeginTransaction();
  /*package*/ void EndTransaction(OsIndependentSQLiteDatabase* database);
  /*package*/ OsIndependentSQLiteStatement* CreateInsertStatement(OsIndependentSQLiteDatabase* database);
};

const unsigned char* SmsDatabase::TAG = "SmsDatabase";

const unsigned char* SmsDatabase::TABLE_NAME = "sms";
const unsigned char* SmsDatabase::PERSON = "person";
const unsigned char* SmsDatabase::DATE_RECEIVED = "date";
const unsigned char* SmsDatabase::DATE_SENT = "date_sent";
const unsigned char* SmsDatabase::PROTOCOL = "protocol";
const unsigned char* SmsDatabase::STATUS = "status";
const unsigned char* SmsDatabase::TYPE = "type";
const unsigned char* SmsDatabase::REPLY_PATH_PRESENT = "reply_path_present";
const unsigned char* SmsDatabase::SUBJECT = "subject";
const unsigned char* SmsDatabase::SERVICE_CENTER = "service_center";
const unsigned char* SmsDatabase::CREATE_TABLE = "CREATE TABLE sms (_id integer PRIMARY KEY, thread_id INTEGER, address TEXT, address_device_id INTEGER DEFAULT 1, person INTEGER, date INTEGER, date_sent INTEGER, protocol INTEGER, read INTEGER DEFAULT 0, status INTEGER DEFAULT -1,type INTEGER, reply_path_present INTEGER, delivery_receipt_count INTEGER DEFAULT 0,subject TEXT, body TEXT, mismatched_identities TEXT DEFAULT NULL, service_center TEXT);";
const unsigned char* SmsDatabase::CREATE_INDEXS[] = {
  "CREATE INDEX IF NOT EXISTS sms_thread_id_index ON sms (thread_id);",
  "CREATE INDEX IF NOT EXISTS sms_read_index ON sms (read);",
  "CREATE INDEX IF NOT EXISTS sms_read_and_thread_id_index ON sms(read,thread_id);",
  "CREATE INDEX IF NOT EXISTS sms_type_index ON sms (type);",
  "CREATE INDEX IF NOT EXISTS sms_date_sent_index ON sms (date_sent);",
  "CREATE INDEX IF NOT EXISTS sms_thread_date_index ON sms (thread_id, date);"
};
const unsigned char* SmsDatabase::MESSAGE_PROJECTION[] = 
{
  MmsSmsColumns::ID, MmsSmsColumns::THREAD_ID, 
  MmsSmsColumns::ADDRESS, MmsSmsColumns::ADDRESS_DEVICE_ID, PERSON, 
  "date AS date_received", "date_sent AS date_sent", PROTOCOL, 
  MmsSmsColumns::READ, STATUS, TYPE, REPLY_PATH_PRESENT, SUBJECT, 
  MmsSmsColumns::BODY, SERVICE_CENTER, MmsSmsColumns::RECEIPT_COUNT, 
  MmsSmsColumns::MISMATCHED_IDENTITIES
};
