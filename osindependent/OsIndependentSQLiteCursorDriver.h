#pragma once
/*
  abstract class OsIndependentSQLiteCursorDriver to replace  android.database.sqlite.SQLiteCursorDriver
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteCursorDriver.java#SQLiteCursorDriver
*/

// [ ] done
// TFS ID: 781

#include "..\Factory\Factory.h"

// public interface  [More ...] SQLiteCursorDriver {
class OsIndependentSQLiteCursorDriver
{
private:
  /*
  Executes the query returning a Cursor over the result set.
  Parameters:
  factory -> The CursorFactory to use when creating the Cursors, or null if standard SQLiteCursors should be returned.
  Returns:
  a Cursor over the result set
  */
  virtual OsIndependentCursor* Query(OsIndependentSQLiteDatabase::CursorFactory* factory, List<OsIndependentString*>* bindArgs) = 0;
  /* Called by a SQLiteCursor when it is released. */
  virtual void CursorDeactivated() = 0;
  /* Called by a SQLiteCursor when it is requeried. */
  virtual void CursorRequeried(OsIndependentCursor* cursor) = 0;
  /* Called by a SQLiteCursor when it it closed to destroy this object as well. */
  virtual void CursorClosed() = 0;
public:
  /*
  Set new bind arguments. These will take effect in CursorRequeried().
  Parameters:
  bindArgs -> the new arguments
  */
  virtual void SetBindArguments(List<OsIndependentString*>* bindArgs) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------------+  creates   +--------------------------------+
| OsIndependentSQLiteCursorDriver |<-----------|    FactorySQLiteCursorDriver   |
+---------------------------------+            +--------------------------------+
                ^                                               ^                Plattform independent code
               /|\                                             /|\
                |                                               |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                |                                               |
                |                                               |                Plattform specific code
                |                                               |
+---------------------------------+  creates   +--------------------------------+
|     Tizen-SQLiteCursorDriver    |<-----------| TizenFactorySQLiteCursorDriver |
+---------------------------------+            +--------------------------------+


*/
class FactorySQLiteCursorDriver
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySQLiteCursorDriver* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySQLiteCursorDriver* plattformSpecific) { FactorySQLiteCursorDriver::instance = plattformSpecific; }
  static FactorySQLiteCursorDriver* GetInstance()
  {
    if (FactorySQLiteCursorDriver::instance == nullptr)
      throw;
    return FactorySQLiteCursorDriver::instance;
  }
  // interface
  virtual OsIndependentSQLiteCursorDriver* CreateNewCursorDriver() = 0;
};
