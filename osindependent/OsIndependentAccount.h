#pragma once
/*
  abstract class OsIndependentCursor to replace android.accounts.Account
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/accounts/Account.java#Account
*/

// [ ] done
// TFS ID: 683

#include "OsIndependentParcelable.h"

// public class Account implements Parcelable {
class OsIndependentAccount : public OsIndependentParcelable
{
private:
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------+  creates   +----------------------------+
| OsIndependentAccount        |<-----------|    FactoryAccount          |
+-----------------------------+            +----------------------------+
             ^                                          ^                Plattform independent code
            /|\                                        /|\
             |                                          |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                          |
             |                                          |                Plattform specific code
             |                                          |
+-----------------------------+  creates   +----------------------------+
|     Tizen-Account           |<-----------| TizenFactoryAccount        |
+-----------------------------+            +----------------------------+
*/
class FactoryAccount
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryAccount* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryAccount* plattformSpecific) { FactoryAccount::instance = plattformSpecific; }
  static FactoryAccount* GetInstance()
  {
    if (FactoryAccount::instance == nullptr)
      throw;
    return FactoryAccount::instance;
  }
  // interface
  virtual OsIndependentAccount* CreateNewAccount() = 0;
};
