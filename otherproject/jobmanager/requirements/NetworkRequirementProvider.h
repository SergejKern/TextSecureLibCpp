#pragma once
/*
Port of class NetworkRequirementProvider from jobmanager-android
*/

// [x] done
// TFS ID: 776

//import android.content.BroadcastReceiver;
#include "..\..\..\Factory\Factory.h"
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
  NetworkRequirementProvider(OsIndependentContext* context, OsIndependentBroadcastReceiver* broadcastReceiver, FactoryIntentFilter* intentFilterFactory)
  {
    this->requirement = new NetworkRequirement(context);
    // TODO -> deanonymize anonyme function
    // they instantiate a abstract class BroadcastReceiver and override it anonymously!!!!
    // pass instance of overriden BroadcastReceiver from outside
    context->GetApplicationContext()->RegisterReceiver(broadcastReceiver
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
    //}
    , intentFilterFactory->CreateNewIntentFilter((OsIndependentString*)OsIndependentConnectivityManager::CONNECTIVITY_ACTION));
  }

  //@Override
  virtual void SetListener(RequirementListener* listener) override
  {
    this->listener = listener;
  }
};
