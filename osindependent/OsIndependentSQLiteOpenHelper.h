#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteOpenHelper
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteOpenHelper.java#SQLiteOpenHelper
*/

// [ ] done
// TFS ID: 662

#include "..\Factory\Factory.h"

class OsIndependentSQLiteOpenHelper
{
private:
public:
  OsIndependentSQLiteOpenHelper(
    OsIndependentContext* context, 
    OsIndependentString* name, 
    OsIndependentSQLiteDatabase::CursorFactory* factory,
    int version)
  { };
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/database/Cursor.html#moveToNext%28%29
  */
  virtual void OnCreate(OsIndependentSQLiteDatabase* db) = 0;
  virtual void OnUpgrade(OsIndependentSQLiteDatabase* db, int oldVersion, int newVersion) = 0;
  virtual OsIndependentSQLiteDatabase* GetWritableDatabase() = 0;
  virtual OsIndependentSQLiteDatabase* GetReadableDatabase() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-------------------------------+            +------------------------------+
| OsIndependentSQLiteOpenHelper |<-----------|    FactorySQLiteOpenHelper   |
+-------------------------------+            +------------------------------+
               ^                                             ^                Plattform independent code
              /|\                                           /|\
               |                                             |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                             |
               |                                             |                Plattform specific code
               |                                             |
+-------------------------------+            +------------------------------+
|     Tizen-SQLiteOpenHelper    |<-----------| TizenFactorySQLiteOpenHelper |
+-------------------------------+            +------------------------------+


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
