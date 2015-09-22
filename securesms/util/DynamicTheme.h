#pragma once

/*
Port of DynamicTheme.java from TextSecure-android
*/

// [x] done
// [ ] is ready in TextSecure-android
// TFS ID: 220

#include "..\..\osindependent\OsIndependentActivity.h"
#include "..\..\osindependent\OsIndependentIntent.h"
#include "TextSecurePreferences.h"
#include "..\R.h"

// import org.thoughtcrime.securesms.R;

class DynamicTheme
{
private:
  int currentTheme;
private:
  class OverridePendingTransition
  {
  public:
    static void Invoke(OsIndependentActivity* activity)
    {
      activity->OverridePendingTransition(0, 0);
    }
  };
public:
  virtual void OnCreate(OsIndependentActivity* activity)
  {
    currentTheme = getSelectedTheme(activity);
    activity->SetTheme(currentTheme);
  }
  virtual void OnResume(OsIndependentActivity* activity)
  {
    if (currentTheme != getSelectedTheme(activity)) {
      OsIndependentIntent* intent = activity->GetIntent();
      activity->Finish();
      OverridePendingTransition::Invoke(activity);
      activity->StartActivity(intent);
      OverridePendingTransition::Invoke(activity);
    }
  }
protected:
  virtual int GetSelectedTheme(OsIndependentActivity* activity)
  {
    unsigned char* theme = TextSecurePreferences::GetTheme(activity);
    if (theme == "dark")
    {
      return R::Style::TextSecure_DarkTheme;
    }
    return R::Style::TextSecure_LightTheme;
  }
};
