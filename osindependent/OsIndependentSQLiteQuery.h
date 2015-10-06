#pragma once
/*
  abstract class OsIndependentContentValues to replace  android.database.sqlite.SQLiteQuery
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteQuery.java#SQLiteQuery
*/

// [ ] done
// TFS ID: 782

#include "..\Factory\Factory.h"
#include "OsIndependentSQLiteProgram.h"

// public final class  [More ...] SQLiteQuery extends SQLiteProgram {
class OsIndependentSQLiteQuery : public OsIndependentSQLiteProgram
{
private:
public:
  
};
