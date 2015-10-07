#pragma once
/*
  abstract class OsIndependentSyncResult to replace android.content.SyncResult
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/SyncResult.java#SyncResult
*/

// [ ] done
// TFS ID: 686

#include "..\Factory\Factory.h"

// public class Account implements Parcelable {
class OsIndependentSyncResult : OsIndependentParcelable
{
private:
  OsIndependentSyncResult();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-------------------------+  creates   +------------------------+
| OsIndependentSyncResult |<-----------|    FactorySyncResult   |
+-------------------------+            +------------------------+
            ^                                      ^                Plattform independent code
           /|\                                    /|\
            |                                      |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                      |
            |                                      |                Plattform specific code
            |                                      |
+-------------------------+  creates   +------------------------+
|     Tizen-SyncResult    |<-----------| TizenFactorySyncResult |
+-------------------------+            +------------------------+
*/
class FactorySyncResult
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySyncResult* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySyncResult* plattformSpecific) { FactorySyncResult::instance = plattformSpecific; }
  static FactorySyncResult* GetInstance()
  {
    if (FactorySyncResult::instance == nullptr)
      throw;
    return FactorySyncResult::instance;
  }
  // interface
  virtual OsIndependentSyncResult* CreateNewSyncResult() = 0;
};
