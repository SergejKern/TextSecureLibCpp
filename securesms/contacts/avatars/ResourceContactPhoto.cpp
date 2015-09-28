#include "ResourceContactPhoto.h"

OsIndependentDrawable* ResourceContactPhoto::AsDrawable(OsIndependentContext* context, int color)
{
  return AsDrawable(context, color, false);
}
OsIndependentDrawable* ResourceContactPhoto::AsDrawable(OsIndependentContext* context, int color, bool inverted)
{
  OsIndependentDrawable* background = TextDrawable.builder().buildRound(" ", inverted ? Color.WHITE : color);
  RoundedDrawable foreground = (RoundedDrawable)RoundedDrawable.fromDrawable(context.getResources().getDrawable(resourceId));

  foreground.setScaleType(ImageView.ScaleType.CENTER);

  if (inverted) {
    foreground.setColorFilter(color, PorterDuff.Mode.SRC_ATOP);
  }

  return new ExpandingLayerDrawable(new OsIndependentDrawable[] {background, foreground});
}
