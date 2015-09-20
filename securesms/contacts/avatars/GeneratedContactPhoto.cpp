#include "GeneratedContactPhoto.h"

GeneratedContactPhoto::GeneratedContactPhoto(char* name)
{
  this->name = name;
}
//@Override
void* GeneratedContactPhoto::AsDrawable(void* context, int color)
{
  return AsDrawable(context, color, false);
}
//@Override
void* GeneratedContactPhoto::AsDrawable(void* context, int color, bool inverted)
{
  return nullptr;
  // TODO int targetSize = context.getResources().getDimensionPixelSize(R.dimen.contact_photo_target_size);

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
