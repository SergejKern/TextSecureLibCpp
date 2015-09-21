#pragma once
/*
Port of class UndeliverableMessageException from TextSecure-android
*/

// [x] done
// TFS ID: 652

#include "..\..\javastuff\Exception.h"
class UndeliverableMessageException : Exception
{
public:
  UndeliverableMessageException() { }
  UndeliverableMessageException(unsigned char* detailMessage) : Exception(detailMessage) {}
  UndeliverableMessageException(unsigned char* detailMessage, /*Throwable*/Exception* throwable) : Exception(detailMessage, throwable) {}
  UndeliverableMessageException(/*Throwable*/Exception* throwable) : Exception(throwable) {}
};
