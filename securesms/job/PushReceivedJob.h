#pragma once
/*
Port of class PushReceivedJob from TextSecure-android
*/

// [ ] done
// TFS ID: 541

#include "ContextJob.h"

#include "..\..\osindependent\OsIndependentContext.h"
//import android.util.Log;
//
//import org.thoughtcrime.securesms.ApplicationContext;
#include "..\database\DatabaseFactory.h"
#include "..\database\NotInDirectoryException.h"
#include "..\database\TextSecureDirectory.h"
//import org.thoughtcrime.securesms.recipients.RecipientFactory;
#include "..\recipients\Recipients.h"
//import org.whispersystems.jobqueue.JobManager;
//import org.whispersystems.jobqueue.JobParameters;
#include "..\..\lib\api\messages\TextSecureEnvelope.h"
#include "..\..\lib\api\push\ContactTokenDetails.h"

class PushReceivedJob : ContextJob
{
private:
  static const OsIndependentString* TAG;
protected:
  PushReceivedJob(OsIndependentContext* context, JobParameters* parameters);
public:
  void Handle(TextSecureEnvelope* envelope, bool sendExplicitReceipt);
private:
  void HandleMessage(TextSecureEnvelope* envelope, bool sendExplicitReceipt);
  void HandleReceipt(TextSecureEnvelope* envelope);
  bool IsActiveNumber(OsIndependentContext* context, OsIndependentString* e164number);
};

const OsIndependentString* PushReceivedJob::TAG = new OsIndependentString("PushReceivedJob");
