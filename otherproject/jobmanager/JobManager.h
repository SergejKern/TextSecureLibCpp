#pragma once
/*
Port of class JobManager from jobmanager-android
*/

// [ ] done
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
#include "..\..\owntemplates\ArrayList.h"
#include "..\..\owntemplates\List.h"
#include "JobQueue.h"
//import java.util.concurrent.Executor;
//import java.util.concurrent.Executors;
//import java.util.concurrent.atomic.AtomicBoolean;

/**
 * A JobManager allows you to enqueue {@link org.whispersystems.jobqueue.Job} tasks
 * that are executed once a Job's {@link org.whispersystems.jobqueue.requirements.Requirement}s
 * are met.
 */
class JobManager : public RequirementListener
{
private:
  JobQueue* jobQueue = new JobQueue();
  Executor* eventExecutor = Executors.newSingleThreadExecutor();
  AtomicBoolean* hasLoadedEncrypted = new AtomicBoolean(false);

  OsIndependentContext* context;
  PersistentStorage* persistentStorage;
  List<RequirementProvider*>*   requirementProviders;
  AggregateDependencyInjector* dependencyInjector;

private:
  class LoadTask : Runnable
  {
  private:
    EncryptionKeys* keys;
  public:
    LoadTask(EncryptionKeys* keys)
    {
      this->keys = keys;
    }
    //@Override
    void Run() override
    {
      List<Job*>* pendingJobs;
      if (keys == nullptr)
        pendingJobs = persistentStorage->GetAllUnencrypted();
      else
        pendingJobs = persistentStorage->GetAllEncrypted(keys);
      jobQueue->AddAll(pendingJobs);
    }
  };
public:
  class Builder {
  private:
    OsIndependentContext* context;
    OsIndependentString* name;
    List<RequirementProvider*>* requirementProviders;
    DependencyInjector* dependencyInjector;
    JobSerializer* jobSerializer;
    int consumerThreads;

    Builder(OsIndependentContext* context)
    {
      this->context = context;
      this->consumerThreads = 5;
    }
    /**
    * A name for the {@link org.whispersystems.jobqueue.JobManager}. This is a required parameter,
    * and is linked to the durable queue used by persistent jobs.
    *
    * @param name The name for the JobManager to build.
    * @return The builder.
    */
  public:
    Builder* WithName(OsIndependentString* name)
    {
      this->name = name;
      return this;
    }

    /**
    * The {@link org.whispersystems.jobqueue.requirements.RequirementProvider}s to register with this
    * JobManager.  Optional. Each {@link org.whispersystems.jobqueue.requirements.Requirement} an
    * enqueued Job depends on should have a matching RequirementProvider registered here.
    *
    * @param requirementProviders The RequirementProviders
    * @return The builder.
    */
    Builder* WithRequirementProviders(RequirementProvider... requirementProviders)
    {
      this->requirementProviders = Arrays.asList(requirementProviders);
      return this;
    }
    /**
    * The {@link org.whispersystems.jobqueue.dependencies.DependencyInjector} to use for injecting
    * dependencies into {@link Job}s. Optional. Injection occurs just before a Job's onAdded() callback, or
    * after deserializing a persistent job.
    *
    * @param dependencyInjector The injector to use.
    * @return The builder.
    */
    Builder* WithDependencyInjector(DependencyInjector* dependencyInjector)
    {
      this->dependencyInjector = dependencyInjector;
      return this;
    }
    /**
    * The {@link org.whispersystems.jobqueue.persistence.JobSerializer} to use for persistent Jobs.
    * Required if persistent Jobs are used.
    *
    * @param jobSerializer The serializer to use.
    * @return The builder.
    */
    Builder* WithJobSerializer(JobSerializer* jobSerializer)
    {
      this->jobSerializer = jobSerializer;
      return this;
    }
    /**
    * Set the number of threads dedicated to consuming Jobs from the queue and executing them.
    *
    * @param consumerThreads The number of threads.
    * @return The builder.
    */
    Builder* WithConsumerThreads(int consumerThreads)
    {
      this->consumerThreads = consumerThreads;
      return this;
    }
    /**
    * @return A constructed JobManager.
    */
    JobManager* Build()
    {
      if (name == nullptr)
      {
        throw new IllegalArgumentException("You must specify a name!");
      }
      if (requirementProviders == nullptr)
      {
        requirementProviders = new LinkedList<RequirementProvider*>();
      }

      return new JobManager(context, name, requirementProviders,
        dependencyInjector, jobSerializer,
        consumerThreads);
    }
  };
public:
  JobManager(OsIndependentContext* context, OsIndependentString* name,
                     List<RequirementProvider*>* requirementProviders,
                     DependencyInjector* dependencyInjector,
                     JobSerializer* jobSerializer, int consumers)
  {
    this->context              = context;
    this->dependencyInjector   = new AggregateDependencyInjector(dependencyInjector);
    this->persistentStorage    = new PersistentStorage(context, name, jobSerializer, this.dependencyInjector);
    this->requirementProviders = requirementProviders;

    eventExecutor->Execute(new LoadTask(nullptr));

    if (requirementProviders != nullptr && !requirementProviders->IsEmpty())
    {
      for (int i = 0; i < requirementProviders->Size(); i++)
      {
        RequirementProvider* provider = requirementProviders->Get(i);
        provider->SetListener(this);
      }
    }
    for (int i = 0; i < consumers; i++)
    {
      new JobConsumer("JobConsumer-" + i, jobQueue, persistentStorage).start();
    }
  }

  /**
   * @param context An Android {@link android.content.Context}.
   * @return a {@link org.whispersystems.jobqueue.JobManager.Builder} used to construct a JobManager.
   */
  static Builder newBuilder(Context context) {
    return new Builder(context);
  }

  void setEncryptionKeys(EncryptionKeys keys) {
    if (hasLoadedEncrypted.compareAndSet(false, true)) {
      eventExecutor.execute(new LoadTask(keys));
    }
  }

  /**
   * Queue a {@link org.whispersystems.jobqueue.Job} to be executed.
   *
   * @param job The Job to be executed.
   */
  void add(const Job job) {
    if (job.needsWakeLock()) {
      job.setWakeLock(acquireWakeLock(context, job.toString(), job.getWakeLockTimeout()));
    }

    eventExecutor.execute(new Runnable() {
      @Override
      public void run() {
        try {
          if (job.isPersistent()) {
            persistentStorage.store(job);
          }

          dependencyInjector.injectDependencies(context, job);

          job.onAdded();
          jobQueue.add(job);
        } catch (IOException e) {
          Log.w("JobManager", e);
          job.onCanceled();
        }
      }
    });
  }

  //@Override
  void onRequirementStatusChanged() {
    eventExecutor.execute(new Runnable() {
      @Override
      public void run() {
        jobQueue.onRequirementStatusChanged();
      }
    });
  }

private:
  OsIndependentPowerManager::WakeLock* AcquireWakeLock(OsIndependentContext* context, OsIndependentString* name, long timeout)
  {
    OsIndependentPowerManager* powerManager = (OsIndependentPowerManager*)context->GetSystemService((OsIndependentString*)OsIndependentContext::POWER_SERVICE);
    OsIndependentPowerManager::WakeLock* wakeLock = powerManager->NewWakeLock(OsIndependentPowerManager::PARTIAL_WAKE_LOCK, name);

    if (timeout == 0)
      wakeLock->Acquire();
    else
      wakeLock->Acquire(timeout);
    return wakeLock;
  }
};
