#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.Parcelable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Parcelable.java#Parcelable
*/

// [ ] done
// TFS ID: 663
#include "OsIndependentParcel.h"

class OsIndependentParcelable
{
private:
public:
  OsIndependentParcelable() {};
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/net/Uri.html
  */
  virtual void WriteToParcel(OsIndependentParcel* parcel, int len) = 0;
  
  template <typename T> class Creator<T>
  {
  public:
    T* CreateFromParcel(OsIndependentParcel* source);
    T[] NewArray(int size);
  };
};
