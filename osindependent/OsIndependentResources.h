#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.res.Resources
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/graphics/drawable/Drawable.java#Drawable
*/

// [ ] done
// TFS ID: 675

#include "OsIndependentDrawable.h"

/*
public class Resources {
*/
class OsIndependentResources
{
public:
  // http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/res/Resources.java#Resources.Theme
  // public final class  [More ...] Theme {
  class Theme
  {

  };
public:
  //@Deprecated
  //@Nullable
  // public Drawable getDrawable(int id) throws NotFoundException {
  OsIndependentDrawable* GetDrawable(int id)
  {
    OsIndependentDrawable* d = GetDrawable(id, nullptr);
    return d;
  }
  // @Nullable
  //public Drawable[More ...] getDrawable(int id, @Nullable Theme theme) throws NotFoundException{
  OsIndependentDrawable* GetDrawable(int id, Theme* theme)
  {
  }
};
