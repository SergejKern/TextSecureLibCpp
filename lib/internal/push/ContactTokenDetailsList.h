#pragma once
/*
Port of class ContactTokenDetailsList from TextSecure-android
*/

// [x] done
// TFS ID: 335

#include "..\..\api\push\ContactTokenDetails.h"
#include "..\..\..\owntemplates\List.h"

class ContactTokenDetailsList
{
private:
  List<ContactTokenDetails*>* contacts;
public:
  ContactTokenDetailsList() {}
  List<ContactTokenDetails*>* GetContacts() { return this->contacts; }
};
