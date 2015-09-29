#pragma once
/*
Port of class PushNotificationReceiveJob from TextSecure-android
*/

// [ ] done
// TFS ID: 540

#include "PushReceivedJob.h"

#include "..\..\osindependent\OsIndependentContext.h"
//import android.util.Log;

#include "..\dependencies\InjectableType.h"
//import org.whispersystems.jobqueue.JobParameters;
//import org.whispersystems.jobqueue.requirements.NetworkRequirement;
#include "..\..\lib\api\TextSecureMessageReceiver.h"
#include "..\..\lib\api\messages\TextSecureEnvelope.h"
#include "..\..\lib\api\push\exceptions\PushNetworkException.h"

//import java.io.IOException;
//import java.util.concurrent.TimeUnit;

//import javax.inject.Inject;

class PushNotificationReceiveJob : public PushReceivedJob, public InjectableType
{
private:
  static const OsIndependentString* TAG;

  /*@Inject transient */
  TextSecureMessageReceiver* receiver;
public:
  PushNotificationReceiveJob(OsIndependentContext* context);
  //@Override
  void OnAdded() {}
  //@Override
  void OnRun() /*throws IOException*/;
  //@Override
  bool OnShouldRetry(Exception* e);
  //@Override
  void OnCanceled();
};
const OsIndependentString* PushNotificationReceiveJob::TAG = new OsIndependentString("PushNotificationReceiveJob");
