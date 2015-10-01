#pragma once
/*
Port of class JobParameters from jobmanager-android
*/

// [x] done
// TFS ID: 761


#include "..\..\javastuff\Serializable.h"
#include "..\..\owntemplates\List.h"
#include "..\..\javastuff\TimeUnit.h"
#include "EncryptionKeys.h"
#include "requirements\Requirement.h"
#include "..\..\osindependent\OsIndependentString.h"

/**
 * The set of parameters that describe a {@link org.whispersystems.jobqueue.Job}.
 */
class JobParameters : public Serializable
{
public:
  class Builder
  {
  private:
    List<Requirement*>* requirements = new LinkedList<Requirement*>();
    bool isPersistent = false;
    EncryptionKeys* encryptionKeys = nullptr;
    int retryCount = 100;
    OsIndependentString* groupId = nullptr;
    bool wakeLock = false;
    long wakeLockTimeout = 0;
    /**
    * Specify a {@link org.whispersystems.jobqueue.requirements.Requirement }that must be met
    * before the Job is executed.  May be called multiple times to register multiple requirements.
    * @param requirement The Requirement that must be met.
    * @return the builder.
    */
  public:
    Builder* WithRequirement(Requirement* requirement)
    {
      this->requirements->Add(requirement);
      return this;
    }
    /**
    * Specify that the Job should be durably persisted to disk, so that it remains in the queue
    * across application restarts.
    * @return The builder.
    */
    Builder* WithPersistence()
    {
      this->isPersistent = true;
      return this;
    }
    /**
    * Specify that the job should use encryption when durably persisted to disk.
    * @param encryptionKeys The keys to encrypt the serialized job with before persisting.
    * @return the builder.
    */
    Builder* WithEncryption(EncryptionKeys* encryptionKeys)
    {
      this->encryptionKeys = encryptionKeys;
      return this;
    }
    /**
    * Specify how many times the job should be retried if execution fails but onShouldRetry() returns
    * true.
    *
    * @param retryCount The number of times the job should be retried.
    * @return the builder.
    */
    Builder* WithRetryCount(int retryCount)
    {
      this->retryCount = retryCount;
      return this;
    }
    /**
    * Specify a groupId the job should belong to.  Jobs with the same groupId are guaranteed to be
    * executed serially.
    *
    * @param groupId The job's groupId.
    * @return the builder.
    */
    Builder* WithGroupId(OsIndependentString* groupId)
    {
      this->groupId = groupId;
      return this;
    }
    /**
    * Specify whether this job should hold a wake lock.
    *
    * @param needsWakeLock If set, this job will acquire a wakelock on add(), and hold it until
    *                      run() completes, or cancel().
    * @param timeout       Specify a timeout for the wakelock.  A timeout of
    *                      0 will result in no timeout.
    *
    * @return the builder.
    */
    Builder* WithWakeLock(bool needsWakeLock, long timeout, TimeUnit::MILLISECONDS* unit)//TimeUnit* unit)
    {
      this->wakeLock = needsWakeLock;
      // TimeUnit::MILLISECONDS::ToMillis does nothing.
      this->wakeLockTimeout = timeout; //  unit->ToMillis(timeout);
      return this;
    }
    /**
    * Specify whether this job should hold a wake lock.
    *
    * @return the builder.
    */
    Builder* WithWakeLock(bool needsWakeLock)
    {
      return WithWakeLock(needsWakeLock, 0, nullptr); // new TimeUnit::MILLISECONDS());
    }
    /**
    * @return the JobParameters instance that describes a Job.
    */
    JobParameters* Create()
    {
      return new JobParameters(requirements, isPersistent, groupId, encryptionKeys, retryCount, wakeLock, wakeLockTimeout);
    }
  };
private:
  /*transient*/ EncryptionKeys* encryptionKeys;
  List<Requirement*>* requirements;
  const bool isPersistent;
  const int retryCount;
  const OsIndependentString* groupId;
  const bool wakeLock;
  const long wakeLockTimeout;

  JobParameters(List<Requirement*>* requirements,
    bool isPersistent, OsIndependentString* groupId,
    EncryptionKeys* encryptionKeys,
    int retryCount, bool wakeLock,
    long wakeLockTimeout)
    : isPersistent(isPersistent), retryCount(retryCount),
    wakeLock(wakeLock), wakeLockTimeout(wakeLockTimeout)
  {
    this->requirements = requirements;
    this->groupId = groupId;
    this->encryptionKeys = encryptionKeys;
  }
public:
  List<Requirement*>* GetRequirements() { return this->requirements; }
  bool IsPersistent() { return this->isPersistent; }
  EncryptionKeys* GetEncryptionKeys() { return this->encryptionKeys; }
  void SetEncryptionKeys(EncryptionKeys* encryptionKeys) { this->encryptionKeys = encryptionKeys; }
  int GetRetryCount() { return this->retryCount; }
  /**
   * @return a builder used to construct JobParameters.
   */
  static Builder* NewBuilder() { return new Builder(); }
  const OsIndependentString* GetGroupId() { return this->groupId; }
  bool NeedsWakeLock() { return this->wakeLock; }
  long GetWakeLockTimeout() { return this->wakeLockTimeout; }
};
