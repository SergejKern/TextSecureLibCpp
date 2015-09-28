#pragma once
/*
Port of class CredentialsProvider from TextSecure-android
*/

// [x] done
// TFS ID: 297

//interface CredentialsProvider
class CredentialsProvider
{
public:
  virtual unsigned char* GetUser() = 0;
  virtual unsigned char* GetPassword() = 0;
  virtual unsigned char* GetSignalingKey() = 0;
};
