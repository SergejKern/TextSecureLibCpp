#pragma once
/*
  abstract class OsIndependentCursor to replace android.view.inputmethod.InputMethodManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/view/inputmethod/InputMethodManager.java#InputMethodManager
*/

// [ ] done
// TFS ID: 671

#include "..\Factory\Factory.h"

// public final class  [More ...] InputMethodManager {
class OsIndependentInputMethodManager
{
private:
  OsIndependentInputMethodManager();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------------+  creates   +--------------------------------+
| OsIndependentInputMethodManager |<-----------|    FactoryInputMethodManager   |
+---------------------------------+            +--------------------------------+
                 ^                                              ^                Plattform independent code
                /|\                                            /|\
                 |                                              |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                 |                                              |
                 |                                              |                Plattform specific code
                 |                                              |
+---------------------------------+  creates   +--------------------------------+
|     Tizen-InputMethodManager    |<-----------| TizenFactoryInputMethodManager |
+---------------------------------+            +--------------------------------+
*/
class FactoryInputMethodManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryInputMethodManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryInputMethodManager* plattformSpecific) { FactoryInputMethodManager::instance = plattformSpecific; }
  static FactoryInputMethodManager* GetInstance()
  {
    if (FactoryInputMethodManager::instance == nullptr)
      throw;
    return FactoryInputMethodManager::instance;
  }
  // interface
  virtual OsIndependentInputMethodManager* CreateNewInputMethodManager() = 0;
};
