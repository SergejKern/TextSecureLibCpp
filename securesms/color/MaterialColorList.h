#pragma once

/*
Port of class MaterialColorList from TextSecure-android
*/

// [x] done
// TFS ID: 656

#include "MaterialColor.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\owntemplates\List.h"

class MaterialColorList
{
private:
  List<MaterialColor> colors;
public:
  virtual ~MaterialColorList() {}
  MaterialColorList() {}
  MaterialColorList(List<MaterialColor> colors)
  {
    this->colors = colors;
  }
  MaterialColor* Get(int index)
  {
    return this->colors.Get(index);
  }
  int Size()
  {
    return this->colors.Size();
  }
  MaterialColor* GetByColor(OsIndependentContext* context, int colorValue)
  {
    for (MaterialColor color : colors)
    {
      if (color.Represents(context, colorValue))
      {
        return &color;
      }
    }
    return nullptr;
  }
  int* AsConversationColorArray(OsIndependentContext* context)
  {
    int* results = new int[this->colors.Size()];
    int index = 0;
    for (MaterialColor color : colors)
    {
      results[index++] = color.ToConversationColor(context);
    }
    return results;
  }
};
