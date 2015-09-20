#pragma once

/*
Port of interface ContactPhoto from TextSecure-android
*/

// [ ] done
// TFS ID: 432

class ContactPhoto
{
  /* android.graphics.drawable.Drawable
     android.content.Context
     OS SPECIFIC
  public Drawable asDrawable(Context context, int color);
  public Drawable asDrawable(Context context, int color, boolean inverted);
  */
public:
  virtual void* AsDrawable(void* context, int color) = 0;
  virtual void* AsDrawable(void* context, int color, bool inverted) = 0;
};
