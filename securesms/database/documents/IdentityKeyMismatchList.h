#pragma once

/*
Port of IdentityKeyMismatchList from TextSecure-android
*/

// [x] done
// TFS ID: 314

#include "Document.h"
#include "IdentityKeyMismatch.h"

class IdentityKeyMismatchList : public Document<IdentityKeyMismatch>
{
private:
  //@JsonProperty(value = "m")
  List<IdentityKeyMismatch>* mismatches;

public:
  IdentityKeyMismatchList()
  {
    this->mismatches = new LinkedList<IdentityKeyMismatch>();
  }
  IdentityKeyMismatchList(List<IdentityKeyMismatch>* mismatches)
  {
    this->mismatches = mismatches;
  }
  //@Override
  int Size()
  {
    if (this->mismatches == nullptr)
    {
      return 0;
    }
    else
    {
      return mismatches->Size();
    }
  }
  //@Override
  List<IdentityKeyMismatch>* GetList()
  {
    return this->mismatches;
  }
};
