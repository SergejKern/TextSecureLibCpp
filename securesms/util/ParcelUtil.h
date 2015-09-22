#pragma once

/*
Port of ParcelUtil.java from TextSecure-android
*/

// [x] done
// TFS ID: 231

#include "..\..\osindependent\OsIndependentParcel.h"
#include "..\..\osindependent\OsIndependentParcelable.h"

class ParcelUtil
{
public:
  // returns byte[]
  static char* Serialize(OsIndependentParcelable* parceable)
  {
    OsIndependentParcel* parcel = OsIndependentParcel::Obtain();
    parceable->WriteToParcel(parcel, 0);
    char* bytes = parcel->Marshall();
    parcel->Recycle();
    return bytes;
  }
  static OsIndependentParcel* Deserialize(char* bytes)
  {
    int len = 0; // TODO -> len of bytes array
    OsIndependentParcel* parcel = OsIndependentParcel::Obtain();
    parcel->Unmarshall(bytes, 0, /* TODO bytes.length*/ len);
    parcel->SetDataPosition(0);
    return parcel;
  }
  template<typename T> static T Deserialize(char* bytes, OsIndependentParcelable::Creator<T>* creator)
  {
    OsIndependentParcel* parcel = Deserialize(bytes);
    return creator->CreateFromParcel(parcel);
  }
};
