#pragma once
/*
  abstract class OsIndependentContentValues to replace android.database.sqlite.SQLiteProgram
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteProgram.java#SQLiteProgram
*/

// [ ] done
// TFS ID: 783

#include "OsIndependentSQLiteClosable.h"

// public abstract class  [More ...] SQLiteProgram extends SQLiteClosable {
class OsIndependentSQLiteProgram : public OsIndependentSQLiteClosable
{
private:
  OsIndependentSQLiteProgram();
public:
  
};
/*
needs no Factory, because is abstract
*/
