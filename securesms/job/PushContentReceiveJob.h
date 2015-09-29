#pragma once
/*
Port of class PushContentReceiveJob from TextSecure-android
*/

// [ ] done
// TFS ID: 536

#include "PushReceivedJob.h"

#include "..\..\osindependent\OsIndependentContext.h"
//import android.util.Log;
//
//import org.thoughtcrime.securesms.ApplicationContext;
//import org.thoughtcrime.securesms.database.DatabaseFactory;
#include "..\util\TextSecurePreferences.h"
//import org.whispersystems.jobqueue.JobManager;
//import org.whispersystems.jobqueue.JobParameters;
//import org.whispersystems.libaxolotl.InvalidVersionException;
//import org.whispersystems.textsecure.api.messages.TextSecureEnvelope;
//import org.thoughtcrime.securesms.database.TextSecureDirectory;
//import org.thoughtcrime.securesms.database.NotInDirectoryException;
//import org.whispersystems.textsecure.api.push.ContactTokenDetails;
//
#include "..\..\javastuff\IOException.h"

class PushContentReceiveJob : PushReceivedJob
{
private:
  static const OsIndependentString* TAG;
  const OsIndependentString* data;
public:
  PushContentReceiveJob(OsIndependentContext* context);
  PushContentReceiveJob(OsIndependentContext* context, OsIndependentString* data);
  //@Override
  void onAdded() {}
  //@Override
  void onRun();
  //@Override
  void onCanceled() { }
  //@Override
  bool OnShouldRetry(Exception exception) { return false; }
};

const OsIndependentString* PushContentReceiveJob::TAG = new OsIndependentString("PushContentReceiveJob");
