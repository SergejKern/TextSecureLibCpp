#pragma once
/*
Port of class MasterSecretRequirement from TextSecure-android
*/

// [ ] done
// TFS ID: 551

#include "..\..\..\osindependent\OsIndependentContext.h"
//
//import org.thoughtcrime.securesms.service.KeyCachingService;
//import org.whispersystems.jobqueue.dependencies.ContextDependent;
//import org.whispersystems.jobqueue.requirements.Requirement;

class MasterSecretRequirement : Requirement, ContextDependent
{
private:
  /*TODO transient*/ OsIndependentContext* context;
public:
  MasterSecretRequirement(OsIndependentContext* context)
  {
    this->context = context;
  }
  //@Override
  bool IsPresent()
  {
    return KeyCachingService::GetMasterSecret(context) != nullptr;
  }
  //@Override
  void SetContext(OsIndependentContext* context)
  {
    this->context = context;
  }
};
