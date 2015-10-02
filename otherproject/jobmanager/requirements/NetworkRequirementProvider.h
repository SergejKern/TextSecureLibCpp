#pragma once
/*
Port of class NetworkRequirementProvider from jobmanager-android
*/

// [x] done
// TFS ID: 776

//import android.content.BroadcastReceiver;
//import android.content.Context;
//import android.content.Intent;
//import android.content.IntentFilter;
//import android.net.ConnectivityManager;

#include "RequirementProvider.h"
#include "NetworkRequirement.h"

class NetworkRequirementProvider : public RequirementProvider
{
private:
  RequirementListener* listener;
  NetworkRequirement* requirement;
public:
  NetworkRequirementProvider(OsIndependentContext* context)
  {
    this->requirement = new NetworkRequirement(context);
    // TODO -> deanonymize anonyme function
    //context->GetApplicationContext()->RegisterReceiver(new BroadcastReceiver()
    //{
    //  //@Override
    //  public void onReceive(Context context, Intent intent) {
    //    if (listener == null) {
    //      return;
    //    }

    //    if (requirement.isPresent()) {
    //      listener.onRequirementStatusChanged();
    //    }
    //  }
    //}, new IntentFilter(ConnectivityManager.CONNECTIVITY_ACTION));
  }

  //@Override
  virtual void SetListener(RequirementListener* listener) override
  {
    this->listener = listener;
  }
};
