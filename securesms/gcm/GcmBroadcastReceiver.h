#pragma once
/*
Port of class GcmBroadcastReceiver from TextSecure-android
*/

// [ ] done
// TFS ID: 518

#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentIntent.h"
//import android.support.v4.content.WakefulBroadcastReceiver;
//import android.text.TextUtils;
//import android.util.Log;
//
//import com.google.android.gms.gcm.GoogleCloudMessaging;
//
//import org.thoughtcrime.securesms.ApplicationContext;
#include "..\jobs\PushContentReceiveJob.h"
#include "..\jobs\PushNotificationReceiveJob.h"
#include "..\util\TextSecurePreferences.h"

class GcmBroadcastReceiver : WakefulBroadcastReceiver
{
private:
  static const OsIndependentString* TAG;
public:
  //@Override
  void OnReceive(OsIndependentContext* context, OsIndependentIntent* intent);
private:
  void HandleReceivedMessage(OsIndependentContext* context, OsIndependentString* data);
  void HandleReceivedNotification(OsIndependentContext* context);
};

const OsIndependentString* GcmBroadcastReceiver::TAG = new OsIndependentString("GcmBroadcastReceiver");
