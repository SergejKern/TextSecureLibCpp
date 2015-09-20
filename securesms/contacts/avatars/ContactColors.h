#pragma once

/*
Port of class ContactColors from TextSecure-android
*/

// [ ] done
// TFS ID: 433

#include "..\..\color\MaterialColor.h"
#include "..\..\color\MaterialColors.h"

class ContactColors
{
public:
  static /*const*/ MaterialColor* UNKNOWN_COLOR;
public:
  static MaterialColor* GenerateFor(unsigned char* name)
  {
    // TODO return MaterialColors::CONVERSATION_PALETTE::get(Math.abs(name.hashCode()) % MaterialColors.CONVERSATION_PALETTE.size());
    return nullptr;
  }
};

MaterialColor* ContactColors::UNKNOWN_COLOR = MaterialColor::GREY;
