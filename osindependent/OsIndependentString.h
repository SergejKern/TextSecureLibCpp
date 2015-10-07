#pragma once
/*
  abstract class OsIndependentIntent to replace java.lang.String
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/lang/String.java#String
*/

// [ ] done
// TFS ID: 687

#include "..\Factory\Factory.h"
#include "..\owntemplates\ArrayList.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class OsIndependentString
{
private:
public:
  virtual bool StartsWith(OsIndependentString*) = 0;
  virtual ArrayList<OsIndependentString*>* Split(OsIndependentString*, int) = 0;
  virtual ArrayList<OsIndependentString*>* Split(const char*, int) = 0;
  virtual OsIndependentString* Trim() = 0;
  virtual bool IsEmpty() = 0;
  virtual ArrayList<char>* GetBytes() = 0;
  virtual OsIndependentString* Append(OsIndependentString*) = 0;
};

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------+  creates   +--------------------+
| OsIndependentString |<-----------|    FactoryString   |
+---------------------+            +--------------------+
^                                 ^                Plattform independent code
/|\                               /|\
|                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|                                 |
|                                 |                Plattform specific code
|                                 |
+---------------------+  creates   +--------------------+
|     Tizen-String    |<-----------| TizenFactoryString |
+---------------------+            +--------------------+


*/
/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class FactoryString
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryString* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryString* plattformSpecific) { FactoryString::instance = plattformSpecific; }
  static FactoryString* GetInstance()
  {
    if (FactoryString::instance == nullptr)
      throw;
    return FactoryString::instance;
  }
  // interface
  virtual OsIndependentString* CreateNewString() = 0;
  virtual OsIndependentString* CreateNewString(unsigned char*) = 0;
  virtual OsIndependentString* CreateNewString(char*) = 0;
  virtual OsIndependentString* CreateNewString(long) = 0;
};
