#pragma once
/*
Port of class DependencyInjector from jobmanager-android
*/

// [x] done
// TFS ID: 772

/**
 * Interface responsible for injecting dependencies into Jobs.
 */
class DependencyInjector
{
public:
  virtual void InjectDependencies(void* object) = 0;
};
