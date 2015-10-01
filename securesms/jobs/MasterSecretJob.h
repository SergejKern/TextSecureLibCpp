#pragma once
/*
Port of class PartProgressEvent from TextSecure-android
*/

// [x] done
// TFS ID: 535

#include "ContextJob.h"

#include "..\crypto\MasterSecret.h";
#include "..\service\KeyCachingService.h";

class MasterSecretJob : public ContextJob
{
protected:
  class RequirementNotMetException : public Exception {};
public:
  MasterSecretJob(OsIndependentContext* context, JobParameters* parameters)
    : ContextJob(context, parameters)
  { }
  //@Override
  virtual void OnRun() /*throws Exception*/
  {
    MasterSecret* masterSecret = GetMasterSecret();
    OnRun(masterSecret);
  }
  //@Override
  virtual bool OnShouldRetry(Exception* exception)
  {
    /*
    TODO REFACTOR
    Every time you need to use a dynamic_cast (or instanceof) 
    you'd better ask yourself whether it's a necessary thing. 
    It's generally a sign of poor design. 

    introduce something like a visitor ???
    */
    if (Exception* v = dynamic_cast<RequirementNotMetException*>(exception))
      return true;
    return OnShouldRetryThrowable(exception);
  }

  virtual void OnRun(MasterSecret* masterSecret) = 0 /*throws Exception*/;
  virtual bool OnShouldRetryThrowable(Exception* exception) = 0;

private:
  MasterSecret* GetMasterSecret() /*throws RequirementNotMetException*/
  {
    MasterSecret* masterSecret = KeyCachingService::GetMasterSecret(context);

    if (masterSecret == nullptr)
      throw new RequirementNotMetException();
    else
      return masterSecret;
  }
};
