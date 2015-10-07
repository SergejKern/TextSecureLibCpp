#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.Uri
  http://developer.android.com/reference/android/net/Uri.html
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/Uri.java#Uri
*/

// [ ] done
// TFS ID: 327

#include "..\Factory\Factory.h"

// public abstract class  [More ...] Uri implements Parcelable, Comparable<Uri> {
class OsIndependentUri : OsIndependentParcelable
{
private:
public:
  //public static Uri parse(String uriString) {
  virtual OsIndependentUri* Parse(unsigned char* uriString) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentUri     |<-----------|    FactoryUri       |
+----------------------+            +---------------------+
          ^                                   ^                Plattform independent code
         /|\                                 /|\
          |                                   |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
          |                                   |
          |                                   |                Plattform specific code
          |                                   |
+----------------------+  creates   +---------------------+
|     Tizen-Uri        |<-----------| TizenFactoryUri     |
+----------------------+            +---------------------+
*/
class FactoryUri
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryUri* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryUri* plattformSpecific) { FactoryUri::instance = plattformSpecific; }
  static FactoryUri* GetInstance()
  {
    if (FactoryUri::instance == nullptr)
      throw;
    return FactoryUri::instance;
  }
  // interface
  virtual OsIndependentUri* CreateNewUri() = 0;
};
