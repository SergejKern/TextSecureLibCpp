#pragma once
/*
Port of class KeyExchangeWirePrefix from TextSecure-android
*/

// [x] done
// TFS ID: 626

#include "WirePrefix.h"

class KeyExchangeWirePrefix : WirePrefix
{
public:
  // @Override
  virtual OsIndependentString* CalculatePrefix(OsIndependentString* message)
  {
    return CalculateKeyExchangePrefix(message);
  }
};
