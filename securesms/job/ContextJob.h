#pragma once
/*
Port of class ContextJob from TextSecure-android
*/

// [ ] done
// TFS ID: 523

#include "..\..\osindependent\OsIndependentContext.h"

//import org.whispersystems.jobqueue.Job;
//import org.whispersystems.jobqueue.JobParameters;
//import org.whispersystems.jobqueue.dependencies.ContextDependent;

class ContextJob : public Job, public ContextDependent
{
protected:
  /*transient*/ OsIndependentContext* context;

protected:
  ContextJob(OsIndependentContext* context, JobParameters* parameters)
  {
    super(parameters);
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
