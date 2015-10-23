#include "JobManager.h"

/**
 * A JobManager allows you to enqueue {@link org.whispersystems.jobqueue.Job} tasks
 * that are executed once a Job's {@link org.whispersystems.jobqueue.requirements.Requirement}s
 * are met.
 */
JobManager::LoadTask::LoadTask(EncryptionKeys* keys, PersistentStorage* persistentStorage, JobQueue* jobQueue)
{
  this->keys = keys;
  this->persistentStorage = persistentStorage;
  this->jobQueue = jobQueue;
}
    //@Override
void JobManager::LoadTask::Run()
{
  std::list<Job*>* pendingJobs;
  if (keys == nullptr)
  {
    pendingJobs = this->persistentStorage->GetAllUnencrypted();
  }
  else
  {
    pendingJobs = this->persistentStorage->GetAllEncrypted(keys);
  }
  this->jobQueue->AddAll(pendingJobs);
}
JobManager::Builder::Builder(OsIndependentContext* context)
{
  this->context = context;
  this->consumerThreads = 5;
}
JobManager::Builder* JobManager::Builder::WithName(OsIndependentString* name)
{
  this->name = name;
  return this;
}

JobManager::Builder* JobManager::Builder::WithDependencyInjector(DependencyInjector* dependencyInjector)
{
  this->dependencyInjector = dependencyInjector;
  return this;
}
JobManager::Builder* JobManager::Builder::WithJobSerializer(JobSerializer* jobSerializer)
{
  this->jobSerializer = jobSerializer;
  return this;
}
JobManager::Builder* JobManager::Builder::WithConsumerThreads(int consumerThreads)
{
  this->consumerThreads = consumerThreads;
  return this;
}
JobManager* JobManager::Builder::Build()
{
  if (name == nullptr)
  {
    throw new IllegalArgumentException(FactoryString::GetInstance()->CreateNewString("You must specify a name!"));
  }
  if (requirementProviders == nullptr)
  {
    requirementProviders = new std::vector<RequirementProvider*>();
  }

  return new JobManager(context, name, requirementProviders,
    dependencyInjector, jobSerializer,
    consumerThreads);
}
JobManager::JobManager(OsIndependentContext* context, OsIndependentString* name,
  std::vector<RequirementProvider*>* requirementProviders,
  DependencyInjector* dependencyInjector,
  JobSerializer* jobSerializer, int consumers)
{
  this->context = context;
  this->dependencyInjector = new AggregateDependencyInjector(dependencyInjector);
  this->persistentStorage = new PersistentStorage(context, name, jobSerializer, this->dependencyInjector);
  this->requirementProviders = requirementProviders;

  eventExecutor->Execute(new LoadTask(nullptr, this->persistentStorage, this->jobQueue));

  if (requirementProviders != nullptr && !requirementProviders->empty())
  {
    for (int i = 0; i < requirementProviders->size(); i++)
    {
      RequirementProvider* provider = (*requirementProviders)[i];
      provider->SetListener(this);
    }
  }
  for (int i = 0; i < consumers; i++)
  {
    // Garbage Collector Trash!
    // TODO: collect pointer!!
    new JobConsumer(FactoryString::GetInstance()->CreateNewString((unsigned char*)"JobConsumer-", i), 
      jobQueue, persistentStorage)
      ->Start();
  }
}
JobManager::Builder* JobManager::NewBuilder(OsIndependentContext* context)
{
  return new JobManager::Builder(context);
}

void JobManager::SetEncryptionKeys(EncryptionKeys* keys)
{
  if (hasLoadedEncrypted->CompareAndSet(false, true))
  {
    eventExecutor->Execute(new LoadTask(keys, this->persistentStorage, this->jobQueue));
  }
}
void JobManager::Add(Job* job)
{
  if (job->NeedsWakeLock())
  {
    job->SetWakeLock(AcquireWakeLock(context, job->ToString(), job->GetWakeLockTimeout()));
  }
  // TODO: memory leak
  eventExecutor->Execute(new Runnable1(job, jobQueue, dependencyInjector, persistentStorage, context));
}
void Runnable1::Run()
{
  try {
    if (job->IsPersistent())
    {
      persistentStorage->Store(job);
    }
    dependencyInjector->InjectDependencies(context, job);
    job->OnAdded();
    jobQueue->Add(job);
  }
  catch (IOException* e)
  {
    //Log.w("JobManager", e);
    job->OnCanceled();
  }
}
Runnable1::Runnable1(Job* job, JobQueue* jobQueue, AggregateDependencyInjector* dependencyInjector, PersistentStorage* persistentStorage, OsIndependentContext* context)
{
  this->job = job;
  this->jobQueue = jobQueue;
  this->dependencyInjector = dependencyInjector;
  this->persistentStorage = persistentStorage;
  this->context = context;
}
//@Override
void JobManager::OnRequirementStatusChanged()
{
  eventExecutor->Execute(new Runnable2(jobQueue));
}
Runnable2::Runnable2(JobQueue* jobQueue)
{
  this->jobQueue = jobQueue;
}
// override
void Runnable2::Run()
{
  jobQueue->OnRequirementStatusChanged();
}
OsIndependentPowerManager::WakeLock* JobManager::AcquireWakeLock(OsIndependentContext* context, OsIndependentString* name, long timeout)
{
  OsIndependentPowerManager* powerManager = (OsIndependentPowerManager*)context->GetSystemService((OsIndependentString*)OsIndependentContext::POWER_SERVICE);
  OsIndependentPowerManager::WakeLock* wakeLock = powerManager->NewWakeLock(OsIndependentPowerManager::PARTIAL_WAKE_LOCK, name);

  if (timeout == 0)
    wakeLock->Acquire();
  else
    wakeLock->Acquire(timeout);
  return wakeLock;
}
