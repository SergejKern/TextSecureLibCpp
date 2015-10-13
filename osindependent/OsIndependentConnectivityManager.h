#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.ConnectivityManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/ConnectivityManager.java#ConnectivityManager
*/

// [ ] done
// TFS ID: 672

#include "..\Factory\Factory.h"

class OsIndependentConnectivityManager
{
public:
  static const OsIndependentString* CONNECTIVITY_ACTION;
public:
  virtual OsIndependentNetworkInfo* GetActiveNetworkInfo() = 0;
};

const OsIndependentString* OsIndependentConnectivityManager::CONNECTIVITY_ACTION = FactoryString::GetInstance()->CreateNewString("android.net.conn.CONNECTIVITY_CHANGE");
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------------------+  creates   +---------------------------------+
| OsIndependentConnectivityManager |<-----------|    FactoryConnectivityManager   |
+----------------------------------+            +---------------------------------+
                ^                                                 ^                Plattform independent code
               /|\                                               /|\
                |                                                 | 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                |                                                 |
                |                                                 |                Plattform specific code
                |                                                 |
+----------------------------------+  creates   +---------------------------------+
|     Tizen-ConnectivityManager    |<-----------| TizenFactoryConnectivityManager |
+----------------------------------+            +---------------------------------+
*/
class FactoryConnectivityManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryConnectivityManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryConnectivityManager* plattformSpecific) { FactoryConnectivityManager::instance = plattformSpecific; }
  static FactoryConnectivityManager* GetInstance()
  {
    if (FactoryConnectivityManager::instance == nullptr)
      throw;
    return FactoryConnectivityManager::instance;
  }
  // interface
  virtual OsIndependentConnectivityManager* CreateNewConnectivityManager() = 0;
};
