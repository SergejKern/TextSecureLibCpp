#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.res.Resources
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/res/Resources.java#Resources
*/

// [ ] done
// TFS ID: 675

#include "OsIndependentDrawable.h"
#include "OsIndependentInputStream.h"

/*
public class Resources {
*/
class OsIndependentResources
{
public:
  // http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/res/Resources.java#Resources.Theme
  // public final class  [More ...] Theme {
  class Theme
  { };
public:
  //@Deprecated
  //@Nullable
  // public Drawable getDrawable(int id) throws NotFoundException {
  virtual OsIndependentDrawable* GetDrawable(int id) = 0;
  // @Nullable
  //public Drawable[More ...] getDrawable(int id, @Nullable Theme theme) throws NotFoundException{
  virtual OsIndependentDrawable* GetDrawable(int id, Theme* theme) = 0;
  virtual OsIndependentInputStream* OpenRawResource(int id) = 0;
};
