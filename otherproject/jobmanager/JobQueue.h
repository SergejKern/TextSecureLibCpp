#pragma once
/*
Port of class JobQueue from jobmanager-android
*/

// [ ] done
// TFS ID: 770

#include "Job.h"

#include "..\..\Factory\Factory.h"

#include "..\..\owntemplates\List.h"
//import java.util.ListIterator;
#include "..\..\owntemplates\Set.h"

class JobQueue
{
private:
  Set<OsIndependentString*>* activeGroupIds = new HashSet<OsIndependentString*>();
  LinkedList<Job*>* jobQueue = new LinkedList<Job*>();
public:
  /*synchronized*/
  void OnRequirementStatusChanged();
  /*synchronized*/
  void Add(Job* job);
  /*synchronized*/
  void AddAll(List<Job*>* jobs);
  /*synchronized*/
  void Push(Job* job);
  /*synchronized*/
  Job* GetNext();
  /*synchronized*/
  void SetGroupIdAvailable(OsIndependentString* groupId);
  Job* GetNextAvailableJob();
  bool IsGroupIdAvailable(OsIndependentString* groupId);
  void SetGroupIdUnavailable(OsIndependentString* groupId);
};
