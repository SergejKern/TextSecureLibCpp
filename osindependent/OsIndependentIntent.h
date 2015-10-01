#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.Intent
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/Intent.java#Intent
*/

// [ ] done
// TFS ID: 665

#include "OsIndependentParcelable.h"
#include "OsIndependentString.h"

/* public class  Intent implements Parcelable, Cloneable { */
class OsIndependentIntent : OsIndependentParcelable
{
private:
  OsIndependentString* mAction;
public:
  OsIndependentIntent(OsIndependentString* action);
  virtual OsIndependentIntent* SetAction(OsIndependentString* action) = 0;
  virtual OsIndependentIntent* PutExtra(OsIndependentString* name, long value) = 0;
  virtual OsIndependentIntent* SetPackage(OsIndependentString* packageName) = 0;
  virtual OsIndependentString* GetStringExtra(OsIndependentString* name) = 0;
  virtual bool HasExtra(OsIndependentString* name) = 0;
};
