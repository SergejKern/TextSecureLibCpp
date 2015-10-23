#pragma once
/*
Port of class DeviceGroup from TextSecure-android
*/

// [x] done
// TFS ID: 277

#include "..\TextSecureAttachmentStream.h"
#include <list>
#include <vector>
#include "..\..\..\..\osindependent\OsIndependentString.h"

class DeviceGroup
{
private:
  std::vector<unsigned char>* id;
  OsIndependentString* name;
  std::list<unsigned char*>* members;
  TextSecureAttachmentStream* avatar;
public:
  DeviceGroup(std::vector<unsigned char>* id, OsIndependentString* name, std::list<unsigned char*>* members, TextSecureAttachmentStream* avatar)
  {
    this->id = id;
    this->name = name;
    this->members = members;
    this->avatar = avatar;
  }
  TextSecureAttachmentStream* GetAvatar() { return this->avatar; }
  OsIndependentString* GetName() { return this->name; }
  std::vector<unsigned char>* GetId() { return this->id; }
  std::list<unsigned char*>* GetMembers() { return this->members; }
};
