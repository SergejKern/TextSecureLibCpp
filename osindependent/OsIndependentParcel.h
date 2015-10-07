#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.Parcel
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Parcel.java#Parcel
*/

// [ ] done
// TFS ID: 329

#include "..\Factory\Factory.h"

class OsIndependentParcel
{
private:
  OsIndependentParcel();
public:
  virtual OsIndependentParcel* Obtain() = 0;
  // returns byte[]
  virtual char* Marshall() = 0;
  virtual char* Unmarshall(char* buffer, int offset, int len) = 0;
  virtual void Recycle() = 0;
  virtual void SetDataPosition(int pos) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentParcel  |<-----------|    FactoryParcel    |
+----------------------+            +---------------------+
            ^                                  ^                Plattform independent code
           /|\                                /|\
            |                                  |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                  |
            |                                  |                Plattform specific code
            |                                  |
+----------------------+  creates   +---------------------+
|     Tizen-Parcel     |<-----------| TizenFactoryParcel  |
+----------------------+            +---------------------+
*/
class FactoryParcel
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryParcel* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryParcel* plattformSpecific) { FactoryParcel::instance = plattformSpecific; }
  static FactoryParcel* GetInstance()
  {
    if (FactoryParcel::instance == nullptr)
      throw;
    return FactoryParcel::instance;
  }
  // interface
  virtual OsIndependentParcel* CreateNewParcel() = 0;
};
