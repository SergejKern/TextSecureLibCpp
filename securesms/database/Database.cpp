#include "Database.h"

Database::~Database()
{
}
Database::Database(OsIndependentContext* context, OsIndependentSQLiteOpenHelper* databaseHelper)
{
  this->context = context;
  this->databaseHelper = databaseHelper;
}
void Database::Reset(OsIndependentSQLiteOpenHelper* databaseHelper)
{
  this->databaseHelper = databaseHelper;
}
void Database::NotifyConversationListeners(Set<long> threadIds)
{
  for (long threadId : threadIds)
    NotifyConversationListeners(threadId);
}
void Database::NotifyConversationListeners(long threadId)
{
  context->GetContentResolver()->NotifyChange(OsIndependentUri::Parse((unsigned char*)CONVERSATION_URI + threadId), nullptr);
}
void Database::NotifyConversationListListeners()
{
  context->GetContentResolver()->NotifyChange(OsIndependentUri::Parse((unsigned char*)CONVERSATION_LIST_URI), nullptr);
}
void Database::SetNotifyConverationListeners(OsIndependentCursor* cursor, long threadId)
{
  cursor->SetNotificationUri(context->GetContentResolver(), OsIndependentUri::Parse((unsigned char*)CONVERSATION_URI + threadId));
}
void Database::SetNotifyConverationListListeners(OsIndependentCursor* cursor)
{
  cursor->SetNotificationUri(context->GetContentResolver(), OsIndependentUri::Parse((unsigned char*)CONVERSATION_LIST_URI));
}
