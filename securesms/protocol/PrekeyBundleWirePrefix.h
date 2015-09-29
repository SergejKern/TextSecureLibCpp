#pragma once
/*
Port of class PrekeyBundleWirePrefix from TextSecure-android
*/

// [x] done
// TFS ID: 627

#include "WirePrefix.h"

class PrekeyBundleWirePrefix : WirePrefix
{
public:
  // @Override
  virtual OsIndependentString* CalculatePrefix(OsIndependentString* message)
  {
    return CalculatePreKeyBundlePrefix(message);
  }
};
