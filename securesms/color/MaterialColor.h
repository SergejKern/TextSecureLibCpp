#pragma once

/*
Port of enum MaterialColor from TextSecure-android
*/

// [ ] done
// TFS ID: 371

#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\javastuff\Exception.h"

class MaterialColor
{
public:
  static /*const*/ MaterialColor* GREY; // TODO
  //RED(R.color.red_400, R.color.red_900, R.color.red_700, "red"),
  //  PINK(R.color.pink_400, R.color.pink_900, R.color.pink_700, "pink"),
  //  PURPLE(R.color.purple_400, R.color.purple_900, R.color.purple_700, "purple"),
  //  DEEP_PURPLE(R.color.deep_purple_400, R.color.deep_purple_900, R.color.deep_purple_700, "deep_purple"),
  //  INDIGO(R.color.indigo_400, R.color.indigo_900, R.color.indigo_700, "indigo"),
  //  BLUE(R.color.blue_500, R.color.blue_900, R.color.blue_700, "blue"),
  //  LIGHT_BLUE(R.color.light_blue_500, R.color.light_blue_900, R.color.light_blue_700, "light_blue"),
  //  CYAN(R.color.cyan_500, R.color.cyan_900, R.color.cyan_700, "cyan"),
  //  TEAL(R.color.teal_500, R.color.teal_900, R.color.teal_700, "teal"),
  //  GREEN(R.color.green_500, R.color.green_900, R.color.green_700, "green"),
  //  LIGHT_GREEN(R.color.light_green_600, R.color.light_green_900, R.color.light_green_700, "light_green"),
  //  LIME(R.color.lime_500, R.color.lime_900, R.color.lime_700, "lime"),
  //  YELLOW(R.color.yellow_500, R.color.yellow_900, R.color.yellow_700, "yellow"),
  //  AMBER(R.color.amber_600, R.color.amber_900, R.color.amber_700, "amber"),
  //  ORANGE(R.color.orange_500, R.color.orange_900, R.color.orange_700, "orange"),
  //  DEEP_ORANGE(R.color.deep_orange_500, R.color.deep_orange_900, R.color.deep_orange_700, "deep_orange"),
  //  BROWN(R.color.brown_500, R.color.brown_900, R.color.brown_700, "brown"),
  //  GREY(R.color.grey_500, R.color.grey_900, R.color.grey_700, "grey"),
  //  BLUE_GREY(R.color.blue_grey_500, R.color.blue_grey_900, R.color.blue_grey_700, "blue_grey"),

  //  GROUP(GREY.conversationColorLight, R.color.textsecure_primary, R.color.textsecure_primary_dark,
  //  GREY.conversationColorDark, R.color.gray95, R.color.black,
  //  "group_color");

private:
  const int conversationColorLight;
  const int actionBarColorLight;
  const int statusBarColorLight;
  const int conversationColorDark;
  const int actionBarColorDark;
  const int statusBarColorDark;
  const unsigned char* serialized;

  MaterialColor(int conversationColorLight, int actionBarColorLight,
    int statusBarColorLight, int conversationColorDark,
    int actionBarColorDark, int statusBarColorDark,
    unsigned char* serialized) 
    : conversationColorLight(conversationColorLight),
    actionBarColorLight(actionBarColorLight),
    statusBarColorLight(statusBarColorLight),
    conversationColorDark(conversationColorDark),
    actionBarColorDark(actionBarColorDark),
    statusBarColorDark(statusBarColorDark)
  {
    this->serialized = serialized;
  }

  MaterialColor(int lightColor, int darkColor, int statusBarColor, unsigned char* serialized)
    : conversationColorLight(lightColor),
    actionBarColorLight(lightColor),
    statusBarColorLight(statusBarColor),
    conversationColorDark(darkColor),
    actionBarColorDark(darkColor),
    statusBarColorDark(statusBarColor)
  {
    this->serialized = serialized;
  }
public:

  class UnknownColorException : Exception
  {
  public:
    UnknownColorException(unsigned char* message) : Exception(message)
    { }
  };
public:
  int ToConversationColor(OsIndependentContext* context);
  int ToActionBarColor(OsIndependentContext* context);
  int ToStatusBarColor(OsIndependentContext* context);
  bool Represents(OsIndependentContext* context, int colorValue);
  const unsigned char* Serialize() { return serialized; }
  unsigned char* GetAttribute(OsIndependentContext* context, int attribute, unsigned char* defaultValue);
  static MaterialColor* FromSerialized(unsigned char* serialized); /*throws UnknownColorException*/
};
