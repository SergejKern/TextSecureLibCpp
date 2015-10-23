#pragma once
/*
Port of class JobManager from jobmanager-android
*/

// [x] done
// TFS ID: 763

#include "..\..\Factory\Factory.h"

//import android.util.Log;

#include "dependencies\AggregateDependencyInjector.h"
#include "dependencies\DependencyInjector.h"
#include "persistence\JobSerializer.h"
#include "persistence\PersistentStorage.h"
#include "requirements\RequirementListener.h"
#include "requirements\RequirementProvider.h"

#include "..\..\javastuff\IOException.h"
#include "..\..\javastuff\Runnable.h"
#include "..\..\javastuff\Serializable.h"
#include "..\..\owntemplates\List.h"
#include "JobQueue.h"
#include "JobConsumer.h"
#include "..\..\osindependent\OsIndependentExecutors.h"

/**
 * A JobManager allows you to enqueue {@link org.whispersystems.jobqueue.Job} tasks
 * that are executed once a Job's {@link org.whispersystems.jobqueue.requirements.Requirement}s
 * are met.
 */
class JobManager : public RequirementListener
{
private:
  JobQueue* jobQueue = new JobQueue();
  Executor* eventExecutor = FactoryExecutors::GetInstance()->NewSingleThreadExecutor();
  AtomicBoolean* hasLoadedEncrypted = new AtomicBoolean(false);

  OsIndependentContext* context;
  PersistentStorage* persistentStorage;
  std::vector<RequirementProvider*>* requirementProviders;
  AggregateDependencyInjector* dependencyInjector;

private:
  class LoadTask : public Runnable
  {
  private:
    EncryptionKeys* keys;
    PersistentStorage* persistentStorage;
    JobQueue* jobQueue;
  public:
    LoadTask(EncryptionKeys* keys, PersistentStorage* persistentStorage, JobQueue* jobQueue);
    //@Override
    void Run() override;
  };
public:
  class Builder
  {
  private:
    OsIndependentContext* context;
    OsIndependentString* name;
    std::vector<RequirementProvider*>* requirementProviders;
    DependencyInjector* dependencyInjector;
    JobSerializer* jobSerializer;
    int consumerThreads;
  public:
    Builder(OsIndependentContext* context);
    /**
    * A name for the {@link org.whispersystems.jobqueue.JobManager}. This is a required parameter,
    * and is linked to the durable queue used by persistent jobs.
    *
    * @param name The name for the JobManager to build.
    * @return The builder.
    */
    Builder* WithName(OsIndependentString* name);

    // TODO
    ///**
    //* The {@link org.whispersystems.jobqueue.requirements.RequirementProvider}s to register with this
    //* JobManager.  Optional. Each {@link org.whispersystems.jobqueue.requirements.Requirement} an
    //* enqueued Job depends on should have a matching RequirementProvider registered here.
    //*
    //* @param requirementProviders The RequirementProviders
    //* @return The builder.
    //*/
    //Builder* WithRequirementProviders(RequirementProvider... requirementProviders)
    //{
    //  this->requirementProviders = Arrays.asList(requirementProviders);
    //  return this;
    //}
    /**
    * The {@link org.whispersystems.jobqueue.dependencies.DependencyInjector} to use for injecting
    * dependencies into {@link Job}s. Optional. Injection occurs just before a Job's onAdded() callback, or
    * after deserializing a persistent job.
    *
    * @param dependencyInjector The injector to use.
    * @return The builder.
    */
    Builder* WithDependencyInjector(DependencyInjector* dependencyInjector);
    /**
    * The {@link org.whispersystems.jobqueue.persistence.JobSerializer} to use for persistent Jobs.
    * Required if persistent Jobs are used.
    *
    * @param jobSerializer The serializer to use.
    * @return The builder.
    */
    Builder* WithJobSerializer(JobSerializer* jobSerializer);
    /**
    * Set the number of threads dedicated to consuming Jobs from the queue and executing them.
    *
    * @param consumerThreads The number of threads.
    * @return The builder.
    */
    Builder* WithConsumerThreads(int consumerThreads);
    /**
    * @return A constructed JobManager.
    */
    JobManager* Build();
  };
public:
  JobManager(OsIndependentContext* context, OsIndependentString* name,
    std::vector<RequirementProvider*>* requirementProviders,
    DependencyInjector* dependencyInjector,
    JobSerializer* jobSerializer, int consumers);
  /**
   * @param context An Android {@link android.content.Context}.
   * @return a {@link org.whispersystems.jobqueue.JobManager.Builder} used to construct a JobManager.
   */
  static Builder* NewBuilder(OsIndependentContext* context);
  void SetEncryptionKeys(EncryptionKeys* keys);
  /**
   * Queue a {@link org.whispersystems.jobqueue.Job} to be executed.
   * @param job The Job to be executed.
   */
  void Add(Job* job);
  //@Override
  void OnRequirementStatusChanged() override;
private:
  OsIndependentPowerManager::WakeLock* AcquireWakeLock(OsIndependentContext* context, OsIndependentString* name, long timeout);
};

class Runnable1 : public Runnable
{
private:
  Job* job;
  JobQueue* jobQueue;
  AggregateDependencyInjector* dependencyInjector;
  PersistentStorage* persistentStorage;
  OsIndependentContext* context;
public:
  Runnable1(Job* job, 
    JobQueue* jobQueue, 
    AggregateDependencyInjector* dependencyInjector,
    PersistentStorage* persistentStorage,
    OsIndependentContext* context);
  void Run() override;
};

class Runnable2 : public Runnable
{
private:
  JobQueue* jobQueue;
public:
  Runnable2(JobQueue* jobQueue);
  void Run() override;
};
