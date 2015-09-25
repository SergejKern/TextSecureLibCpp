#pragma once
/*
Port of class PushNetworkException from TextSecure-android
*/

// [x] done
// TFS ID: 294

#include "..\..\..\..\javastuff\Exception.h"
//import java.io.IOException;

class PushNetworkException : public Exception /*extends IOException*/
{
public:
  PushNetworkException(Exception* exception)
    : Exception(exception)
  { }
  PushNetworkException(unsigned char* s)
    : Exception(s) { }
};
