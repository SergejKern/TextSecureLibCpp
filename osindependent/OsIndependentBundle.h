#pragma once
/*
  abstract class OsIndependentCursor to replace  android.os.Bundle
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Bundle.java#Bundle
*/

// [ ] done
// TFS ID: 684

#include "OsIndependentParcelable.h"

// public final class Bundle extends BaseBundle implements Cloneable, Parcelable{
class OsIndependentBundle : public OsIndependentParcelable
{
private:
  OsIndependentBundle();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentBundle  |<-----------|    FactoryBundle    |
+----------------------+            +---------------------+
            ^                                  ^                Plattform independent code
           /|\                                /|\
            |                                  |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                  |
            |                                  |                Plattform specific code
            |                                  |
+----------------------+  creates   +---------------------+
|     Tizen-Bundle     |<-----------| TizenFactoryBundle  |
+----------------------+            +---------------------+
*/
class FactoryBundle
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryBundle* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryBundle* plattformSpecific) { FactoryBundle::instance = plattformSpecific; }
  static FactoryBundle* GetInstance()
  {
    if (FactoryBundle::instance == nullptr)
      throw;
    return FactoryBundle::instance;
  }
  // interface
  virtual OsIndependentBundle* CreateNewBundle() = 0;
};
