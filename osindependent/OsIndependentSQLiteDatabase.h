#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteDatabase
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteDatabase.java#SQLiteDatabase
*/

// [ ] done
// TFS ID: 659

#include "..\Factory\Factory.h"

class OsIndependentSQLiteDatabase
{
private:
public:
  // public interface[More ...] CursorFactory{
  class CursorFactory
  {
    virtual OsIndependentCursor* NewCursor(
      OsIndependentSQLiteDatabase* db, 
      OsIndependentSQLiteCursorDriver* masterQuery, 
      OsIndependentString* editTable, 
      OsIndependentSQLiteQuery* query) = 0;
  };
public:
  OsIndependentSQLiteDatabase() {};
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/database/Cursor.html#moveToNext%28%29
  */
  virtual void ExecSQL(OsIndependentString* sql) = 0; // throws SQLException
  virtual long Insert(OsIndependentString* table, 
    OsIndependentString* nullColumnHack, 
    OsIndependentContentValues* values) = 0;
  virtual OsIndependentCursor* Query(
    OsIndependentString* table, 
    List<OsIndependentString*>* columns,
    OsIndependentString* selection,
    List<OsIndependentString*>* selectionArgs,
    OsIndependentString* groupBy, 
    OsIndependentString* having,
    OsIndependentString* orderBy, 
    OsIndependentString* limit) = 0;
  virtual int Delete(
    OsIndependentString* table, 
    OsIndependentString* whereClause, 
    List<OsIndependentString*>* whereArgs) = 0;
};
