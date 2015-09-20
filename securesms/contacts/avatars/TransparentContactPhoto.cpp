#include "TransparentContactPhoto.h"

TransparentContactPhoto::TransparentContactPhoto()
{
}
void* TransparentContactPhoto::AsDrawable(void* context, int color)
{
  return AsDrawable(context, color, false);
}
void* TransparentContactPhoto::AsDrawable(void* context, int color, bool inverted)
{
  return nullptr;
  // TODO OS SPECIFIC return RoundedDrawable.fromDrawable(context.getResources().getDrawable(android.R.color.transparent));
}
