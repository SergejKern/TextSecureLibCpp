#pragma once
/*
  abstract class OsIndependentIntent to replace  java.lang.StringBuilder
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/lang/StringBuilder.java#StringBuilder
*/

// [ ] done
// TFS ID: 688

#include "..\Factory\Factory.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class OsIndependentStringBuilder
{
private:
public:
  virtual OsIndependentStringBuilder* Append(OsIndependentString* str) = 0;
  /* java.lang.AbstractStringBuilder.length()*/ 
  virtual int Length() = 0;
  virtual OsIndependentString* ToString() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------------+  creates   +---------------------------+
| OsIndependentStringBuilder |<-----------|    FactoryStringBuilder   |
+----------------------------+            +---------------------------+
              ^                                         ^                Plattform independent code
             /|\                                       /|\
              |                                         |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                         |
              |                                         |                Plattform specific code
              |                                         |
+----------------------------+  creates   +---------------------------+
|     Tizen-StringBuilder    |<-----------| TizenFactoryStringBuilder |
+----------------------------+            +---------------------------+
*/
class FactoryStringBuilder
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryStringBuilder* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryStringBuilder* plattformSpecific) { FactoryStringBuilder::instance = plattformSpecific; }
  static FactoryStringBuilder* GetInstance()
  {
    if (FactoryStringBuilder::instance == nullptr)
      throw;
    return FactoryStringBuilder::instance;
  }
  // interface
  virtual OsIndependentStringBuilder* CreateNewStringBuilder() = 0;
};
