#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.Uri
  http://developer.android.com/reference/android/net/Uri.html
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/Uri.java#Uri
*/

// [ ] done
// TFS ID: 327

#include "OsIndependentParcelable.h"

// public abstract class  [More ...] Uri implements Parcelable, Comparable<Uri> {
class OsIndependentUri : OsIndependentParcelable
{
private:
public:
  //public static Uri parse(String uriString) {
  virtual OsIndependentUri* Parse(unsigned char* uriString) = 0;
};
/*
needs no Factory, because is abstract
*/
