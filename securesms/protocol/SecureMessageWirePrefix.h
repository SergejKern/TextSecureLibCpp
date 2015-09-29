#pragma once
/*
Port of class SecureMessageWirePrefix from TextSecure-android
*/

// [x] done
// TFS ID: 628

#include "WirePrefix.h"

class SecureMessageWirePrefix : WirePrefix
{
public:
  // @Override
  virtual OsIndependentString* CalculatePrefix(OsIndependentString* message)
  {
    return CalculateEncryptedMesagePrefix(message);
  }
};
