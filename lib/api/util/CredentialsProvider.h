#pragma once
/*
Port of class CredentialsProvider from TextSecure-android
*/

// [x] done
// TFS ID: 297

#include "..\..\..\osindependent\OsIndependentString.h"

//interface CredentialsProvider
class CredentialsProvider
{
public:
  virtual OsIndependentString* GetUser() = 0;
  virtual OsIndependentString* GetPassword() = 0;
  virtual OsIndependentString* GetSignalingKey() = 0;
};
