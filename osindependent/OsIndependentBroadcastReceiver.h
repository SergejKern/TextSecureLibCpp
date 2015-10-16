#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.BroadcastReceiver
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/BroadcastReceiver.java#BroadcastReceiver
*/

// [ ] done
// TFS ID: 797

#include "OsIndependentContext.h"
#include "OsIndependentIntent.h"

/*
public abstract class  [More ...] BroadcastReceiver {
*/
class OsIndependentBroadcastReceiver
{
public:
public:
  // public abstract void[More ...] onReceive(Context context, Intent intent);
  virtual void OnReceive(OsIndependentContext* context, OsIndependentIntent* intent) = 0;
};

/*
needs no Factory, because is abstract
*/
