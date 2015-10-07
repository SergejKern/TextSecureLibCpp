#pragma once
/*
  abstract class OsIndependentContentValues to replace android.database.sqlite.SQLiteProgram
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteProgram.java#SQLiteProgram
*/

// [ ] done
// TFS ID: 783

#include "..\Factory\Factory.h"

// public final class  [More ...] SQLiteQuery extends SQLiteProgram {
class OsIndependentSQLiteProgram : public OsIndependentSQLiteClosable
{
private:
public:
  
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------------+  creates   +---------------------------+
| OsIndependentSQLiteProgram |<-----------|    FactorySQLiteProgram   |
+----------------------------+            +---------------------------+
              ^                                 ^                Plattform independent code
             /|\                               /|\
              |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                 |
              |                                 |                Plattform specific code
              |                                 |
+----------------------------+  creates   +---------------------------+
|     Tizen-SQLiteProgram    |<-----------| TizenFactorySQLiteProgram |
+----------------------------+            +---------------------------+
*/
class FactorySQLiteProgram
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteProgram* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteProgram* plattformSpecific) { FactorySQLiteProgram::instance = plattformSpecific; }
  static FactorySQLiteProgram* GetInstance()
  {
    if (FactorySQLiteProgram::instance == nullptr)
      throw;
    return FactorySQLiteProgram::instance;
  }
  // interface
  virtual OsIndependentSQLiteProgram* CreateNewSQLiteProgram() = 0;
};
