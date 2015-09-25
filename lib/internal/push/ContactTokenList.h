#pragma once
/*
Port of class ContactTokenList from TextSecure-android
*/

// [x] done
// TFS ID: 336

#include "..\..\..\owntemplates\List.h"

class ContactTokenList
{
private:
  List<unsigned char*>* contacts;
public:
  ContactTokenList(List<unsigned char*>* contacts)
  {
    this->contacts = contacts;
  }
  ContactTokenList() {}

  List<unsigned char*>* GetContacts() { return contacts; }
};
