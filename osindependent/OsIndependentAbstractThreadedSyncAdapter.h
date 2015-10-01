#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.AbstractThreadedSyncAdapter
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/AbstractThreadedSyncAdapter.java#AbstractThreadedSyncAdapter
*/

// [ ] done
// TFS ID: 682

#include "OsIndependentContext.h"
#include "OsIndependentAccount.h"
#include "OsIndependentBundle.h"
#include "OsIndependentContentProviderClient.h"
#include "OsIndependentSyncResult.h"

/*
  public abstract class AbstractThreadedSyncAdapter
*/
class OsIndependentAbstractThreadedSyncAdapter
{
private:
  OsIndependentContext* mContext;
  const bool mAutoInitialize;
  bool mAllowParallelSyncs;
public:  
public:
  OsIndependentAbstractThreadedSyncAdapter(OsIndependentContext* context, bool autoInitialize)
    : mAutoInitialize(autoInitialize)
  {
    mAllowParallelSyncs = false;
    this->mContext = context;
  }
  OsIndependentContext* GetContext() { return this->mContext; }
  // public abstract void[More ...] onPerformSync(Account account, Bundle extras, String authority, ContentProviderClient provider, SyncResult syncResult);
  virtual void OnPerformSync(
    OsIndependentAccount* account, 
    OsIndependentBundle* extras, 
    unsigned char* authority, 
    OsIndependentContentProviderClient* provider, 
    OsIndependentSyncResult* syncResult) = 0;
};
