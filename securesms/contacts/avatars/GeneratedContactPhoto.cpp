#include "GeneratedContactPhoto.h"

GeneratedContactPhoto::GeneratedContactPhoto(OsIndependentString* name)
{
  this->name = name;
}
//@Override
OsIndependentDrawable* GeneratedContactPhoto::AsDrawable(OsIndependentContext* context, int color)
{
  return AsDrawable(context, color, false);
}
//@Override
OsIndependentDrawable* GeneratedContactPhoto::AsDrawable(OsIndependentContext* context, int color, bool inverted)
{
  int targetSize = context->GetResources()->GetDimensionPixelSize(R::dimen::contact_photo_target_size);
  return nullptr;  

  /*
  https://github.com/amulyakhare/TextDrawable
  */

  /* TODO return TextDrawable.builder()
    .beginConfig()
    .width(targetSize)
    .height(targetSize)
    .textColor(inverted ? color : Color.WHITE)
    .endConfig()
    .buildRound(String.valueOf(name.charAt(0)), inverted ? Color.WHITE : color); */
}
