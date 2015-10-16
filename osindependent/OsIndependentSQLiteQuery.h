#pragma once
/*
  abstract class OsIndependentContentValues to replace  android.database.sqlite.SQLiteQuery
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteQuery.java#SQLiteQuery
*/

// [ ] done
// TFS ID: 782

#include "OsIndependentSQLiteProgram.h"

// public final class  [More ...] SQLiteQuery extends SQLiteProgram {
class OsIndependentSQLiteQuery : public OsIndependentSQLiteProgram
{
private:
public:
  
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+--------------------------+  creates   +-------------------------+
| OsIndependentSQLiteQuery |<-----------|    FactorySQLiteQuery   |
+--------------------------+            +-------------------------+
             ^                                       ^                Plattform independent code
            /|\                                     /|\
             |                                       |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                       |
             |                                       |                Plattform specific code
             |                                       |
+--------------------------+  creates   +-------------------------+
|     Tizen-SQLiteQuery    |<-----------| TizenFactorySQLiteQuery |
+--------------------------+            +-------------------------+
*/
class FactorySQLiteQuery
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteQuery* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteQuery* plattformSpecific) { FactorySQLiteQuery::instance = plattformSpecific; }
  static FactorySQLiteQuery* GetInstance()
  {
    if (FactorySQLiteQuery::instance == nullptr)
      throw;
    return FactorySQLiteQuery::instance;
  }
  // interface
  virtual OsIndependentSQLiteQuery* CreateNewQuery() = 0;
};
