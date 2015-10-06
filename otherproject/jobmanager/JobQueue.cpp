#include "JobQueue.h"

void JobQueue::OnRequirementStatusChanged()
{
  NotifyAll();
}
/*synchronized*/
void JobQueue::Add(Job* job)
{
  jobQueue->Add(job);
  NotifyAll();
}
/*synchronized*/
void JobQueue::AddAll(List<Job*>* jobs)
{
  jobQueue->AddAll(jobs);
  NotifyAll();
}
/*synchronized*/
void JobQueue::Push(Job* job)
{
  jobQueue->AddFirst(job);
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
  catch (InterruptedException e)
  {
    throw new AssertionError(e);
  }
}
/*synchronized*/ void JobQueue::SetGroupIdAvailable(OsIndependentString* groupId)
{
  if (groupId != nullptr)
  {
    activeGroupIds->Remove(groupId);
    NotifyAll();
  }
}
Job* JobQueue::GetNextAvailableJob()
{
  if (jobQueue->IsEmpty())
    return nullptr;

  ListIterator<Job*> iterator = jobQueue->listIterator();
  while (iterator.hasNext())
  {
    Job* job = iterator.next();
    if (job->IsRequirementsMet() && IsGroupIdAvailable((OsIndependentString*)job->GetGroupId()))
    {
      iterator.remove();
      SetGroupIdUnavailable((OsIndependentString*)job->GetGroupId());
      return job;
    }
  }
  return nullptr;
}
bool JobQueue::IsGroupIdAvailable(OsIndependentString* groupId)
{
  return groupId == nullptr || !activeGroupIds->Contains(groupId);
}
void JobQueue::SetGroupIdUnavailable(OsIndependentString* groupId)
{
  if (groupId != nullptr)
  {
    activeGroupIds->Add(groupId);
  }
}
