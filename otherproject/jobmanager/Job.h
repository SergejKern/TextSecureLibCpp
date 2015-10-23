#pragma once
/*
Port of class Job from jobmanager-android
*/

// [x] done
// TFS ID: 760

#include "JobParameters.h"
//
#include "requirements\Requirement.h"
#include "..\..\javastuff\Serializable.h"
#include "..\..\owntemplates\List.h"
#include "..\..\Factory\Factory.h"
#include "EncryptionKeys.h"

/**
 * An abstract class representing a unit of work that can be scheduled with
 * the JobManager. This should be extended to implement tasks.
 */
class Job : public Serializable
{
private:
  JobParameters* parameters;

  /*transient*/ long persistentId;
  /*transient*/ int runIteration;
  /*transient*/ OsIndependentPowerManager::WakeLock* wakeLock;
public:
  Job(JobParameters* parameters)
  {
    this->parameters = parameters;
  }
  List<Requirement*>* GetRequirements()
  {
    return this->parameters->GetRequirements();
  }
  bool IsRequirementsMet()
  {
    auto reqList = parameters->GetRequirements();
    for (int i = 0; i < reqList->Size(); i++)
    {
      Requirement* requirement = reqList->Get(i);
      if (!requirement->IsPresent())
        return false;
    }
    return true;
  }
  const OsIndependentString* GetGroupId() { return parameters->GetGroupId(); }
  bool IsPersistent() { return parameters->IsPersistent(); }
  EncryptionKeys* GetEncryptionKeys() { return parameters->GetEncryptionKeys(); }
  void SetEncryptionKeys(EncryptionKeys* keys) { parameters->SetEncryptionKeys(keys); }
  int GetRetryCount() { return parameters->GetRetryCount(); }
  void SetPersistentId(long persistentId) { this->persistentId = persistentId; }
  long GetPersistentId() { return this->persistentId; }
  int GetRunIteration() { return this->runIteration; }
  void SetRunIteration(int runIteration) { this->runIteration = runIteration; }
  bool NeedsWakeLock() { return parameters->NeedsWakeLock(); }
  long GetWakeLockTimeout() { return parameters->GetWakeLockTimeout(); }
  void SetWakeLock(OsIndependentPowerManager::WakeLock* wakeLock) { this->wakeLock = wakeLock; }
  OsIndependentPowerManager::WakeLock* GetWakeLock() { return this->wakeLock; }
  /**
   * Called after a job has been added to the JobManager queue.  If it's a persistent job,
   * the state has been persisted to disk before this method is called.
   */
  virtual void OnAdded() = 0;
  /**
   * Called to actually execute the job.
   * @throws Exception
   */
  virtual void OnRun() = 0 /*throws Exception*/;
  /**
   * If onRun() throws an exception, this method will be called to determine whether the
   * job should be retried.
   *
   * @param exception The exception onRun() threw.
   * @return true if onRun() should be called again, false otherwise.
   */
  virtual bool OnShouldRetry(Exception* exception) = 0;
  /**
   * Called if a job fails to run (onShouldRetry returned false, or the number of retries exceeded
   * the job's configured retry count.
   */
  virtual void OnCanceled() = 0;

  virtual OsIndependentString* ToString() = 0;
};
