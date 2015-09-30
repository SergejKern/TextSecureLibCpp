#pragma once

/*
Port of MasterSecretListener.java from TextSecure-android
*/

// [x] done
// TFS ID: 714

#include "..\osindependent\OsIndependentActivity.h"
#include "..\osindependent\OsIndependentBundle.h"

/**
 * Workaround for Android bug:
 * https://code.google.com/p/android/issues/detail?id=53313
 * TODO: needed in C++/not-android ???
 */
class DummyActivity : public OsIndependentActivity
{
private:
  typedef OsIndependentActivity super;
public:
  //@Override
  void OnCreate(OsIndependentBundle* bundle)
  {
    super::OnCreate(bundle);
    Finish();
  }
};
