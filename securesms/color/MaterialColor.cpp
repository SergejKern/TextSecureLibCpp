#include "MaterialColor.h"

int MaterialColor::ToConversationColor(OsIndependentContext* context)
{
  if (GetAttribute(context, R.attr.theme_type, "light").equals("dark"))
  {
    return context.getResources().getColor(conversationColorDark);
  }
  else {
    return context.getResources().getColor(conversationColorLight);
  }
}

  //public int toActionBarColor(@NonNull Context context) {
  //  if (getAttribute(context, R.attr.theme_type, "light").equals("dark")) {
  //    return context.getResources().getColor(actionBarColorDark);
  //  }
  //  else {
  //    return context.getResources().getColor(actionBarColorLight);
  //  }
  //}

  //public int toStatusBarColor(@NonNull Context context) {
  //  if (getAttribute(context, R.attr.theme_type, "light").equals("dark")) {
  //    return context.getResources().getColor(statusBarColorDark);
  //  }
  //  else {
  //    return context.getResources().getColor(statusBarColorLight);
  //  }
  //}

  //public boolean represents(Context context, int colorValue) {
  //  return context.getResources().getColor(conversationColorDark) == colorValue ||
  //    context.getResources().getColor(conversationColorLight) == colorValue ||
  //    context.getResources().getColor(actionBarColorDark) == colorValue ||
  //    context.getResources().getColor(actionBarColorLight) == colorValue ||
  //    context.getResources().getColor(statusBarColorLight) == colorValue ||
  //    context.getResources().getColor(statusBarColorDark) == colorValue;
  //}

  //public String serialize() {
  //  return serialized;
  //}

  //private String getAttribute(Context context, int attribute, String defaultValue) {
  //  TypedValue outValue = new TypedValue();

  //  if (context.getTheme().resolveAttribute(attribute, outValue, true)) {
  //    return outValue.coerceToString().toString();
  //  }
  //  else {
  //    return defaultValue;
  //  }
  //}


  //public static MaterialColor fromSerialized(String serialized) throws UnknownColorException{
  //  for (MaterialColor color : MaterialColor.values()) {
  //    if (color.serialized.equals(serialized)) return color;
  //  }

  //  throw new UnknownColorException("Unknown color: " + serialized);
  //}

  //  public static class UnknownColorException extends Exception {
  //  public UnknownColorException(String message) {
  //    super(message);
  //  }
  //}
};
