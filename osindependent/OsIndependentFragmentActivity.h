#pragma once
/*
  abstract class OsIndependentCursor to replace android.support.v4.app.FragmentActivity
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/support/v4/app/FragmentActivity.java#FragmentActivity
*/

// [ ] done
// TFS ID: 756

#include "OsIndependentActivity.h"

/*
public class  [More ...] FragmentActivity extends Activity {
*/
class OsIndependentFragmentActivity : public OsIndependentActivity
{
public:
public:
  // public boolean  [More ...] onKeyDown(int keyCode, KeyEvent event) {
  virtual bool OnKeyDown(int keyCode, OsIndependentKeyEvent* event) = 0;
};
