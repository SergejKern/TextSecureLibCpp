#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.Parcelable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Parcelable.java#Parcelable
*/

// [ ] done
// TFS ID: 663

#include "..\Factory\Factory.h"

class OsIndependentParcelable
{
private:
  OsIndependentParcelable();
public:  
  virtual void WriteToParcel(OsIndependentParcel* parcel, int len) = 0;
  template <typename T> class Creator<T>
  {
  public:
    virtual T* CreateFromParcel(OsIndependentParcel* source) = 0;
    virtual T[] NewArray(int size) = 0;
  };
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-------------------------+  creates   +------------------------+
| OsIndependentParcelable |<-----------|    FactoryParcelable   |
+-------------------------+            +------------------------+
             ^                                      ^                Plattform independent code
            /|\                                    /|\
             |                                      |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                      |
             |                                      |                Plattform specific code
             |                                      |
+-------------------------+  creates   +------------------------+
|     Tizen-Parcelable    |<-----------| TizenFactoryParcelable |
+-------------------------+            +------------------------+
*/
class FactoryParcelable
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryParcelable* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryParcelable* plattformSpecific) { FactoryParcelable::instance = plattformSpecific; }
  static FactoryParcelable* GetInstance()
  {
    if (FactoryParcelable::instance == nullptr)
      throw;
    return FactoryParcelable::instance;
  }
  // interface
  virtual OsIndependentParcelable* CreateNewParcelable() = 0;
};
