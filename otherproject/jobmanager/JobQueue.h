#pragma once
/*
Port of class JobQueue from jobmanager-android
*/

// [x] done
// TFS ID: 770

#include "Job.h"

#include "..\..\Factory\Factory.h"

#include <list>
//import java.util.ListIterator;
#include "..\..\owntemplates\Set.h"

class JobQueue
{
private:
  Set<OsIndependentString*>* activeGroupIds = new HashSet<OsIndependentString*>();
  std::list<Job*>* jobQueue = new std::list<Job*>();
public:
  /*synchronized*/
  void OnRequirementStatusChanged();
  /*synchronized*/
  void Add(Job* job);
  /*synchronized*/
  void AddAll(std::list<Job*>* jobs);
  /*synchronized*/
  void Push(Job* job);
  /*synchronized*/
  Job* GetNext();
  /*synchronized*/
  void SetGroupIdAvailable(OsIndependentString* groupId);
  Job* GetNextAvailableJob();
  bool IsGroupIdAvailable(OsIndependentString* groupId);
  void SetGroupIdUnavailable(OsIndependentString* groupId);
  // stolen from java.lang.Object
  virtual void Wait()
  {
    throw new NotImplementedException();
  };
  // stolen from java.lang.Object
  virtual void NotifyAll()
  {
    throw new NotImplementedException();
  };
};
