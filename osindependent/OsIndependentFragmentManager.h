#pragma once
/*
  abstract class OsIndependentFragmentManager to replace android.support.v4.app.FragmentManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/support/v4/app/FragmentManager.java#FragmentManager
*/

// [ ] done
// TFS ID: 758

#include "..\Factory\Factory.h"

//public abstract class  [More ...] FragmentManager {
class OsIndependentFragmentManager
{
private:
  OsIndependentFragmentManager();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------+  creates   +-----------------------------+
| OsIndependentFragmentManager |<-----------|    FactoryFragmentManager   |
+------------------------------+            +-----------------------------+
               ^                                            ^                Plattform independent code
              /|\                                          /|\
               |                                            |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                            |
               |                                            |                Plattform specific code
               |                                            |
+------------------------------+  creates   +-----------------------------+
|     Tizen-FragmentManager    |<-----------| TizenFactoryFragmentManager |
+------------------------------+            +-----------------------------+
*/
class FactoryFragmentManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryFragmentManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryFragmentManager* plattformSpecific) { FactoryFragmentManager::instance = plattformSpecific; }
  static FactoryFragmentManager* GetInstance()
  {
    if (FactoryFragmentManager::instance == nullptr)
      throw;
    return FactoryFragmentManager::instance;
  }
  // interface
  virtual OsIndependentFragmentManager* CreateNewFragmentManager() = 0;
};
