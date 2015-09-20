#pragma once

/*
Port of class MaterialColorList from TextSecure-android
*/

// [ ] done
// TFS ID: 656

#include "MaterialColor.h"

class MaterialColorList
{
private:
  //TODO const List<MaterialColor> colors;
  const MaterialColor* colors;

public:
  MaterialColorList(MaterialColor* colors)
  {
    this->colors = colors;
  }
  MaterialColorList() {}
  virtual ~MaterialColorList() {}

  MaterialColor* Get(int index)
  {
    return nullptr;
    // TODO return colors->Get(index);
  }

  int Size()
  {
    return 0;
    // TODO return colors->Size();
  }

  // TODO OS SPECIFIC
  MaterialColor* GetByColor(/*Context*/ void* context, int colorValue)
  {
    /* TODO for (MaterialColor color : colors) {
      if (color.represents(context, colorValue)) {
        return color;
      }
    }*/

    return nullptr;
  }
  // TODO OS SPECIFIC
  int* AsConversationColorArray(/*Context*/ void* context)
  {
    /* TODO
    int[] results = new int[Size()];
    int   index = 0;

    for (MaterialColor color : colors) {
      results[index++] = color.toConversationColor(context);
    }

    return results;
    */
    nullptr;
  }
};
