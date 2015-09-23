#pragma once
/*
Port of class BlockedContactsLoader from TextSecure-android
*/

// [x] done
// TFS ID: 317

#include "..\..\..\osindependent\OsIndependentContext.h"
#include "..\..\..\osindependent\OsIndependentCursor.h"

#include "..\DatabaseFactory.h"
#include "..\..\util\AbstractCursorLoader.h"

class BlockedContactsLoader : AbstractCursorLoader
{
public:
  BlockedContactsLoader(OsIndependentContext* context)
    : AbstractCursorLoader(context)
  { }

  //@Override
  OsIndependentCursor* GetCursor()
  {
    return DatabaseFactory::GetRecipientPreferenceDatabase(GetContext())->GetBlocked();
  }
};
