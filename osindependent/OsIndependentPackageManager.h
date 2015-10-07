#pragma once
/*
  abstract class OsIndependentPackageManager to replace android.content.pm.PackageManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/pm/PackageManager.java#PackageManager
*/

// [ ] done
// TFS ID: 669

#include "..\Factory\Factory.h"

class OsIndependentPackageManager
{
private:
public:
  /*
  */
  virtual OsIndependentPackageInfo* GetPackageInfo(unsigned char* packageName, int flags) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------+  creates   +----------------------------+
| OsIndependentPackageManager |<-----------|    FactoryPackageManager   |
+-----------------------------+            +----------------------------+
              ^                                           ^                Plattform independent code
             /|\                                         /|\
              |                                           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                           |
              |                                           |                Plattform specific code
              |                                           |
+-----------------------------+  creates   +----------------------------+
|     Tizen-PackageManager    |<-----------| TizenFactoryPackageManager |
+-----------------------------+            +----------------------------+
*/
class FactoryPackageManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryPackageManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryPackageManager* plattformSpecific) { FactoryPackageManager::instance = plattformSpecific; }
  static FactoryPackageManager* GetInstance()
  {
    if (FactoryPackageManager::instance == nullptr)
      throw;
    return FactoryPackageManager::instance;
  }
  // interface
  virtual OsIndependentPackageManager* CreateNewPackageManager() = 0;
};
