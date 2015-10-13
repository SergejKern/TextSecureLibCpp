#include "JobQueue.h"

void JobQueue::OnRequirementStatusChanged()
{
  NotifyAll();
}
/*synchronized*/
void JobQueue::Add(Job* job)
{
  jobQueue->push_back(job);
  NotifyAll();
}
/*synchronized*/
void JobQueue::AddAll(std::list<Job*>* jobs)
{
  //for (std::list<Job*>::iterator it = jobs->begin(); it != jobs->end(); ++it)
  //{
  //  jobQueue->push_back(*it);
  //}
  jobQueue->merge(*jobs);
  NotifyAll();
}
/*synchronized*/
void JobQueue::Push(Job* job)
{
  jobQueue->push_front(job);
}
/*synchronized*/
Job* JobQueue::GetNext()
{
  try
  {
    Job* nextAvailableJob;
    while ((nextAvailableJob = GetNextAvailableJob()) == nullptr)
    {
      Wait();
    }
    return nextAvailableJob;
  }
  catch(...) // (InterruptedException e) is thrown by java.lang.Object.wait()
  {
    throw new AssertionError(/*e*/);
  }
}
bool JobQueue::IsGroupIdAvailable(OsIndependentString* groupId)
{
  return groupId == nullptr || !activeGroupIds->Contains(groupId);
}
// SetGroupIdAvailable mixed with SetGroupIdUnavailable ???
/*synchronized*/ void JobQueue::SetGroupIdAvailable(OsIndependentString* groupId)
{
  if (groupId != nullptr)
  {
    activeGroupIds->Remove(groupId);
    NotifyAll();
  }
}
// SetGroupIdAvailable mixed with SetGroupIdUnavailable ???
void JobQueue::SetGroupIdUnavailable(OsIndependentString* groupId)
{
  if (groupId != nullptr)
  {
    activeGroupIds->Add(groupId);
  }
}
Job* JobQueue::GetNextAvailableJob()
{
  if (jobQueue->empty())
    return nullptr;

  for (std::list<Job*>::iterator it = jobQueue->begin(); it != jobQueue->end(); ++it)
  {
    Job* job = *it;
    if (job->IsRequirementsMet() && IsGroupIdAvailable((OsIndependentString*)job->GetGroupId()))
    {
      // TODO iterator may break here!!!
      jobQueue->remove(job);
      SetGroupIdUnavailable((OsIndependentString*)job->GetGroupId());
      return job;
    }
  }
  return nullptr;
}
