#include "TransparentContactPhoto.h"
#include "..\..\..\osindependent\OsIndependentSystem.h"

TransparentContactPhoto::TransparentContactPhoto()
{
}
OsIndependentDrawable* TransparentContactPhoto::AsDrawable(OsIndependentContext* context, int color)
{
  return AsDrawable(context, color, false);
}
OsIndependentDrawable* TransparentContactPhoto::AsDrawable(OsIndependentContext* context, int color, bool inverted)
{
  return RoundedDrawable::FromDrawable(context->GetResources()->GetDrawable(/*android.R.color.transparent*/ OsIndependentSystem::GetColorTransparent()));
}
