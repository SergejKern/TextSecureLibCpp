#pragma once

/*
Port of enum MaterialColors from TextSecure-android
*/

// [ ] done
// TFS ID: 372

#include "MaterialColorList.h"

class MaterialColors
{
public:
  static /*const*/ MaterialColorList* CONVERSATION_PALETTE;

    /* TODO new ArrayList<>(Arrays.asList(
    MaterialColor.RED,
    MaterialColor.PINK,
    MaterialColor.PURPLE,

    MaterialColor.DEEP_PURPLE,
    MaterialColor.INDIGO,
    MaterialColor.BLUE,

    MaterialColor.LIGHT_BLUE,
    MaterialColor.CYAN,
    MaterialColor.TEAL,
    MaterialColor.GREEN,
    MaterialColor.LIGHT_GREEN,
    // Lime
    // Yellow
    // Amber
    MaterialColor.ORANGE,
    MaterialColor.DEEP_ORANGE,
    //    MaterialColor.BROWN,
    MaterialColor.AMBER,
    // Grey
    MaterialColor.BLUE_GREY
    )));*/
    
};

MaterialColorList* MaterialColors::CONVERSATION_PALETTE = new MaterialColorList();
