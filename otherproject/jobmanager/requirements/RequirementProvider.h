#pragma once
/*
Port of class RequirementProvider from jobmanager-android
*/

// [x] done
// TFS ID: 778

#include "RequirementListener.h"

/**
 * Notifies listeners when a {@link org.whispersystems.jobqueue.requirements.Requirement}'s
 * state is likely to have changed.
 */
class RequirementProvider
{

  /**
   * The {@link org.whispersystems.jobqueue.requirements.RequirementListener} to call when
   * a {@link org.whispersystems.jobqueue.requirements.Requirement}'s status is likely to
   * have changed.
   *
   * @param listener The listener to call.
   */
public:
  virtual void SetListener(RequirementListener* listener) = 0;
};
