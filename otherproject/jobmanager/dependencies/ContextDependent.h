#pragma once
/*
Port of class ContextDependent from jobmanager-android
*/

// [x] done
// TFS ID: 762

#include "..\..\..\osindependent\OsIndependentContext.h"

/**
 * Any Job or Requirement that depends on {@link android.content.Context} can implement this
 * interface to receive a Context after being deserialized.
 */
class ContextDependent
{
public:
  virtual void SetContext(OsIndependentContext* context) = 0;
};
