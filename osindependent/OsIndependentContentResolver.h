#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.ContentResolver
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/ContentResolver.java#ContentResolver
*/

// [ ] done
// TFS ID: 665

#include "OsIndependentUri.h"
#include "OsIndependentContentObserver.h"

/* public abstract class  [More ...] ContentResolver { */
class OsIndependentContentResolver
{
private:
public:
  // public void  [More ...] notifyChange(Uri uri, ContentObserver observer) {
  virtual void NotifyChange(OsIndependentUri* uri, OsIndependentContentObserver* observer) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------+  creates   +-----------------------------+
| OsIndependentContentResolver |<-----------|    FactoryContentResolver   |
+------------------------------+            +-----------------------------+
              ^                                             ^                Plattform independent code
             /|\                                           /|\
              |                                             |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                             |
              |                                             |                Plattform specific code
              |                                             |
+------------------------------+  creates   +-----------------------------+
|     Tizen-ContentResolver    |<-----------| TizenFactoryContentResolver |
+------------------------------+            +-----------------------------+
*/
class FactoryContentResolver
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryContentResolver* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryContentResolver* plattformSpecific) { FactoryContentResolver::instance = plattformSpecific; }
  static FactoryContentResolver* GetInstance()
  {
    if (FactoryContentResolver::instance == nullptr)
      throw;
    return FactoryContentResolver::instance;
  }
  // interface
  virtual OsIndependentContentResolver* CreateNewContentResolver() = 0;
};
