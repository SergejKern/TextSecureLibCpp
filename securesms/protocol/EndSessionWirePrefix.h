#pragma once
/*
Port of class EndSessionWirePrefix from TextSecure-android
*/

// [x] done
// TFS ID: 625

#include "WirePrefix.h"

class EndSessionWirePrefix : WirePrefix
{
public:
  // @Override
  virtual OsIndependentString* CalculatePrefix(OsIndependentString* message)
  {
    return CalculateEndSessionPrefix(message);
  }
};
