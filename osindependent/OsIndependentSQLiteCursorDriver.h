#pragma once
/*
  abstract class OsIndependentSQLiteCursorDriver to replace  android.database.sqlite.SQLiteCursorDriver
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteCursorDriver.java#SQLiteCursorDriver
*/

// [x] done
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
