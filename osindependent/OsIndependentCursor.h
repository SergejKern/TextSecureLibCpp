#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.Cursor
  http://developer.android.com/reference/android/database/Cursor.html
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/Cursor.java#Cursor
*/

// [ ] done
// TFS ID: 657

#include "..\Factory\Factory.h"
#include "..\javastuff\Closeable.h"

// public interface Cursor extends Closeable {
class OsIndependentCursor : public Closeable
{
private:
public:
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/database/Cursor.html#moveToNext%28%29
  */
  virtual bool MoveToNext() = 0;
  /*
  Returns the numbers of rows in the cursor.
  http://developer.android.com/reference/android/database/Cursor.html#getCount%28%29
  */
  virtual int GetCount() = 0;
  /*
  Returns the value of the requested column as a long.
  The result and whether this method throws an exception when the column value is null, the column type is not an integral type, or the integer value is outside the range [Long.MIN_VALUE, Long.MAX_VALUE] is implementation-defined.
  http://developer.android.com/reference/android/database/Cursor.html#getLong%28int%29
  */
  virtual long GetLong(int columnIndex) = 0;
  /*
  Returns the value of the requested column as a String.
  The result and whether this method throws an exception when the column value is null or the column type is not a string type is implementation-defined.
  http://developer.android.com/reference/android/database/Cursor.html#getString%28int%29
  */
  virtual OsIndependentString* GetString(int columnIndex) = 0;
  /*
  Returns the value of the requested column as an int.
  The result and whether this method throws an exception when the column value is null, the column type is not an integral type, or the integer value is outside the range [Integer.MIN_VALUE, Integer.MAX_VALUE] is implementation-defined.
  http://developer.android.com/reference/android/database/Cursor.html#getInt%28int%29
  */
  virtual int GetInt(int columnIndex) = 0;
  /*
  Returns the zero-based index for the given column name, or throws IllegalArgumentException if the column doesn't exist. If you're not sure if a column will exist or not use getColumnIndex(String) and check for -1, which is more efficient than catching the exceptions.
  http://developer.android.com/reference/android/database/Cursor.html#getColumnIndexOrThrow%28java.lang.String%29
  */
  virtual int GetColumnIndexOrThrow(OsIndependentString* columnName) = 0;
  /*
  Returns the zero-based index for the given column name, or -1 if the column doesn't exist. If you expect the column to exist use getColumnIndexOrThrow(String) instead, which will make the error more clear.
  http://developer.android.com/reference/android/database/Cursor.html#getColumnIndex%28java.lang.String%29
  */
  virtual int GetColumnIndex(OsIndependentString* columnName) = 0;
  // void  [More ...] setNotificationUri(ContentResolver cr, Uri uri);
  virtual void SetNotificationUri(OsIndependentContentResolver* cr, OsIndependentUri* uri) = 0;
  virtual void Close() = 0;
};
/*
needs no Factory, because is an interface
*/
