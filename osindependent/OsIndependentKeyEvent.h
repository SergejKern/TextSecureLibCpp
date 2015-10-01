#pragma once
/*
  abstract class OsIndependentCursor to replace android.support.v4.app.FragmentActivity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/support/v4/app/FragmentActivity.java#FragmentActivity
*/

// [ ] done
// TFS ID: 757

#include "OsIndependentParcelable.h"

/*
public class  [More ...] KeyEvent extends InputEvent implements Parcelable {
*/
class OsIndependentKeyEvent : public OsIndependentParcelable
{
public:
  // TODO REFACTOR
  static const int KEYCODE_MENU = 82;
public:

};
