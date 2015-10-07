#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.NetworkInfo
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/NetworkInfo.java#NetworkInfo
*/

// [ ] done
// TFS ID: 768

#include "..\Factory\Factory.h"

/*
public class  [More ...] NetworkInfo implements Parcelable {
*/
class OsIndependentNetworkInfo : public OsIndependentParcelable
{
private:
public:
  virtual bool IsConnected() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+--------------------------+  creates   +-------------------------+
| OsIndependentNetworkInfo |<-----------|    FactoryNetworkInfo   |
+--------------------------+            +-------------------------+
            ^                                       ^                Plattform independent code
           /|\                                     /|\
            |                                       |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                       |
            |                                       |                Plattform specific code
            |                                       |
+--------------------------+  creates   +-------------------------+
|     Tizen-NetworkInfo    |<-----------| TizenFactoryNetworkInfo |
+--------------------------+            +-------------------------+
*/
class FactoryNetworkInfo
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryNetworkInfo* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryNetworkInfo* plattformSpecific) { FactoryNetworkInfo::instance = plattformSpecific; }
  static FactoryNetworkInfo* GetInstance()
  {
    if (FactoryNetworkInfo::instance == nullptr)
      throw;
    return FactoryNetworkInfo::instance;
  }
  // interface
  virtual OsIndependentNetworkInfo* CreateNewNetworkInfo() = 0;
};
