#pragma once
/*
Port of class StaticCredentialsProvider from TextSecure-android
*/

// [x] done
// TFS ID: 365

#include "..\..\api\util\CredentialsProvider.h"

class StaticCredentialsProvider : public CredentialsProvider
{
private:
  const unsigned char* user;
  const unsigned char* password;
  const unsigned char* signalingKey;
public:
  StaticCredentialsProvider(unsigned char* user, unsigned char* password, unsigned char* signalingKey)
  {
    this->user = user;
    this->password = password;
    this->signalingKey = signalingKey;
  }
  //@Override
  virtual const unsigned char* GetUser() { return this->user; }
  //@Override
  virtual const unsigned char* GetPassword() { return password; }
  //@Override
  virtual const unsigned char* GetSignalingKey() { return signalingKey; }
};
