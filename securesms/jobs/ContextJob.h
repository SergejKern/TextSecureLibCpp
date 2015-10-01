#pragma once
/*
Port of class ContextJob from TextSecure-android
*/

// [x] done
// TFS ID: 523

#include "..\..\osindependent\OsIndependentContext.h"

#include "..\..\otherproject\jobmanager\Job.h"
#include "..\..\otherproject\jobmanager\JobParameters.h"
#include "..\..\otherproject\jobmanager\dependencies\ContextDependent.h"

class ContextJob : public Job, public ContextDependent
{
private:
  typedef Job super;
protected:
  /*transient*/ OsIndependentContext* context;

protected:
  ContextJob(OsIndependentContext* context, JobParameters* parameters)
    : Job(parameters)
  {
    this->context = context;
  }
public:
  void SetContext(OsIndependentContext* context)
  {
    this->context = context;
  }
protected:
  OsIndependentContext* GetContext()
  {
    return this->context;
  }
};
