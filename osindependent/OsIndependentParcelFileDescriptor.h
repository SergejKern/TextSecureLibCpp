#pragma once
/*
  abstract class OsIndependentParcelFileDescriptor to replace android.os.ParcelFileDescriptor
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/ParcelFileDescriptor.java#ParcelFileDescriptor
*/

// [ ] done
// TFS ID: 785

#include "OsIndependentParcelable.h"
#include "..\javastuff\Cloneable.h"

// public class  [More ...] ParcelFileDescriptor implements Parcelable, Closeable {
class OsIndependentParcelFileDescriptor : public OsIndependentParcelable, public Cloneable
{
private:
  OsIndependentParcelFileDescriptor();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------------+  creates   +-----------------------------------+
| OsIndependentParcelFileDescriptor  |<-----------|    FactoryParcelFileDescriptor    |
+------------------------------------+            +-----------------------------------+
                  ^                                                 ^                Plattform independent code
                 /|\                                               /|\
                  |                                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  |                                                 |
                  |                                                 |                Plattform specific code
                  |                                                 |
+------------------------------------+  creates   +-----------------------------------+
|     Tizen-ParcelFileDescriptor     |<-----------| TizenFactoryParcelFileDescriptor  |
+------------------------------------+            +-----------------------------------+
*/
class FactoryParcelFileDescriptor
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryParcelFileDescriptor* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryParcelFileDescriptor* plattformSpecific) { FactoryParcelFileDescriptor::instance = plattformSpecific; }
  static FactoryParcelFileDescriptor* GetInstance()
  {
    if (FactoryParcelFileDescriptor::instance == nullptr)
      throw;
    return FactoryParcelFileDescriptor::instance;
  }
  // interface
  virtual OsIndependentParcelFileDescriptor* CreateNewParcelFileDescriptor() = 0;
};
