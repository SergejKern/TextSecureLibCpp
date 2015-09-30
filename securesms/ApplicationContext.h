#pragma once

/*
Port of ApplicationContext.java from TextSecure-android
*/

// [ ] done
// TFS ID: 689

//import android.app.Application;
#include "..\osindependent\OsIndependentContext.h"
//import android.os.StrictMode;
//import android.os.StrictMode.ThreadPolicy;
//import android.os.StrictMode.VmPolicy;
//
//import org.thoughtcrime.securesms.crypto.PRNGFixes;
//import org.thoughtcrime.securesms.dependencies.AxolotlStorageModule;
//import org.thoughtcrime.securesms.dependencies.InjectableType;
//import org.thoughtcrime.securesms.dependencies.TextSecureCommunicationModule;
//import org.thoughtcrime.securesms.jobs.GcmRefreshJob;
//import org.thoughtcrime.securesms.jobs.persistence.EncryptingJobSerializer;
//import org.thoughtcrime.securesms.jobs.requirements.MasterSecretRequirementProvider;
//import org.thoughtcrime.securesms.jobs.requirements.MediaNetworkRequirementProvider;
//import org.thoughtcrime.securesms.jobs.requirements.ServiceRequirementProvider;
//import org.thoughtcrime.securesms.util.TextSecurePreferences;
//import org.whispersystems.jobqueue.JobManager;
//import org.whispersystems.jobqueue.dependencies.DependencyInjector;
//import org.whispersystems.jobqueue.requirements.NetworkRequirementProvider;
//import org.whispersystems.libaxolotl.logging.AxolotlLoggerProvider;
//import org.whispersystems.libaxolotl.util.AndroidAxolotlLogger;
//
//import dagger.ObjectGraph;

/**
 * Will be called once when the TextSecure process is created.
 *
 * We're using this as an insertion point to patch up the Android PRNG disaster,
 * to initialize the job manager, and to check for GCM registration freshness.
 *
 * @author Moxie Marlinspike
 */
class ApplicationContext : Application, DependencyInjector
{
private:
  JobManager* jobManager;
  ObjectGraph* objectGraph;
  MediaNetworkRequirementProvider* mediaNetworkRequirementProvider = new MediaNetworkRequirementProvider();
public:
  static ApplicationContext* GetInstance(OsIndependentContext* context)
  {
    return (ApplicationContext*)context->GetApplicationContext();
  }
  //@Override
  void OnCreate()
  {
    super.onCreate();
    InitializeDeveloperBuild();
    InitializeRandomNumberFix();
    InitializeLogging();
    InitializeDependencyInjection();
    InitializeJobManager();
    InitializeGcmCheck();
  }
  //@Override
  void InjectDependencies(Object object)
  {
    if (object instanceof InjectableType) {
      objectGraph.inject(object);
    }
  }
  JobManager* GetJobManager()
  {
    return jobManager;
  }
private:
  void InitializeDeveloperBuild()
  {
    if (BuildConfig.DEV_BUILD)
    {
//      LeakCanary.install(this);
      StrictMode::SetThreadPolicy(new ThreadPolicy.Builder().detectAll()
                                                           .penaltyLog()
                                                           .build());
      StrictMode::SetVmPolicy(new VmPolicy.Builder().detectAll().penaltyLog().build());
    }
  }
  void InitializeRandomNumberFix()
  {
    PRNGFixes.apply();
  }
  void InitializeLogging()
  {
    AxolotlLoggerProvider.setProvider(new AndroidAxolotlLogger());
  }
  void InitializeJobManager()
  {
    this->jobManager = JobManager.newBuilder(this)
                                .withName("TextSecureJobs")
                                .withDependencyInjector(this)
                                .withJobSerializer(new EncryptingJobSerializer())
                                .withRequirementProviders(new MasterSecretRequirementProvider(this),
                                                          new ServiceRequirementProvider(this),
                                                          new NetworkRequirementProvider(this),
                                                          mediaNetworkRequirementProvider)
                                .withConsumerThreads(5)
                                .build();
  }
  void NotifyMediaControlEvent()
  {
    mediaNetworkRequirementProvider.notifyMediaControlEvent();
  }
  void InitializeDependencyInjection()
  {
    this.objectGraph = ObjectGraph.create(new TextSecureCommunicationModule(this),
                                          new AxolotlStorageModule(this));
  }
  void InitializeGcmCheck()
  {
    if (TextSecurePreferences.isPushRegistered(this) &&
        TextSecurePreferences.getGcmRegistrationId(this) == null)
    {
      this.jobManager.add(new GcmRefreshJob(this));
    }
  }
};
