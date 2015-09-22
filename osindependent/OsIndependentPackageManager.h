#pragma once
/*
  abstract class OsIndependentPackageManager to replace android.content.pm.PackageManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/pm/PackageManager.java#PackageManager
*/

// [ ] done
// TFS ID: 669

#include "OsIndependentPackageInfo.h"

class OsIndependentPackageManager
{
private:
public:
  /*
  */
  virtual OsIndependentPackageInfo* GetPackageInfo(unsigned char* packageName, int flags) = 0;
};
