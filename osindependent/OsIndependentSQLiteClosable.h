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
