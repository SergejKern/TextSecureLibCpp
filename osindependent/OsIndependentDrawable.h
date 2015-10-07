#pragma once
/*
  abstract class OsIndependentCursor to replace android.graphics.drawable.Drawable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/graphics/drawable/Drawable.java#Drawable
*/

// [ ] done
// TFS ID: 674

#include "..\Factory\Factory.h"

/*
public abstract class Drawable {
*/
class OsIndependentDrawable
{
private:
  OsIndependentDrawable();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------+  creates   +----------------------+
| OsIndependentDrawable |<-----------|    FactoryDrawable   |
+-----------------------+            +----------------------+
           ^                                    ^                Plattform independent code
          /|\                                  /|\
           |                                    |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                    |
           |                                    |                Plattform specific code
           |                                    |
+-----------------------+  creates   +----------------------+
|     Tizen-Drawable    |<-----------| TizenFactoryDrawable |
+-----------------------+            +----------------------+
*/
class FactoryDrawable
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryDrawable* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryDrawable* plattformSpecific) { FactoryDrawable::instance = plattformSpecific; }
  static FactoryDrawable* GetInstance()
  {
    if (FactoryDrawable::instance == nullptr)
      throw;
    return FactoryDrawable::instance;
  }
  // interface
  virtual OsIndependentDrawable* CreateNewDrawable() = 0;
};
