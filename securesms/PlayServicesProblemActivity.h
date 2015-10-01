#pragma once

/*
Port of PlayServicesProblemActivity.java from TextSecure-android
*/

// [x] done
// TFS ID: 736

#include "..\osindependent\OsIndependentFragmentActivity.h"
#include "..\osindependent\OsIndependentBundle.h"
#include "PlayServicesProblemFragment.h"

// TODO REFACTOR: is this needed on non android ??
class PlayServicesProblemActivity : public OsIndependentFragmentActivity
{
private:
  typedef OsIndependentFragmentActivity super;
public:
  //@Override
  void OnCreate(OsIndependentBundle* bundle)
  {
    super::OnCreate(bundle);
    PlayServicesProblemFragment* fragment = new PlayServicesProblemFragment();
    fragment->Show(GetSupportFragmentManager(), "dialog");
  }
};
