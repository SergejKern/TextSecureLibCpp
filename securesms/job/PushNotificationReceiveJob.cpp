#include "PushNotificationReceiveJob.h"

PushNotificationReceiveJob::PushNotificationReceiveJob(OsIndependentContext* context)
{
  super(context, JobParameters.newBuilder()
    .withRequirement(new NetworkRequirement(context))
    .withGroupId("__notification_received")
    .withWakeLock(true, 30, TimeUnit.SECONDS).create());
}


//@Override
void PushNotificationReceiveJob::OnRun() /*throws IOException*/ {
  receiver.retrieveMessages(new TextSecureMessageReceiver.MessageReceivedCallback() {
    @Override
      public void onMessage(TextSecureEnvelope envelope) {
      handle(envelope, false);
    }
  });
}

//@Override
bool PushNotificationReceiveJob::OnShouldRetry(Exception* e)
{
  //Log.w(TAG, e);
  return e instanceof PushNetworkException;
}

//@Override
void PushNotificationReceiveJob::OnCanceled()
{
  //Log.w(TAG, "***** Failed to download pending message!");
}
