#include "GcmBroadcastReceiver.h"

void GcmBroadcastReceiver::OnReceive(OsIndependentContext* context, OsIndependentIntent* intent)
{
  // TODO: Use Google Cloud Messaging????
  GoogleCloudMessaging gcm = GoogleCloudMessaging.getInstance(context);
  OsIndependentString* messageType = gcm.getMessageType(intent);

  if (GoogleCloudMessaging.MESSAGE_TYPE_MESSAGE.equals(messageType))
  {
    //Log.w(TAG, "GCM message...");

    if (!TextSecurePreferences::IsPushRegistered(context))
    {
      //Log.w(TAG, "Not push registered!");
      return;
    }

    OsIndependentString* messageData = intent->GetStringExtra(new OsIndependentString("message"));
    OsIndependentString* receiptData = intent->GetStringExtra(new OsIndependentString("receipt"));

    if (!TextUtils.isEmpty(messageData)) 
      HandleReceivedMessage(context, messageData);
    else if (!TextUtils.isEmpty(receiptData)) 
      HandleReceivedMessage(context, receiptData);
    else if (intent->HasExtra("notification")) 
      HandleReceivedNotification(context);
  }
}
void GcmBroadcastReceiver::HandleReceivedMessage(OsIndependentContext* context, OsIndependentString* data)
{
  ApplicationContext::GetInstance(context)
    ->GetJobManager()
    ->Add(new PushContentReceiveJob(context, data));
}
void GcmBroadcastReceiver::HandleReceivedNotification(OsIndependentContext* context)
{
  ApplicationContext::GetInstance(context)
    ->GetJobManager()
    ->Add(new PushNotificationReceiveJob(context));
}
