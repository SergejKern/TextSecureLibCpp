#pragma once
/*
Port of class EmojiPages from TextSecure-android
*/

// [x] done
// TFS ID: 410

#include "..\..\R.h"
#include "EmojiPageModel.h"
#include "StaticEmojiPageModel.h"
#include "..\..\..\owntemplates\List.h"

class EmojiPages
{
public:
  List<EmojiPageModel*>* PAGES;
  EmojiPages();
};
