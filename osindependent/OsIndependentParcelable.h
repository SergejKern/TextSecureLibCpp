#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.Parcelable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Parcelable.java#Parcelable
*/

// [ ] done
// TFS ID: 663

#include "..\Factory\Factory.h"

// public interface  [More ...] Parcelable {
class OsIndependentParcelable
{
private:
  OsIndependentParcelable();
public:  
  virtual void WriteToParcel(OsIndependentParcel* parcel, int len) = 0;
  template <typename T> class Creator<T>
  {
  public:
    virtual T* CreateFromParcel(OsIndependentParcel* source) = 0;
    virtual T[] NewArray(int size) = 0;
  };
};
/*
needs no Factory, because is an interface
*/
