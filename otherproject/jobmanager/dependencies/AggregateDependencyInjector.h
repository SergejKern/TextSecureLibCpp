#pragma once
/*
Port of class DependencyInjector from jobmanager-android
*/

// [x] done
// TFS ID: 771

//import android.content.Context;
#include "..\..\..\osindependent\OsIndependentContext.h"

#include "DependencyInjector.h"
#include "..\Job.h"

class AggregateDependencyInjector
{
private:
  DependencyInjector* dependencyInjector;
public:
  AggregateDependencyInjector(DependencyInjector* dependencyInjector);
  void InjectDependencies(OsIndependentContext* context, Job* job);
};
