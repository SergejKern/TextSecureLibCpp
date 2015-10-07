#pragma once
/*
  abstract class OsIndependentCursor to replace android.support.v4.app.FragmentActivity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/support/v4/app/FragmentActivity.java#FragmentActivity
*/

// [ ] done
// TFS ID: 756

#include "..\Factory\Factory.h"

/*
public class  [More ...] FragmentActivity extends Activity {
*/
class OsIndependentFragmentActivity : public OsIndependentActivity
{
public:
public:
  // public boolean  [More ...] onKeyDown(int keyCode, KeyEvent event) {
  virtual bool OnKeyDown(int keyCode, OsIndependentKeyEvent* event) = 0;
  //public FragmentManager[More ...] getSupportFragmentManager() {
  virtual OsIndependentFragmentManager* GetSupportFragmentManager() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-------------------------------+  creates   +------------------------------+
| OsIndependentFragmentActivity |<-----------|    FactoryFragmentActivity   |
+-------------------------------+            +------------------------------+
                ^                                            ^                Plattform independent code
               /|\                                          /|\
                |                                            |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                |                                            |
                |                                            |                Plattform specific code
                |                                            |
+-------------------------------+  creates   +------------------------------+
|     Tizen-FragmentActivity    |<-----------| TizenFactoryFragmentActivity |
+-------------------------------+            +------------------------------+
*/
class FactoryFragmentActivity
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryFragmentActivity* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryFragmentActivity* plattformSpecific) { FactoryFragmentActivity::instance = plattformSpecific; }
  static FactoryFragmentActivity* GetInstance()
  {
    if (FactoryFragmentActivity::instance == nullptr)
      throw;
    return FactoryFragmentActivity::instance;
  }
  // interface
  virtual OsIndependentFragmentActivity* CreateNewFragmentActivity() = 0;
};
