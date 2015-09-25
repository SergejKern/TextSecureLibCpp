#pragma once
/*
Port of class NonSuccessfulResponseCodeException from TextSecure-android
*/

// [x] done
// TFS ID: 292

#include "..\..\..\..\javastuff\Exception.h"
//import java.io.IOException;

class NonSuccessfulResponseCodeException /*extends IOException*/
  : public Exception
{
public:
  NonSuccessfulResponseCodeException() 
    : Exception() { }
  NonSuccessfulResponseCodeException(unsigned char* s)
    : Exception(s) { }
};
