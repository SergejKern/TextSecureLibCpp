#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteDatabase
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteDatabase.java#SQLiteDatabase
*/

// [ ] done
// TFS ID: 659

#include "..\Factory\Factory.h"
/*
public final class  [More ...] SQLiteDatabase extends SQLiteClosable {
*/
class OsIndependentSQLiteDatabase : public OsIndependentSQLiteClosable
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
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------+  creates   +----------------------------+
| OsIndependentSQLiteDatabase |<-----------|    FactorySQLiteDatabase   |
+-----------------------------+            +----------------------------+
              ^                                          ^                Plattform independent code
             /|\                                        /|\
              |                                          |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                          |
              |                                          |                Plattform specific code
              |                                          |
+-----------------------------+  creates   +----------------------------+
|     Tizen-SQLiteDatabase    |<-----------| TizenFactorySQLiteDatabase |
+-----------------------------+            +----------------------------+


*/
class FactorySQLiteDatabase
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteDatabase* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteDatabase* plattformSpecific) { FactorySQLiteDatabase::instance = plattformSpecific; }
  static FactorySQLiteDatabase* GetInstance()
  {
    if (FactorySQLiteDatabase::instance == nullptr)
      throw;
    return FactorySQLiteDatabase::instance;
  }
  // interface
  virtual OsIndependentSQLiteDatabase* CreateNewDatabase() = 0;
};
