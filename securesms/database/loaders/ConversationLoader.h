#pragma once
/*
Port of class ConversationLoader from TextSecure-android
*/

// [x] done
// TFS ID: 319

#include "..\..\..\osindependent\OsIndependentContext.h"
#include "..\..\..\osindependent\OsIndependentCursor.h"
#include "..\DatabaseFactory.h"
#include "..\..\util\AbstractCursorLoader.h"

class ConversationLoader : AbstractCursorLoader
{
private:
  const long threadId;
public:
  ConversationLoader(OsIndependentContext* context, long threadId)
    : AbstractCursorLoader(context), threadId(threadId)
  { }
  //@Override
  OsIndependentCursor* GetCursor()
  {
    return DatabaseFactory::GetMmsSmsDatabase(context)->GetConversation(threadId);
  }
};
