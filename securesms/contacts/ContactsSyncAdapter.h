#pragma once
/*
Port of class ContactsSyncAdapter from TextSecure-android
*/

// [x] done
// TFS ID: 428

#include "..\..\osindependent\OsIndependentAbstractThreadedSyncAdapter.h"

#include "..\util\DirectoryHelper.h"

//import java.io.IOException;

class ContactsSyncAdapter : OsIndependentAbstractThreadedSyncAdapter
{
private:
  static const unsigned char* TAG;
public:
  ContactsSyncAdapter(OsIndependentContext* context, bool autoInitialize)
    : OsIndependentAbstractThreadedSyncAdapter(context, autoInitialize)
  { }

  //@Override
  void OnPerformSync(
    OsIndependentAccount* account,
    OsIndependentBundle* extras,
    unsigned char* authority,
    OsIndependentContentProviderClient* provider,
    OsIndependentSyncResult* syncResult)
  {
    try
    {
      DirectoryHelper::RefreshDirectory(GetContext());
    }
    catch (.../*IOException e*/)
    {
    }
  }
};
const unsigned char* ContactsSyncAdapter::TAG = "ContactsSyncAdapter";
