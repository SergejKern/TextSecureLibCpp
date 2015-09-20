#include "Database.h"

Database::~Database()
{
}
Database::Database(/*Context context*/ void*, /*SQLiteOpenHelper*/ void* databaseHelper)
{
  this->context = context;
  this->databaseHelper = databaseHelper;
}
void Database::Reset(/*SQLiteOpenHelper*/ void* databaseHelper)
{
  this->databaseHelper = databaseHelper;
}
void Database::NotifyConversationListeners(/*Set<Long> TODO */ long* threadIds)
{
  /* TODO for (long threadId : threadIds)
  NotifyConversationListeners(threadId); */
}
void Database::NotifyConversationListeners(long threadId)
{
  // TODO OS SPECIFIC context.getContentResolver().notifyChange(Uri.parse(CONVERSATION_URI + threadId), null);
}
void Database::NotifyConversationListListeners()
{
  // TODO OS SPECIFIC context.getContentResolver().notifyChange(Uri.parse(CONVERSATION_LIST_URI), null);
}
void Database::SetNotifyConverationListeners(/* TODO OS SPECIFIC android.database.Cursor*/ void* cursor, long threadId)
{
  // TODO OS SPECIFIC cursor.setNotificationUri(context.getContentResolver(), Uri.parse(CONVERSATION_URI + threadId));
}
void Database::SetNotifyConverationListListeners(/* TODO OS SPECIFIC android.database.Cursor*/ void* cursor)
{
  // TODO OS SPECIFIC cursor.setNotificationUri(context.getContentResolver(), Uri.parse(CONVERSATION_LIST_URI));
}
