#pragma once
/*
  abstract class OsIndependentPackageInfo to replace android.content.pm.PackageInfo
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/pm/PackageInfo.java#PackageInfo
*/

// [ ] done
// TFS ID: 670

#include "OsIndependentParcelable.h"

/* public class  [More ...] PackageInfo implements Parcelable { */
class OsIndependentPackageInfo : OsIndependentParcelable
{
private:
  OsIndependentPackageInfo();
public:
  int versionCode;
  /*
  */
  
};

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+--------------------------+  creates   +-------------------------+
| OsIndependentPackageInfo |<-----------|    FactoryPackageInfo   |
+--------------------------+            +-------------------------+
             ^                                       ^                Plattform independent code
            /|\                                     /|\
             |                                       |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                       |
             |                                       |                Plattform specific code
             |                                       |
+--------------------------+  creates   +-------------------------+
|     Tizen-PackageInfo    |<-----------| TizenFactoryPackageInfo |
+--------------------------+            +-------------------------+
*/
class FactoryPackageInfo
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryPackageInfo* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryPackageInfo* plattformSpecific) { FactoryPackageInfo::instance = plattformSpecific; }
  static FactoryPackageInfo* GetInstance()
  {
    if (FactoryPackageInfo::instance == nullptr)
      throw;
    return FactoryPackageInfo::instance;
  }
  // interface
  virtual OsIndependentPackageInfo* CreateNewPackageInfo() = 0;
};
