#pragma once

/*
Port of class TransparentContactPhoto from TextSecure-android
*/

// [ ] done
// TFS ID: 437

#include "ContactPhoto.h"

class TransparentContactPhoto : ContactPhoto
{
public:
  TransparentContactPhoto();
  virtual void* AsDrawable(void* context, int color);
  virtual void* AsDrawable(void* context, int color, bool inverted);
};
