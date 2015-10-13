#pragma once
/*
Port of class NetworkRequirement from jobmanager-android
*/

// [x] done
// TFS ID: 767

#include "..\..\..\Factory\Factory.h"
#include "Requirement.h"
#include "..\dependencies\ContextDependent.h"

/**
 * A requirement that is satisfied when a network connection is present.
 */
class NetworkRequirement : public Requirement, public ContextDependent
{
private:
  /*transient */OsIndependentContext* context;

public:
  NetworkRequirement(OsIndependentContext* context)
  {
    this->context = context;
  }
  NetworkRequirement() {}
  //@Override Requirement
  virtual bool IsPresent() override
  {
    OsIndependentConnectivityManager* cm = (OsIndependentConnectivityManager*)context->GetSystemService((OsIndependentString*)OsIndependentContext::CONNECTIVITY_SERVICE);
    OsIndependentNetworkInfo* netInfo = cm->GetActiveNetworkInfo();
    return netInfo != nullptr && netInfo->IsConnected();
  }
  //@Override ContextDependent
  void SetContext(OsIndependentContext* context)
  {
    this->context = context;
  }
};
