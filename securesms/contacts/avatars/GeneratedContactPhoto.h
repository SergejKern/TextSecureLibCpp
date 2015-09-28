#pragma once

/*
Port of class GeneratedContactPhoto from TextSecure-android
*/
// [ ] done
// TFS ID: 436

#include "ContactPhoto.h"
#include "..\..\..\osindependent\OsIndependentString.h"

class GeneratedContactPhoto : public ContactPhoto
{
private:
  OsIndependentString* name;
public:
  GeneratedContactPhoto(OsIndependentString* name);
  //@Override
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color);
  //@Override
  virtual OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted);
};
