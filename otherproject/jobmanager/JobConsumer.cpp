#include "JobConsumer.h"

JobConsumer::JobConsumer(OsIndependentString* name, JobQueue* jobQueue, PersistentStorage* persistentStorage)
{
  FactoryThread::GetInstance()->CreateNewThread(name);
  this->jobQueue = jobQueue;
  this->persistentStorage = persistentStorage;
}

//@Override
void JobConsumer::Run()
{
  while (true)
  {
    Job* job = jobQueue->GetNext();
    JobResult result = RunJob(job);

    if (result == JobResult::DEFERRED)
    {
      jobQueue->Push(job);
    }
    else
    {
      if (result == JobResult::FAILURE)
      {
        job->OnCanceled();
      }
      if (job->IsPersistent())
      {
        persistentStorage->Remove(job->GetPersistentId());
      }
      if (job->GetWakeLock() != nullptr && job->GetWakeLockTimeout() == 0)
      {
        job->GetWakeLock()->Release();
      }
    }
    if (job->GetGroupId() != nullptr)
    {
      jobQueue->SetGroupIdAvailable((OsIndependentString*)job->GetGroupId());
    }
  }
}

JobConsumer::JobResult JobConsumer::RunJob(Job* job)
{
  int retryCount = job->GetRetryCount();
  int runIteration = job->GetRunIteration();

  for (; runIteration < retryCount; runIteration++)
  {
    try
    {
      job->OnRun();
      return JobResult::SUCCESS;
    }
    catch (Exception* exception)
    {
      //Log.w(TAG, exception);
      /*
      TODO REFACTOR
      Every time you need to use a dynamic_cast (or instanceof)
      you'd better ask yourself whether it's a necessary thing.
      It's generally a sign of poor design.

      introduce something like a visitor ???
      */
      //if (exception instanceof RuntimeException)
      if (Exception* v = dynamic_cast<RuntimeException*>(exception))
      {
        throw (RuntimeException*)exception;
      }
      else if (!job->OnShouldRetry(exception))
      {
        return JobResult::FAILURE;
      }
      else if (!job->IsRequirementsMet())
      {
        job->SetRunIteration(runIteration + 1);
        return JobResult::DEFERRED;
      }
    }
  }
  return JobResult::FAILURE;
}
