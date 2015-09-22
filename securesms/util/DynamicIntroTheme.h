#pragma once

/*
Port of DynamicIntroTheme.java from TextSecure-android
*/

// [x] done
// [ ] is ready in TextSecure-android
// TFS ID: 217

#include "..\..\osindependent\OsIndependentActivity.h"
#include "DynamicTheme.h"
#include "TextSecurePreferences.h"
#include "..\R.h"

class DynamicIntroTheme : DynamicTheme
{
  
protected:
  //@Override
  int GetSelectedTheme(OsIndependentActivity* activity)
  {
    unsigned char* theme = TextSecurePreferences::GetTheme(activity);
    if (theme == "dark")
    {
      return R::Style::TextSecure_DarkIntroTheme;
    }
    return R::Style::TextSecure_LightIntroTheme;
  }
};
