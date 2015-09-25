#pragma once
/*
Port of class SendMessageResponse from TextSecure-android
*/

// [x] done
// TFS ID: 287

#include "..\..\..\osindependent\OsIndependentInputStream.h"

/**
 * A class that represents a Java {@link java.security.KeyStore} and
 * its associated password.
 */
//interface TrustStore
class TrustStore
{
public:
  virtual OsIndependentInputStream* GetKeyStoreInputStream() = 0;
  virtual unsigned char* GetKeyStorePassword() = 0;
};
