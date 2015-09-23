#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.ContentResolver
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/ContentResolver.java#ContentResolver
*/

// [ ] done
// TFS ID: 665

#include "OsIndependentUri.h"
#include "OsIndependentContentObserver.h"

/* public class  Intent implements Parcelable, Cloneable { */
class OsIndependentContentResolver
{
private:
public:
  // public void  [More ...] notifyChange(Uri uri, ContentObserver observer) {
  virtual void NotifyChange(OsIndependentUri* uri, OsIndependentContentObserver* observer) = 0;
};
