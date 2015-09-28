#pragma once
/*
Port of class SmsDatabase from TextSecure-android
*/

// [x] done
// TFS ID: 418

#include "EmojiPageModel.h"

class StaticEmojiPageModel : EmojiPageModel
{
private:
  const int iconAttr;
  const unsigned char** emoji;
  const unsigned char* sprite;
public:
  StaticEmojiPageModel(int iconAttr, unsigned char** emoji, unsigned char* sprite)
    : iconAttr(iconAttr)
  {
    this->emoji = emoji;
    this->sprite = sprite;
  }
  //@Override
  virtual int GetIconAttr() { return iconAttr; }
  //@Override
  virtual const unsigned char** GetEmoji() { return this->emoji; }
  //@Override
  virtual bool HasSpriteMap() { return sprite != nullptr; }
  //@Override
  virtual const unsigned char* GetSprite() { return sprite; }
  //@Override
  virtual bool IsDynamic() { return false; }
};
