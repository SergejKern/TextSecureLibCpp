#pragma once
/*
Port of class DeviceGroupsOutputStream from TextSecure-android
*/

// [x] done
// TFS ID: 279

//import com.google.protobuf.ByteString;
//
//import org.whispersystems.textsecure.internal.push.TextSecureProtos;
#include "..\..\..\internal\push\TextSecureProtos.h"
//
//import java.io.IOException;
#include "ChunkedOutputStream.h"
#include "DeviceGroup.h"

class DeviceGroupsOutputStream : public ChunkedOutputStream
{
public:
  DeviceGroupsOutputStream(OsIndependentOutputStream* out);
  void Write(DeviceGroup* group);
  void Close();
private:
  void WriteAvatarImage(DeviceGroup* contact);
  void WriteGroupDetails(DeviceGroup* group);
};
