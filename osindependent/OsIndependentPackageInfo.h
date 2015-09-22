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
public:
  int versionCode;
  /*
  */
  
};
