#include "ContactPhotoFactory.h"
#include "ContactPhoto.h"
#include "GeneratedContactPhoto.h"
#include "TransparentContactPhoto.h"

/*
[!] IMPORTANT for strings:
    http://www.cprogramming.com/tutorial/unicode.html
*/

ContactPhoto* ContactPhotoFactory::GetDefaultContactPhoto(OsIndependentString* name)
{
  if (!OsIndependentString::IsNullOrEmpty(name))
  {
    return new GeneratedContactPhoto(name);
  }
  else
  {
    return new GeneratedContactPhoto(new OsIndependentString("#"));
  }
}

ContactPhoto* ContactPhotoFactory::GetLoadingPhoto()
{
  return new TransparentContactPhoto();
}
