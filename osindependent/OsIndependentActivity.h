#pragma once
/*
  abstract class OsIndependentCursor to replace android.app.Activity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/app/Activity.java#Activity
*/

// [ ] done
// TFS ID: 664

#include "OsIndependentIntent.h"
#include "OsIndependentBundle.h"

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
  static const unsigned char* WINDOW_SERVICE;
  static const unsigned char* CONNECTIVITY_SERVICE;
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
};

const unsigned char* OsIndependentActivity::WINDOW_SERVICE = "window";
const unsigned char* OsIndependentActivity::CONNECTIVITY_SERVICE = "connectivity";
