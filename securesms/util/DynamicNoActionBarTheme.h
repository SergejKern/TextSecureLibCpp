#pragma once

/*
Port of DynamicNoActionBarTheme.java from TextSecure-android
*/

// [x] done
// [ ] is ready in TextSecure-android
// TFS ID: 219

#include "..\..\osindependent\OsIndependentActivity.h"
#include "DynamicTheme.h"
#include "TextSecurePreferences.h"
#include "..\R.h"

class DynamicNoActionBarTheme : DynamicTheme
{
protected:
  //@Override
  int GetSelectedTheme(OsIndependentActivity* activity)
  {
    unsigned char* theme = TextSecurePreferences::GetTheme(activity);
    if (theme == "dark")
    {
      return R::Style::TextSecure_DarkNoActionBar;
    }
    return R::Style::TextSecure_LightNoActionBar;
  }
};
