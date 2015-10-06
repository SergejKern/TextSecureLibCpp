#pragma once
/*
  abstract class OsIndependentContentValues to replace  android.content.ContentValues
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/ContentValues.java#ContentValues
*/

// [ ] done
// TFS ID: 780

#include "..\Factory\Factory.h"

// public final class  [More ...] ContentValues implements Parcelable {
class OsIndependentContentValues : OsIndependentParcelable
{
private:
public:
  virtual void Put(OsIndependentString* key, bool value) = 0;
  virtual void Put(OsIndependentString* key, OsIndependentString* value) = 0;
};
