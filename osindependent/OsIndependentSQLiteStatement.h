#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteStatement
  http://developer.android.com/reference/android/content/SQLiteStatement.html
*/

// [x] done
// TFS ID: 660

#include "OsIndependentString.h"
#include "OsIndependentSQLiteProgram.h"
#include "OsIndependentParcelFileDescriptor.h"
#include <list>

// public final class  [More ...] SQLiteStatement extends SQLiteProgram {
class OsIndependentSQLiteStatement : public OsIndependentSQLiteProgram
{
private:
public:
  //public void[More ...] execute() {
  virtual void Execute() = 0;
  //public long[More ...] executeInsert() {
  virtual long ExecuteInsert() = 0;
  //public int[More ...] executeUpdateDelete() {
  virtual int ExecuteUpdateDelete() = 0;
  //public ParcelFileDescriptor  [More ...] simpleQueryForBlobFileDescriptor() {
  virtual OsIndependentParcelFileDescriptor* SimpleQueryForBlobFileDescriptor() = 0;
  //public long[More ...] simpleQueryForLong() {
  virtual long SimpleQueryForLong() = 0;
  //public String[More ...] simpleQueryForString() {
  virtual OsIndependentString* SimpleQueryForString() = 0;
  //public String  [More ...] toString() {
  virtual OsIndependentString* ToString() = 0;
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
  virtual OsIndependentSQLiteStatement* CreateNewStatement(OsIndependentSQLiteDatabase* db, OsIndependentString* sql, std::list<void*>* bindArgs) = 0;
};
