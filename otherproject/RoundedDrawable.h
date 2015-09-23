#pragma once
/*
port of java class com.makeramen.roundedimageview.RoundedDrawable
https://github.com/vinc3m1/RoundedImageView/blob/master/roundedimageview/src/main/java/com/makeramen/roundedimageview/RoundedDrawable.java
*/

// [ ] done
// TFS ID: none

#include "..\osindependent\OsIndependentDrawable.h"
/*
public class RoundedDrawable extends Drawable {
*/
class RoundedDrawable : OsIndependentDrawable
{
public:
  static OsIndependentDrawable* FromDrawable(OsIndependentDrawable* drawable)
  {
    // TODO
    //if (drawable != nullptr)
    //{
    //  if (drawable instanceof RoundedDrawable)
    //  {
    //    // just return if it's already a RoundedDrawable
    //    return drawable;
    //  }
    //  else if (drawable instanceof LayerDrawable)
    //  {
    //    LayerDrawable ld = (LayerDrawable)drawable;
    //    int num = ld.getNumberOfLayers();
    //    // loop through layers to and change to RoundedDrawables if possible
    //    for (int i = 0; i < num; i++) {
    //      Drawable d = ld.getDrawable(i);
    //      ld.setDrawableByLayerId(ld.getId(i), fromDrawable(d));
    //    }
    //    return ld;
    //  }
    //  // try to get a bitmap from the drawable and
    //  Bitmap bm = drawableToBitmap(drawable);
    //  if (bm != null) {
    //    return new RoundedDrawable(bm);
    //  }
    //}
    return drawable;
  }
};
