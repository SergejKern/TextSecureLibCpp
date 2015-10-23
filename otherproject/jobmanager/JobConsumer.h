#pragma once
/*
Port of class JobConsumer from jobmanager-android
*/

// [ ] done
// TFS ID: 769

#include "..\..\osindependent\OsIndependentThread.h"

//import android.util.Log;
#include "persistence\PersistentStorage.h"
#include "JobQueue.h"

class JobConsumer /*: public OsIndependentThread*/
{
private:
  OsIndependentThread* thread;
  static const OsIndependentString* TAG;
  enum JobResult
  {
    SUCCESS,
    FAILURE,
    DEFERRED
  };
  JobQueue* jobQueue;
  PersistentStorage* persistentStorage;
public:
  JobConsumer(OsIndependentString* name, JobQueue* jobQueue, PersistentStorage* persistentStorage);
  //@Override
  void Run();
  // override method of Thread
  void Start();
private:
  JobResult RunJob(Job* job);
};

const OsIndependentString* JobConsumer::TAG = FactoryString::GetInstance()->CreateNewString("JobConsumer");
