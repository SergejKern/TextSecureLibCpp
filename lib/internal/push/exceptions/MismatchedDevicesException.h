#pragma once
/*
Port of class MismatchedDevicesException from TextSecure-android
*/

// [x] done
// TFS ID: 359

#include "..\..\..\api\push\exceptions\NonSuccessfulResponseCodeException.h"
#include "..\MismatchedDevices.h"

class MismatchedDevicesException : public NonSuccessfulResponseCodeException 
{
private:
  MismatchedDevices* mismatchedDevices;
public:
  MismatchedDevicesException(MismatchedDevices* mismatchedDevices)
  {
    this->mismatchedDevices = mismatchedDevices;
  }
  MismatchedDevices* GetMismatchedDevices() { return this->mismatchedDevices; }
};
