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

#include "..\osindependent\OsIndependentSQLiteOpenHelper.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class FactorySQLiteOpenHelper
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteOpenHelper* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteOpenHelper* plattformSpecific) { FactorySQLiteOpenHelper::instance = plattformSpecific; }
  static FactorySQLiteOpenHelper* GetInstance()
  {
    if (FactorySQLiteOpenHelper::instance == nullptr)
      throw;
    return FactorySQLiteOpenHelper::instance;
  }
  // interface
  virtual OsIndependentSQLiteOpenHelper* CreateNewHelper(
    OsIndependentContext*, OsIndependentString*) = 0;
  virtual OsIndependentSQLiteOpenHelper* CreateNewHelper
    (OsIndependentContext* context, OsIndependentString* name, 
    OsIndependentSQLiteDatabase::CursorFactory* factory, int version) = 0;
};
