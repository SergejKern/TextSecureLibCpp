#pragma once
/*
Port of class DirectoryRefreshJob from TextSecure-android
*/

// [ ] done
// TFS ID: 526

//import android.content.Context;
//import android.os.PowerManager;
//
//import org.thoughtcrime.securesms.crypto.SecurityEvent;
//import org.thoughtcrime.securesms.util.DirectoryHelper;
//import org.whispersystems.jobqueue.JobParameters;
#include "..\..\otherproject\jobmanager\requirements\NetworkRequirement.h"
//import org.whispersystems.textsecure.api.push.exceptions.PushNetworkException;
//
//import java.io.IOException;

#include "ContextJob.h"

class DirectoryRefreshJob : public ContextJob
{
public:
  DirectoryRefreshJob(OsIndependentContext* context)
    : ContextJob(context, JobParameters::NewBuilder()
    ->WithGroupId(new OsIndependentString("DirectoryRefreshJob"))
    ->WithRequirement(new NetworkRequirement(context))
    ->Create())
  { }

  //@Override Job
  virtual void OnAdded() override { }
  //@Override Job
  virtual void OnRun() /*throws IOException*/ override
  {
    OsIndependentPowerManager* powerManager = (OsIndependentPowerManager*)context->GetSystemService((OsIndependentString*)OsIndependentContext::POWER_SERVICE);
    OsIndependentPowerManager::WakeLock* wakeLock = powerManager->NewWakeLock(OsIndependentPowerManager::PARTIAL_WAKE_LOCK, new OsIndependentString("Directory Refresh"));
    try
    {
      wakeLock->Acquire();
      DirectoryHelper::RefreshDirectory(context);
      SecurityEvent::BroadcastSecurityUpdateEvent(context);
    }
    finally
    {
      if (wakeLock->IsHeld()) 
        wakeLock->Release();
    }
  }

  //@Override Job
  virtual bool OnShouldRetry(Exception* exception) override
  {
    if (exception instanceof PushNetworkException) 
      return true;
    return false;
  }

  //@Override Job
  virtual void OnCanceled() override {}
};
