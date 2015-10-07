#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.Intent
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/Intent.java#Intent
*/

// [ ] done
// TFS ID: 665

#include "..\Factory\Factory.h"

/* public class  Intent implements Parcelable, Cloneable { */
class OsIndependentIntent : OsIndependentParcelable
{
private:
public:
  virtual OsIndependentIntent* SetAction(OsIndependentString* action) = 0;
  virtual OsIndependentIntent* PutExtra(OsIndependentString* name, long value) = 0;
  virtual OsIndependentIntent* PutExtra(OsIndependentString* name, OsIndependentString* value) = 0;
  virtual OsIndependentIntent* SetPackage(OsIndependentString* packageName) = 0;
  virtual OsIndependentString* GetStringExtra(OsIndependentString* name) = 0;
  virtual bool HasExtra(OsIndependentString* name) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentIntent  |<-----------|    FactoryIntent    |
+----------------------+            +---------------------+
           ^                                   ^                Plattform independent code
          /|\                                 /|\
           |                                   |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                   |
           |                                   |                Plattform specific code
           |                                   |
+----------------------+  creates   +---------------------+
|     Tizen-Intent     |<-----------| TizenFactoryIntent  |
+----------------------+            +---------------------+
*/
class FactoryIntent
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryIntent* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryIntent* plattformSpecific) { FactoryIntent::instance = plattformSpecific; }
  static FactoryIntent* GetInstance()
  {
    if (FactoryIntent::instance == nullptr)
      throw;
    return FactoryIntent::instance;
  }
  // interface
  virtual OsIndependentIntent* CreateNewIntent(OsIndependentString* action) = 0;
};
