#pragma once
/*
Port of class Database from TextSecure-android
*/

// [x] done
// TFS ID: 465

#include "..\..\owntemplates\Set.h"
#include "..\..\osindependent\OsIndependentSQLiteOpenHelper.h"
#include "..\..\osindependent\OsIndependentCursor.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentUri.h"

class Database
{
public:
  virtual ~Database();
protected:
  static const unsigned char* ID_WHERE;
  static const unsigned char* CONVERSATION_URI;
  static const unsigned char* CONVERSATION_LIST_URI;

  OsIndependentSQLiteOpenHelper* databaseHelper;
  OsIndependentContext* context;

public:
  Database(OsIndependentContext*, OsIndependentSQLiteOpenHelper* databaseHelper);
  void Reset(OsIndependentSQLiteOpenHelper* databaseHelper);

protected:
  void NotifyConversationListeners(Set<long> threadIds);
  void NotifyConversationListeners(long threadId);
  void NotifyConversationListListeners();
  void SetNotifyConverationListeners(OsIndependentCursor* cursor, long threadId);
  void SetNotifyConverationListListeners(OsIndependentCursor* cursor);
};

const unsigned char* Database::ID_WHERE = (unsigned char*)"_id = ?";
const unsigned char* Database::CONVERSATION_URI = (unsigned char*)"content://textsecure/thread/";
const unsigned char* Database::CONVERSATION_LIST_URI = (unsigned char*)"content://textsecure/conversation-list";
