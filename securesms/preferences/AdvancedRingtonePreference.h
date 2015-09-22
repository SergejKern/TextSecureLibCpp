#pragma once

/*
Port of AdvancedRingtonePreference.java from TextSecure-android
*/

// [x] done
// TFS ID: 612

#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentUri.h"
#include "..\..\osindependent\OsIndependentRingtonePreference.h"
#include "..\..\osindependent\OsIndependentAttributeSet.h"


class AdvancedRingtonePreference : OsIndependentRingtonePreference
{
private:
  OsIndependentUri* currentRingtone;

public:
  AdvancedRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs, int defStyleAttr)
    : OsIndependentRingtonePreference(context, attrs, defStyleAttr)
  { }
  AdvancedRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs)
    : OsIndependentRingtonePreference(context, attrs)
  { }
  AdvancedRingtonePreference(OsIndependentContext* context)
  :OsIndependentRingtonePreference(context)
  { }
protected:
  //@Override
  OsIndependentUri* OnRestoreRingtone()
  {
    return currentRingtone;
  }
public:
  void SetCurrentRingtone(OsIndependentUri* uri)
  {
    currentRingtone = uri;
  }
};
