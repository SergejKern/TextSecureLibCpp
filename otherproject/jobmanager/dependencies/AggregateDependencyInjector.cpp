#include "AggregateDependencyInjector.h"
#include "ContextDependent.h"

AggregateDependencyInjector::AggregateDependencyInjector(DependencyInjector* dependencyInjector)
{
  this->dependencyInjector = dependencyInjector;
}
void AggregateDependencyInjector::InjectDependencies(OsIndependentContext* context, Job* job)
{
  /*
  TODO REFACTOR
  Every time you need to use a dynamic_cast (or instanceof)
  you'd better ask yourself whether it's a necessary thing.
  It's generally a sign of poor design.

  introduce something like a visitor ???
  */
  //if (job instanceof ContextDependent)
  // TODO ? Job _is_not_ ContextDependent
  //if (Job* v = dynamic_cast<ContextDependent*>(job))
  //{
  //  ((ContextDependent*)job)->SetContext(context);
  //}
  for (Requirement* requirement : job->GetRequirements())
  {
    //if (requirement instanceof ContextDependent)
    // TODO ? Requirement _is_not_ ContextDependent
    //if (Requirement* v = dynamic_cast<ContextDependent*>(requirement))
    //{
    //  ((ContextDependent*)requirement)->SetContext(context);
    //}
  }
  if (dependencyInjector != nullptr)
  {
    dependencyInjector->InjectDependencies(job);
    for (Requirement* requirement : job->GetRequirements())
    {
      dependencyInjector->InjectDependencies(requirement);
    }
  }
}
