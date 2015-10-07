#pragma once
/*
  abstract class OsIndependentSQLiteClosable to replace android.database.sqlite.SQLiteClosable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/database/sqlite/SQLiteClosable.java#SQLiteClosable
*/

// [x] done
// TFS ID: 782

#include "..\Factory\Factory.h"
#include "..\javastuff\Closeable.h"

// public abstract class  [More ...] SQLiteClosable implements Closeable {
class OsIndependentSQLiteClosable : public Closeable
{
protected:
  /*
  protected abstract void[More ...] onAllReferencesReleased();
  Called when the last reference to the object was released by a call to releaseReference() or close().
  */
  virtual void OnAllReferencesReleased() = 0;
public:
  /*
  Acquires a reference to the object.
  Throws:
  java.lang.IllegalStateException if the last reference to the object has already been released.
  */
  virtual void AcquireReference() = 0;
  /*
  Releases a reference to the object, closing the object if the last reference was released. Calling this method is equivalent to calling releaseReference().
  */
  virtual void Close() = 0;
  /*
  Releases a reference to the object, closing the object if the last reference was released.

  See also:
  onAllReferencesReleased()
  */
  virtual void ReleaseReference() = 0;
};
/*
needs no Factory, because is abstract
*/
