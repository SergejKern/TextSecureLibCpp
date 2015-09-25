#pragma once
/*
Port of class StaleDevicesException from TextSecure-android
*/

// [x] done
// TFS ID: 360

#include "..\..\..\api\push\exceptions\NonSuccessfulResponseCodeException.h"
#include "..\StaleDevices.h"

class StaleDevicesException : NonSuccessfulResponseCodeException
{
private:
  StaleDevices* staleDevices;
public:
  StaleDevicesException(StaleDevices* staleDevices)
  {
    this->staleDevices = staleDevices;
  }
  StaleDevices* GetStaleDevices() { return this->staleDevices; }
};
