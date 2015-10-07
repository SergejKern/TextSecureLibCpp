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
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------------+  creates   +---------------------------+
| OsIndependentWindowManager |<-----------|    FactoryWindowManager   |
+----------------------------+            +---------------------------+
               ^                                        ^                Plattform independent code
              /|\                                      /|\
               |                                        |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                        |
               |                                        |                Plattform specific code
               |                                        |
+----------------------------+  creates   +---------------------------+
|     Tizen-WindowManager    |<-----------| TizenFactoryWindowManager |
+----------------------------+            +---------------------------+
*/
class FactoryWindowManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryWindowManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryWindowManager* plattformSpecific) { FactoryWindowManager::instance = plattformSpecific; }
  static FactoryWindowManager* GetInstance()
  {
    if (FactoryWindowManager::instance == nullptr)
      throw;
    return FactoryWindowManager::instance;
  }
  // interface
  virtual OsIndependentWindowManager* CreateNewWindowManager() = 0;
};
