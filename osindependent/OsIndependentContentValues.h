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
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------------+            +---------------------------+
| OsIndependentContentValues |<-----------|    FactoryContentValues   |
+----------------------------+            +---------------------------+
              ^                                         ^                Plattform independent code
             /|\                                       /|\
              |                                         |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                         |
              |                                         |                Plattform specific code
              |                                         |
+----------------------------+            +---------------------------+
|     Tizen-ContentValues    |<-----------| TizenFactoryContentValues |
+----------------------------+            +---------------------------+
*/
class FactoryContentValues
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryContentValues* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryContentValues* plattformSpecific) { FactoryContentValues::instance = plattformSpecific; }
  static FactoryContentValues* GetInstance()
  {
    if (FactoryContentValues::instance == nullptr)
      throw;
    return FactoryContentValues::instance;
  }
  // interface
  virtual OsIndependentContentValues* CreateNewContentValues() = 0;
};
