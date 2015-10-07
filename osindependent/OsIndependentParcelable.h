#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.Parcelable
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Parcelable.java#Parcelable
*/

// [x] done
// TFS ID: 663

#include "..\Factory\Factory.h"

// public interface  [More ...] Parcelable {
class OsIndependentParcelable
{
private:
  OsIndependentParcelable();
public:
  /*
  Bit masks for use with describeContents(): each bit represents a kind of object considered to have potential special significance when marshalled.
  */
  static const int CONTENTS_FILE_DESCRIPTOR = 0x0001;
  /*
  Flag for use with writeToParcel(android.os.Parcel,int): the object being written is a return value, that is the result of a function such as "Parcelable someFunction()", "void someFunction(out Parcelable)", or "void someFunction(inout Parcelable)". Some implementations may want to release resources at this point.
  */
  static const int PARCELABLE_WRITE_RETURN_VALUE = 0x0001;
  /*
  Describe the kinds of special objects contained in this Parcelable's marshalled representation.
  Returns:
  a bitmask indicating the set of special object types marshalled by the Parcelable.
  */
  virtual int DescribeContents() = 0;
  /*
  Flatten this object in to a Parcel.
  Parameters:
  dest The Parcel in which the object should be written.
  flags Additional flags about how the object should be written. May be 0 or PARCELABLE_WRITE_RETURN_VALUE.
  */
  virtual void WriteToParcel(OsIndependentParcel* parcel, int len) = 0;
  /*
  Interface that must be implemented and provided as a public CREATOR field that generates instances of your Parcelable class from a Parcel.
  */
  template <typename T> class Creator<T>
  {
  public:
    /*
    Create a new instance of the Parcelable class, instantiating it from the given Parcel whose data had previously been written by Parcelable.writeToParcel().
    Parameters:
    source The Parcel to read the object's data from.
    Returns:
    Returns a new instance of the Parcelable class.
    */
    virtual T* CreateFromParcel(OsIndependentParcel* source) = 0;
    /*
    Create a new array of the Parcelable class.
    Parameters:
    size Size of the array.
    Returns:
    Returns an array of the Parcelable class, with every entry initialized to null.
    */
    virtual T[] NewArray(int size) = 0;
  };
  /*
  */
  template <typename T> class ClassLoaderCreator<T> : public Creator<T>
  {
  public:
    /*
    Create a new instance of the Parcelable class, instantiating it from the given Parcel whose data had previously been written by Parcelable.writeToParcel() and using the given ClassLoader.
    Parameters:
    source The Parcel to read the object's data from.
    loader The ClassLoader that this object is being created in.
    Returns:
    Returns a new instance of the Parcelable class.
    */
    virtual T* CreateFromParcel(OsIndependentParcel* source, OsIndependentClassLoader* loader) = 0;
  };
};
/*
needs no Factory, because is an interface
*/
