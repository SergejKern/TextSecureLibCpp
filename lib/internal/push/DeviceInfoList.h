#pragma once
/*
Port of class DeviceInfoList from TextSecure-android
*/

// [x] done
// TFS ID: 338

//import com.fasterxml.jackson.annotation.JsonProperty;
#include "..\..\api\messages\multidevice\DeviceInfo.h"
#include "..\..\..\owntemplates\List.h"

class DeviceInfoList
{
private:
  //@JsonProperty
  List<DeviceInfo*>* devices;
public:
  DeviceInfoList() {}
  List<DeviceInfo*>* GetDevices() { return devices; }
};
