#pragma once

/*
Port of class ContactPhotoFactory from TextSecure-android
*/

// [x] done
// TFS ID: 435

#include "ContactPhoto.h"
#include "..\..\..\osindependent\OsIndependentString.h"

class ContactPhotoFactory
{
public:
  static ContactPhoto* GetDefaultContactPhoto(OsIndependentString* name);
  static ContactPhoto* GetLoadingPhoto();
};
