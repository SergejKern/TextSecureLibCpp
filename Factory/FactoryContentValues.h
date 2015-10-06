#pragma once
/*
*/

// [x] done
// TFS ID: none

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

#include "..\osindependent\OsIndependentContentValues.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class FactoryContentValues
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryContentValues* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryContentValues* plattformSpecific) { FactoryContentValues::instance = plattformSpecific; }
  static FactoryContentValues* GetInstance()
  {
    if (FactoryContentValues::instance == nullptr)
      throw;
    return FactoryContentValues::instance;
  }
  // interface
  virtual OsIndependentContentValues* CreateNewContentValues() = 0;
};
