#pragma once
/*
  abstract class OsIndependentAttributeSet to replace android.preference.PreferenceManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/preference/PreferenceManager.java#PreferenceManager
*/

// [ ] done
// TFS ID: 803

#include "OsIndependentContext.h"
#include "OsIndependentActivity.h"
#include "OsIndependentSharedPreferences.h"

/* public class PreferenceManager extends Preference implements
PreferenceManager.OnActivityResultListener */
class OsIndependentPreferenceManager
{
private:
public:
  // public static SharedPreferences  [More ...] getDefaultSharedPreferences(Context context) {
  virtual OsIndependentSharedPreferences* GetDefaultSharedPreferences(OsIndependentContext*) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+--------------------------------+  creates   +-------------------------------+
| OsIndependentPreferenceManager |<-----------|    FactoryPreferenceManager   |
+--------------------------------+            +-------------------------------+
                ^                                             ^                Plattform independent code
               /|\                                           /|\
                |                                             |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                |                                             |
                |                                             |                Plattform specific code
                |                                             |
+--------------------------------+  creates   +-------------------------------+
|     Tizen-PreferenceManager    |<-----------| TizenFactoryPreferenceManager |
+--------------------------------+            +-------------------------------+
*/
class FactoryPreferenceManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryPreferenceManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryPreferenceManager* plattformSpecific) { FactoryPreferenceManager::instance = plattformSpecific; }
  static FactoryPreferenceManager* GetInstance()
  {
    if (FactoryPreferenceManager::instance == nullptr)
      throw;
    return FactoryPreferenceManager::instance;
  }
  // interface
  virtual OsIndependentPreferenceManager* CreateNewPreferenceManager() = 0;
  virtual OsIndependentPreferenceManager* CreateNewPreferenceManager(OsIndependentContext* context) = 0;
  virtual OsIndependentPreferenceManager* CreateNewPreferenceManager(OsIndependentActivity* activity, int firstRequestCode) = 0;
};
