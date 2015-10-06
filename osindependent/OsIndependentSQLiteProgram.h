#pragma once
/*
  abstract class OsIndependentContentValues to replace android.database.sqlite.SQLiteProgram
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteProgram.java#SQLiteProgram
*/

// [ ] done
// TFS ID: 783

#include "..\Factory\Factory.h"
#include "OsIndependentSQLiteClosable.h"

// public final class  [More ...] SQLiteQuery extends SQLiteProgram {
class OsIndependentSQLiteProgram : public OsIndependentSQLiteClosable
{
private:
public:
  
};
