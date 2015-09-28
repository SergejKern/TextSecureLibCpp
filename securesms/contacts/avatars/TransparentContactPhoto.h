#pragma once

/*
Port of class TransparentContactPhoto from TextSecure-android
*/

// [x] done
// TFS ID: 437

#include "ContactPhoto.h"
#include "..\..\..\otherproject\RoundedDrawable.h"


class TransparentContactPhoto : public ContactPhoto
{
public:
  TransparentContactPhoto();
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color);
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted);
};
