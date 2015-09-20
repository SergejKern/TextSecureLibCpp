#pragma once
/*
Port of class Database from TextSecure-android
*/

// [ ] done
// TFS ID: 465

class Database
{
public:
  virtual ~Database();
protected:
  static const unsigned char* ID_WHERE;
  static const unsigned char* CONVERSATION_URI;
  static const unsigned char* CONVERSATION_LIST_URI;

  /* TODO OS SPECIFIC SQLiteOpenHelper*/ void* databaseHelper;
  /* TODO OS SPECIFIC Context*/ void* context;

public:
  Database(/*Context context*/ void*, /*SQLiteOpenHelper*/ void* databaseHelper);
  void Reset(/*SQLiteOpenHelper*/ void* databaseHelper);

protected:
  void NotifyConversationListeners(/*Set<Long> TODO */ long* threadIds);
  void NotifyConversationListeners(long threadId);
  void NotifyConversationListListeners();
  void SetNotifyConverationListeners(/* TODO OS SPECIFIC android.database.Cursor*/ void* cursor, long threadId);
  void SetNotifyConverationListListeners(/* TODO OS SPECIFIC android.database.Cursor*/ void* cursor);
};

const unsigned char* Database::ID_WHERE = "_id = ?";
const unsigned char* Database::CONVERSATION_URI = "content://textsecure/thread/";
const unsigned char* Database::CONVERSATION_LIST_URI = "content://textsecure/conversation-list";
