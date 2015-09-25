#pragma once
/*
Port of class DeviceContact from TextSecure-android
*/

// [x] done
// TFS ID: 274

#include "..\TextSecureAttachmentStream.h"

class DeviceContact
{
private:
  const unsigned char* number;
  const unsigned char* name;
  TextSecureAttachmentStream* avatar;

public:
  DeviceContact(unsigned char* number, unsigned char* name, TextSecureAttachmentStream* avatar)
  {
    this->number = number;
    this->name   = name;
    this->avatar = avatar;
  }
  TextSecureAttachmentStream* GetAvatar() { return this->avatar; }
  unsigned char* GetName() { return (unsigned char*)this->name; }
  unsigned char* GetNumber() { return (unsigned char*)this->number; }
};
