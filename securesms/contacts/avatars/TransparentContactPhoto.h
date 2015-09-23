#pragma once

/*
Port of class TransparentContactPhoto from TextSecure-android
*/

// [ ] done
// TFS ID: 437

#include "ContactPhoto.h"
#include "..\..\..\otherproject\RoundedDrawable.h"
#include "..\..\..\osindependent\OsIndependentContext.h"
#include "..\..\..\osindependent\OsIndependentDrawable.h"

class TransparentContactPhoto : ContactPhoto
{
public:
  TransparentContactPhoto();
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color);
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted);
};
