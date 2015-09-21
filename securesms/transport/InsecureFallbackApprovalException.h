#pragma once
/*
Port of class InsecureFallbackApprovalException from TextSecure-android
*/

// [x] done
// TFS ID: 650

#include "..\..\javastuff\Exception.h"

class InsecureFallbackApprovalException : Exception
{
public:
  InsecureFallbackApprovalException(unsigned char* detailMessage) : Exception(detailMessage) {}
  InsecureFallbackApprovalException(/*Throwable*/Exception* e) : Exception(e) {}
};
