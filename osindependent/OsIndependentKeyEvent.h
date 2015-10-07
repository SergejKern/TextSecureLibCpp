#pragma once
/*
  abstract class OsIndependentCursor to replace android.support.v4.app.FragmentActivity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/support/v4/app/FragmentActivity.java#FragmentActivity
*/

// [ ] done
// TFS ID: 757

#include "..\Factory\Factory.h"

/*
public class  [More ...] KeyEvent extends InputEvent implements Parcelable {
*/
class OsIndependentKeyEvent : public OsIndependentParcelable
{
private:
  OsIndependentKeyEvent();
public:
  // TODO REFACTOR
  static const int KEYCODE_MENU = 82;
public:

};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------+  creates   +----------------------+
| OsIndependentKeyEvent |<-----------|    FactoryKeyEvent   |
+-----------------------+            +----------------------+
           ^                                    ^                Plattform independent code
          /|\                                  /|\
           |                                    |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                    |
           |                                    |                Plattform specific code
           |                                    |
+-----------------------+  creates   +----------------------+
|     Tizen-KeyEvent    |<-----------| TizenFactoryKeyEvent |
+-----------------------+            +----------------------+
*/
class FactoryKeyEvent
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryKeyEvent* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryKeyEvent* plattformSpecific) { FactoryKeyEvent::instance = plattformSpecific; }
  static FactoryKeyEvent* GetInstance()
  {
    if (FactoryKeyEvent::instance == nullptr)
      throw;
    return FactoryKeyEvent::instance;
  }
  // interface
  virtual OsIndependentKeyEvent* CreateNewKeyEvent() = 0;
};
