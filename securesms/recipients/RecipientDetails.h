#pragma once

/*
Port of class RecipientDetails from TextSecure-android
*/

// [ ] done
// TFS ID: 324

#include "..\contacts\avatars\ContactPhoto.h"
#include "..\color\MaterialColor.h"

class RecipientDetails
{
public:
  unsigned char* name;
  unsigned char* number;
  ContactPhoto* avatar;
  //const Uri* contactUri;
  void* contactUri;
  MaterialColor* color;
public:
  //RecipientDetails(char* name, char* number, Uri* contactUri, ContactPhoto* avatar, MaterialColor* color);
  RecipientDetails(unsigned char* name, unsigned char* number, void* contactUri, ContactPhoto* avatar, MaterialColor* color);
  virtual ~RecipientDetails();
};
