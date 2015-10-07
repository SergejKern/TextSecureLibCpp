#pragma once
/*
  abstract class OsIndependentCursor to replace android.view.WindowManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/view/WindowManager.java#WindowManager
*/

// [ ] done
// TFS ID: 673

#include "..\Factory\Factory.h"

// done [ ]
// public interface  [More ...] ViewManager
// public abstract class  [More ...] ViewGroup extends View implements ViewParent, ViewManager {
// public class  [More ...] View implements Drawable.Callback, KeyEvent.Callback, AccessibilityEventSource{
class OsIndependentViewManager
{
public:
  //void[More ...] addView(View view, ViewGroup.LayoutParams params);
  virtual void AddView() = 0;
  //void[More ...] updateViewLayout(View view, ViewGroup.LayoutParams params);
  virtual void UpdateViewLayout() = 0;
  //void[More ...] removeView(View view);
  virtual void RemoveView() = 0;
};

// public interface  [More ...] WindowManager extends ViewManager {
class OsIndependentWindowManager : public OsIndependentViewManager
{
private:
  OsIndependentWindowManager();
public:
};
/*
needs no Factory, because is an interface
*/
