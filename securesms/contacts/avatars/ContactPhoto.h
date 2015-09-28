#pragma once

/*
Port of interface ContactPhoto from TextSecure-android
*/

// [x] done
// TFS ID: 432

#include "..\..\..\osindependent\OsIndependentContext.h"
#include "..\..\..\osindependent\OsIndependentDrawable.h"

class ContactPhoto
{
public:
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color) = 0;
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted) = 0;
};
