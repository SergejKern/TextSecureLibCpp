#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteStatement
  http://developer.android.com/reference/android/content/SQLiteStatement.html
*/

// [ ] done
// TFS ID: 660

#include "..\Factory\Factory.h"

class OsIndependentSQLiteStatement
{
private:
  OsIndependentSQLiteStatement();
public:  
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------+  creates   +-----------------------------+
| OsIndependentSQLiteStatement |<-----------|    FactorySQLiteStatement   |
+------------------------------+            +-----------------------------+
               ^                                           ^                Plattform independent code
              /|\                                         /|\
               |                                           |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                           |
               |                                           |                Plattform specific code
               |                                           |
+------------------------------+  creates   +-----------------------------+
|     Tizen-SQLiteStatement    |<-----------| TizenFactorySQLiteStatement |
+------------------------------+            +-----------------------------+
*/
class FactorySQLiteStatement
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteStatement* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteStatement* plattformSpecific) { FactorySQLiteStatement::instance = plattformSpecific; }
  static FactorySQLiteStatement* GetInstance()
  {
    if (FactorySQLiteStatement::instance == nullptr)
      throw;
    return FactorySQLiteStatement::instance;
  }
  // interface
  virtual OsIndependentSQLiteStatement* CreateNewStatement() = 0;
};
