#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.res.Resources
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/res/Resources.java#Resources
*/

// [ ] done
// TFS ID: 675

#include "..\Factory\Factory.h"

/*
public class Resources {
*/
class OsIndependentResources
{
public:
  // http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/res/Resources.java#Resources.Theme
  // public final class  [More ...] Theme {
  class Theme
  { };
public:
  //@Deprecated
  //@Nullable
  // public Drawable getDrawable(int id) throws NotFoundException {
  virtual OsIndependentDrawable* GetDrawable(int id) = 0;
  // @Nullable
  //public Drawable[More ...] getDrawable(int id, @Nullable Theme theme) throws NotFoundException{
  virtual OsIndependentDrawable* GetDrawable(int id, Theme* theme) = 0;
  virtual OsIndependentInputStream* OpenRawResource(int id) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------+  creates   +-----------------------+
| OsIndependentResources |<-----------|    FactoryResources   |
+------------------------+            +-----------------------+
            ^                                    ^                Plattform independent code
           /|\                                  /|\
            |                                    |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                    |
            |                                    |                Plattform specific code
            |                                    |
+------------------------+  creates   +-----------------------+
|     Tizen-Resources    |<-----------| TizenFactoryResources |
+------------------------+            +-----------------------+
*/
class FactoryResources
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryResources* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryResources* plattformSpecific) { FactoryResources::instance = plattformSpecific; }
  static FactoryResources* GetInstance()
  {
    if (FactoryResources::instance == nullptr)
      throw;
    return FactoryResources::instance;
  }
  // interface
  virtual OsIndependentResources* CreateNewResources() = 0;
};
