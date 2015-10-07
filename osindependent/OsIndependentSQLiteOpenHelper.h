#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteOpenHelper
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteOpenHelper.java#SQLiteOpenHelper
*/

// [ ] done
// TFS ID: 662

#include "..\Factory\Factory.h"
// public abstract class  [More ...] SQLiteOpenHelper {
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
needs no Factory, because is abstract
*/
