#pragma once

/*
Port of class ResourceContactPhoto from TextSecure-android
*/

// [ ] done
// TFS ID: 438

#include "..\..\..\osindependent\OsIndependentContext.h"
//import android.graphics.Color;
//import android.graphics.ColorFilter;
//import android.graphics.PorterDuff;
#include "..\..\..\osindependent\OsIndependentDrawable.h"
//import android.graphics.drawable.LayerDrawable;
//import android.support.annotation.DrawableRes;
//import android.support.v4.graphics.ColorUtils;
//import android.widget.ImageView;
//
//import com.amulyakhare.textdrawable.TextDrawable;
//import com.makeramen.roundedimageview.RoundedDrawable;

#include "ContactPhoto.h"

class ResourceContactPhoto : ContactPhoto
{
private:
  static class ExpandingLayerDrawable : LayerDrawable
  {
  public:
    ExpandingLayerDrawable(OsIndependentDrawable[] layers) : LayerDrawable(layers) { }
    //@Override
    int getIntrinsicWidth() { return -1; }
    //@Override
    int getIntrinsicHeight() { return -1; }
  };
private:
  const int resourceId;

  ResourceContactPhoto(int resourceId)
    : resourceId(resourceId)
  { }
public:
  //@Override
  OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color);
  //@Override
  OsIndependentDrawable* AsDrawable(OsIndependentContext* context, int color, bool inverted);
};
