#pragma once
/*
Port of class RateLimitException from TextSecure-android
*/

// [x] done
// TFS ID: 295

#include "NonSuccessfulResponseCodeException.h"

class RateLimitException : public NonSuccessfulResponseCodeException
{
public:
  RateLimitException(unsigned char* s)
    : NonSuccessfulResponseCodeException(s) { }
};
