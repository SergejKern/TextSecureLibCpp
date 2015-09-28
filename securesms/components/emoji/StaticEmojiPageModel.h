#pragma once
/*
Port of class SmsDatabase from TextSecure-android
*/

// [x] done
// TFS ID: 418

#include "EmojiPageModel.h"

class StaticEmojiPageModel : public EmojiPageModel
{
private:
  const int iconAttr;
  List<OsIndependentString*>* emoji;
  OsIndependentString* sprite;
public:
  StaticEmojiPageModel(int iconAttr, List<OsIndependentString*>* emoji, OsIndependentString* sprite)
    : iconAttr(iconAttr)
  {
    this->emoji = emoji;
    this->sprite = sprite;
  }
  //@Override
  virtual int GetIconAttr() { return iconAttr; }
  //@Override
  virtual List<OsIndependentString*>* GetEmoji() { return this->emoji; }
  //@Override
  virtual bool HasSpriteMap() { return sprite != nullptr; }
  //@Override
  virtual OsIndependentString* GetSprite() { return sprite; }
  //@Override
  virtual bool IsDynamic() { return false; }
};
