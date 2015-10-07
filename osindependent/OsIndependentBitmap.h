#pragma once
/*
  abstract class OsIndependentCursor to replace  android.graphics.Bitmap
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/graphics/Bitmap.java#Bitmap
*/

// [ ] done
// TFS ID: 679

#include "..\Factory\Factory.h"

/*
public final class Bitmap implements Parcelable {
*/
class OsIndependentBitmap : OsIndependentParcelable
{
public:
  OsIndependentBitmap();
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentBitmap  |<-----------|    FactoryBitmap    |
+----------------------+            +---------------------+
            ^                                 ^                Plattform independent code
           /|\                               /|\
            |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            |                                 |
            |                                 |                Plattform specific code
            |                                 |
+----------------------+  creates   +---------------------+
|     Tizen-Bitmap     |<-----------| TizenFactoryBitmap  |
+----------------------+            +---------------------+
*/
class FactoryBitmap
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryBitmap* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryBitmap* plattformSpecific) { FactoryBitmap::instance = plattformSpecific; }
  static FactoryBitmap* GetInstance()
  {
    if (FactoryBitmap::instance == nullptr)
      throw;
    return FactoryBitmap::instance;
  }
  // interface
  virtual OsIndependentBitmap* CreateNewBitmap() = 0;
};
