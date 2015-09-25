#pragma once
/*
Port of class DeviceInfoList from TextSecure-android
*/

// [x] done
// TFS ID: 340

#include "DeviceLimit.h"

#include "..\..\api\push\exceptions\NonSuccessfulResponseCodeException.h"

class DeviceLimitExceededException : NonSuccessfulResponseCodeException
{
private:
  DeviceLimit* deviceLimit;

public:
  DeviceLimitExceededException(DeviceLimit* deviceLimit)
  {
    this->deviceLimit = deviceLimit;
  }
  int GetCurrent() { return deviceLimit->GetCurrent(); }
  int GetMax() { return deviceLimit->GetMax(); }
};
