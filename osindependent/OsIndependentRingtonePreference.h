#pragma once
/*
  abstract class OsIndependentAttributeSet to replace android.preference.RingtonePreference
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/util/AttributeSet.java#AttributeSet
*/

// [ ] done
// TFS ID: 668

#include "..\Factory\Factory.h"

/* public class RingtonePreference extends Preference implements
PreferenceManager.OnActivityResultListener */
class OsIndependentRingtonePreference
{
private:
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------------+  creates   +--------------------------------+
| OsIndependentRingtonePreference |<-----------|    FactoryRingtonePreference   |
+---------------------------------+            +--------------------------------+
                ^                                 ^                Plattform independent code
               /|\                               /|\
                |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                |                                 |
                |                                 |                Plattform specific code
                |                                 |
+---------------------------------+  creates   +--------------------------------+
|     Tizen-RingtonePreference    |<-----------| TizenFactoryRingtonePreference |
+---------------------------------+            +--------------------------------+
*/
class FactoryRingtonePreference
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryRingtonePreference* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryRingtonePreference* plattformSpecific) { FactoryRingtonePreference::instance = plattformSpecific; }
  static FactoryRingtonePreference* GetInstance()
  {
    if (FactoryRingtonePreference::instance == nullptr)
      throw;
    return FactoryRingtonePreference::instance;
  }
  // interface
  virtual OsIndependentRingtonePreference* CreateNewRingtonePreference(OsIndependentContext* context) = 0;
  virtual OsIndependentRingtonePreference* CreateNewRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs, int defStyleAttr) = 0;
  virtual OsIndependentRingtonePreference* CreateNewRingtonePreference(OsIndependentContext* context, OsIndependentAttributeSet* attrs) = 0;
};
