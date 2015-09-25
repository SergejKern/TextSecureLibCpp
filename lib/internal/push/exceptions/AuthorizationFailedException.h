#pragma once
/*
Port of class AuthorizationFailedException from TextSecure-android
*/

// [x] done
// TFS ID: 288

#include "NonSuccessfulResponseCodeException.h"

class AuthorizationFailedException : NonSuccessfulResponseCodeException
{
public:
  AuthorizationFailedException(unsigned char* s)
    : NonSuccessfulResponseCodeException(s)
  { }
};
