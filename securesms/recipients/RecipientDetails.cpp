#include "RecipientDetails.h"

RecipientDetails::RecipientDetails(unsigned char* name, unsigned char* number, void* contactUri, ContactPhoto* avatar, MaterialColor* color)
{
  this->name = name;
  this->number = number;
  this->avatar = avatar;
  this->contactUri = contactUri;
  this->color = color;
}

RecipientDetails::~RecipientDetails()
{
}
