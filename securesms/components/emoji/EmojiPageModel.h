#pragma once
/*
Port of class EmojiPageModel from TextSecure-android
*/

// [x] done
// TFS ID: 409

//interface EmojiPageModel
class EmojiPageModel
{
  virtual int GetIconAttr() = 0;
  virtual const unsigned char** GetEmoji() = 0;
  virtual bool HasSpriteMap() = 0;
  virtual const unsigned char* GetSprite() = 0;
  virtual bool IsDynamic() = 0;
};
