#pragma once

/*
Port of class BitmapContactPhoto from TextSecure-android
*/

// [ ] done
// TFS ID: 432

#include "..\..\..\osindependent\OsIndependentContext.h"
#include "..\..\..\osindependent\OsIndependentBitmap.h"
#include "..\..\..\osindependent\OsIndependentDrawable.h"
//import android.widget.ImageView;
//
#include "..\..\..\otherproject\RoundedDrawable.h"

#include "ContactPhoto.h"

class BitmapContactPhoto : ContactPhoto
{
private:
  OsIndependentBitmap* bitmap;
  BitmapContactPhoto(OsIndependentBitmap* bitmap)
  {
    this->bitmap = bitmap;
  }
public:
  //@Override
  OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color)
  {
    return AsDrawable(context, color, false);
  }

  //@Override
  OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted)
  {
    return RoundedDrawable::FromBitmap(bitmap)->SetScaleType(ImageView::ScaleType::CENTER_CROP)->SetOval(true);
  }
};
