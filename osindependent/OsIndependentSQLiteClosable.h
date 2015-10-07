#pragma once
/*
  abstract class OsIndependentSQLiteClosable to replace android.database.sqlite.SQLiteClosable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteClosable.java#SQLiteClosable
*/

// [x] done
// TFS ID: 782

#include "..\Factory\Factory.h"
#include "..\javastuff\Closeable.h"

// public final class  [More ...] SQLiteQuery extends SQLiteProgram {
class OsIndependentSQLiteClosable : public Closeable
{
private:
public:
  virtual void AcquireReference() = 0;
  virtual void Close() = 0;
  virtual void ReleaseReference() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------+  creates   +----------------------------+
| OsIndependentSQLiteClosable |<-----------|    FactorySQLiteClosable   |
+-----------------------------+            +----------------------------+
               ^                                          ^                Plattform independent code
              /|\                                        /|\
               |                                          |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                          |
               |                                          |                Plattform specific code
               |                                          |
+-----------------------------+  creates   +----------------------------+
|     Tizen-SQLiteClosable    |<-----------| TizenFactorySQLiteClosable |
+-----------------------------+            +----------------------------+
*/
class FactorySQLiteClosable
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteClosable* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteClosable* plattformSpecific) { FactorySQLiteClosable::instance = plattformSpecific; }
  static FactorySQLiteClosable* GetInstance()
  {
    if (FactorySQLiteClosable::instance == nullptr)
      throw;
    return FactorySQLiteClosable::instance;
  }
  // interface
  virtual OsIndependentSQLiteClosable* CreateNewSQLiteClosable() = 0;
};
