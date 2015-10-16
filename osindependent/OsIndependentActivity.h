#pragma once
/*
  abstract class OsIndependentCursor to replace android.app.Activity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/app/Activity.java#Activity
*/

// [ ] done
// TFS ID: 664

#include "OsIndependentString.h"
#include "OsIndependentIntent.h"
#include "OsIndependentBundle.h"
#include "OsIndependentKeyEvent.h"

/*
public class Activity extends ContextThemeWrapper
implements LayoutInflater.Factory2,
Window.Callback, KeyEvent.Callback,
OnCreateContextMenuListener, ComponentCallbacks2,
Window.OnWindowDismissedCallback
*/
class OsIndependentActivity
{
public:
  static const OsIndependentString* WINDOW_SERVICE;
  static const OsIndependentString* CONNECTIVITY_SERVICE;
  static const int RESULT_OK = -1;
public:
  //@Override
  // TODO -> ContextThemeWrapper
  virtual void SetTheme(int resid) = 0; // { mBase.setTheme(resid); }
  virtual void Finish() = 0; // { finish(false); }
  /*
  actually private
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/app/Activity.java#Activity.finish%28boolean%29
  */
  virtual void Finish(bool finishTask) = 0;
  virtual void StartActivity(OsIndependentIntent* intent) = 0; // { this.startActivity(intent, null); }
  /*
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/app/Activity.java#Activity.overridePendingTransition%28int%2Cint%29
  */
  virtual void OverridePendingTransition(int enterAnim, int exitAnim) = 0;
  virtual OsIndependentIntent* GetIntent() = 0;
  virtual void OnCreate(OsIndependentBundle* savedInstanceState) = 0;
  //public boolean[More ...] onKeyUp(int keyCode, KeyEvent event) {
  virtual bool OnKeyUp(int keyCode, OsIndependentKeyEvent* event) = 0;
  virtual void OpenOptionsMenu() = 0;
  virtual void SetContentView(int layoutResID) = 0;
  // public final void  [More ...] setResult(int resultCode, Intent data) {
  virtual void SetResult(int resultCode, OsIndependentIntent* data) = 0;
};

const OsIndependentString* OsIndependentActivity::WINDOW_SERVICE = FactoryString::GetInstance()->CreateNewString("window");
const OsIndependentString* OsIndependentActivity::CONNECTIVITY_SERVICE = FactoryString::GetInstance()->CreateNewString("connectivity");

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------+  creates   +----------------------------+
| OsIndependentActivity       |<-----------|    FactoryActivity         |
+-----------------------------+            +----------------------------+
              ^                                          ^                Plattform independent code
             /|\                                        /|\
              |                                          |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                          |
              |                                          |                Plattform specific code
              |                                          |
+-----------------------------+  creates   +----------------------------+
|     Tizen-Activity          |<-----------| TizenFactoryActivity       |
+-----------------------------+            +----------------------------+


*/
class FactoryActivity
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryActivity* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryActivity* plattformSpecific) { FactoryActivity::instance = plattformSpecific; }
  static FactoryActivity* GetInstance()
  {
    if (FactoryActivity::instance == nullptr)
      throw;
    return FactoryActivity::instance;
  }
  // interface
  virtual OsIndependentActivity* CreateNewActivity() = 0;
};
