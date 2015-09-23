#pragma once
/*
  abstract class OsIndependentAttributeSet to replace android.preference.RingtonePreference
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/util/AttributeSet.java#AttributeSet
*/

// [ ] done
// TFS ID: 668

#include "OsIndependentContext.h"
#include "OsIndependentAttributeSet.h"

/* public class RingtonePreference extends Preference implements
PreferenceManager.OnActivityResultListener */
class OsIndependentRingtonePreference
{
private:
public:
  /*
  */
  OsIndependentRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs, int defStyleAttr);
  OsIndependentRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs);
  OsIndependentRingtonePreference(OsIndependentContext* context);
};
