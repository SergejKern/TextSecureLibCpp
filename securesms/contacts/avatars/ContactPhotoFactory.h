#pragma once

/*
Port of class ContactPhotoFactory from TextSecure-android
*/

// [ ] done
// TFS ID: 435

#include "ContactPhoto.h"

class ContactPhotoFactory
{
public:
  static ContactPhoto* GetDefaultContactPhoto(char* name);
  static ContactPhoto* GetLoadingPhoto();
};
