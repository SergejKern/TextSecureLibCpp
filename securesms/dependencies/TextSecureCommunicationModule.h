#pragma once
/*
Port of class TextSecureCommunicationModule from TextSecure-android
*/

// [ ] done
// TFS ID: 493

#include "..\..\osindependent\OsIndependentContext.h"

//import org.thoughtcrime.securesms.BuildConfig;
//import org.thoughtcrime.securesms.DeviceListActivity;
//import org.thoughtcrime.securesms.crypto.storage.TextSecureAxolotlStore;
//import org.thoughtcrime.securesms.jobs.AttachmentDownloadJob;
//import org.thoughtcrime.securesms.jobs.CleanPreKeysJob;
//import org.thoughtcrime.securesms.jobs.CreateSignedPreKeyJob;
//import org.thoughtcrime.securesms.jobs.DeliveryReceiptJob;
//import org.thoughtcrime.securesms.jobs.MultiDeviceContactUpdateJob;
//import org.thoughtcrime.securesms.jobs.MultiDeviceGroupUpdateJob;
//import org.thoughtcrime.securesms.jobs.PushGroupSendJob;
//import org.thoughtcrime.securesms.jobs.PushMediaSendJob;
//import org.thoughtcrime.securesms.jobs.PushNotificationReceiveJob;
//import org.thoughtcrime.securesms.jobs.PushTextSendJob;
//import org.thoughtcrime.securesms.jobs.RefreshPreKeysJob;
//import org.thoughtcrime.securesms.push.SecurityEventListener;
//import org.thoughtcrime.securesms.push.TextSecurePushTrustStore;
//import org.thoughtcrime.securesms.service.MessageRetrievalService;
#include "..\util\TextSecurePreferences.h"
//import org.whispersystems.libaxolotl.util.guava.Optional;
//import org.whispersystems.textsecure.api.TextSecureAccountManager;
//import org.whispersystems.textsecure.api.TextSecureMessageReceiver;
//import org.whispersystems.textsecure.api.TextSecureMessageSender;
#include "..\..\lib\api\TextSecureAccountManager.h"
#include "..\..\lib\api\TextSecureMessageReceiver.h"
#include "..\..\lib\api\TextSecureMessageSender.h"
#include "..\..\lib\api\util\CredentialsProvider.h"

//import dagger.Module;
//import dagger.Provides;

//@Module(complete = false, injects = {CleanPreKeysJob.class,
//                                     CreateSignedPreKeyJob.class,
//                                     DeliveryReceiptJob.class,
//                                     PushGroupSendJob.class,
//                                     PushTextSendJob.class,
//                                     PushMediaSendJob.class,
//                                     AttachmentDownloadJob.class,
//                                     RefreshPreKeysJob.class,
//                                     MessageRetrievalService.class,
//                                     PushNotificationReceiveJob.class,
//                                     MultiDeviceContactUpdateJob.class,
//                                     MultiDeviceGroupUpdateJob.class,
//                                     DeviceListActivity.DeviceListFragment.class})
class TextSecureCommunicationModule
{
private:
  OsIndependentContext* context;

public:
  TextSecureCommunicationModule(OsIndependentContext* context)
  {
    this->context = context;
  }
  //public static interface TextSecureMessageSenderFactory
  class TextSecureMessageSenderFactory
  {
  public:
    virtual TextSecureMessageSender* Create() = 0;
  };

private:
  class DynamicCredentialsProvider : CredentialsProvider
  {
  private:
    OsIndependentContext* context;
    DynamicCredentialsProvider(OsIndependentContext* context)
    {
      this->context = context->GetApplicationContext();
    }
  public:
    //@Override
    virtual OsIndependentString* GetUser()
    {
      return TextSecurePreferences::GetLocalNumber(context);
    }

    //@Override
    virtual OsIndependentString* GetPassword()
    {
      return TextSecurePreferences::GetPushServerPassword(context);
    }

    //@Override
    virtual OsIndependentString* GetSignalingKey()
    {
      return TextSecurePreferences::GetSignalingKey(context);
    }
  };
  //@Provides
  TextSecureAccountManager* ProvideTextSecureAccountManager()
  {
    return new TextSecureAccountManager(BuildConfig.PUSH_URL,
      new TextSecurePushTrustStore(context),
      TextSecurePreferences::GetLocalNumber(context),
      TextSecurePreferences::GetPushServerPassword(context));
  }
  //@Provides
  TextSecureMessageSenderFactory* ProvideTextSecureMessageSenderFactory()
  {
    // TODO deanonymize anonym function
    //return new TextSecureMessageSenderFactory(){
    //  @Override
    //  public TextSecureMessageSender create() {
    //    return new TextSecureMessageSender(BuildConfig.PUSH_URL,
    //      new TextSecurePushTrustStore(context),
    //      TextSecurePreferences.getLocalNumber(context),
    //      TextSecurePreferences.getPushServerPassword(context),
    //      new TextSecureAxolotlStore(context),
    //      Optional.<TextSecureMessageSender.EventListener>of(new SecurityEventListener(context)));
    //  }
    //};
  }

  //@Provides
  TextSecureMessageReceiver* ProvideTextSecureMessageReceiver()
  {
    return new TextSecureMessageReceiver(BuildConfig.PUSH_URL,
      new TextSecurePushTrustStore(context),
      new DynamicCredentialsProvider(context));
  }
};
