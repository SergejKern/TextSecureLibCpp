#pragma once
/*
Port of class DeviceContact from TextSecure-android
*/

// [x] done
// TFS ID: 277

#include "..\TextSecureAttachmentStream.h"
#include "..\..\..\..\owntemplates\List.h"

class DeviceGroup
{
private:
  const char* id;
  const unsigned char* name;
  List<unsigned char*> members;
  TextSecureAttachmentStream* avatar;
public:
  DeviceGroup(char* id, unsigned char* name, List<unsigned char*> members, TextSecureAttachmentStream* avatar)
  {
    this->id = id;
    this->name = name;
    this->members = members;
    this->avatar = avatar;
  }
  TextSecureAttachmentStream* GetAvatar() { return this->avatar; }
  unsigned char* GetName() { return (unsigned char*)this->name; }
  char* GetId() { return (char*)this->id; }
  List<unsigned char*> GetMembers() { return this->members; }
};
