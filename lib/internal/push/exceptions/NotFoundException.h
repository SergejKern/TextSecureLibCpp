#pragma once
/*
Port of class NotFoundException from TextSecure-android
*/

// [x] done
// TFS ID: 293

#include "NonSuccessfulResponseCodeException.h"

class NotFoundException : public NonSuccessfulResponseCodeException
{
public:
  NotFoundException(unsigned char* s)
    : NonSuccessfulResponseCodeException(s)
  {}
};
