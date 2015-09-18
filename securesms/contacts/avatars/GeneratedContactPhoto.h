#pragma once

/*
Port of class GeneratedContactPhoto from TextSecure-android
*/
// [ ] done
// TFS ID: 436

#include "ContactPhoto.h"

class GeneratedContactPhoto : ContactPhoto
{
private:
  const char* name;
public:
  GeneratedContactPhoto(char* name);
  //@Override
  virtual void* AsDrawable(void* context, int color);
  //@Override
  virtual void* AsDrawable(void* context, int color, bool inverted);
};
