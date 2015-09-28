#pragma once
/*
Port of class EmojiPageModel from TextSecure-android
*/

// [x] done
// TFS ID: 409

#include "..\..\..\osindependent\OsIndependentString.h"

//interface EmojiPageModel
class EmojiPageModel
{
  virtual int GetIconAttr() = 0;
  virtual List<OsIndependentString*>* GetEmoji() = 0;
  virtual bool HasSpriteMap() = 0;
  virtual OsIndependentString* GetSprite() = 0;
  virtual bool IsDynamic() = 0;
};
