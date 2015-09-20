#include "ContactPhotoFactory.h"
#include "ContactPhoto.h"
#include "GeneratedContactPhoto.h"

/*
[!] IMPORTANT for strings:
    http://www.cprogramming.com/tutorial/unicode.html
*/

ContactPhoto* ContactPhotoFactory::GetDefaultContactPhoto(char* name)
{
  /* if (!android.text.TextUtils.isEmpty(name)) OS SPECIFIC **/
  /* TODO */
  if (name !=  nullptr)
  {
    return new GeneratedContactPhoto(name);
  }
  else
  {
    return new GeneratedContactPhoto("#");
  }
}

ContactPhoto* ContactPhotoFactory::GetLoadingPhoto()
{
  return new TransparentContactPhoto();
}
