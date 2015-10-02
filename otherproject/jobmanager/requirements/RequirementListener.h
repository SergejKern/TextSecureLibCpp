#pragma once
/*
Port of class RequirementListener from jobmanager-android
*/

// [x] done
// TFS ID: 777

class RequirementListener
{
public:
  virtual void OnRequirementStatusChanged() = 0;
};
