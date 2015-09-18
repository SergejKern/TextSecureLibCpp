#pragma once

/*
Port of class RecipientDetails from TextSecure-android
*/

class RecipientDetails
{
public:
  const char* name;
  const char* number;
  //const ContactPhoto* avatar;
  const void* avatar;
  //const Uri* contactUri;
  const void* contactUri;
  //const MaterialColor* color;
  const void* color;
public:
  //RecipientDetails(char* name, char* number, Uri* contactUri, ContactPhoto* avatar, MaterialColor* color);
  RecipientDetails(char* name, char* number, void* contactUri, void* avatar, void* color);
  virtual ~RecipientDetails();
};
