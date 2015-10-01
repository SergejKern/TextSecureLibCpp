#pragma once

/*
Port of BaseActivity.java from TextSecure-android
*/

// [x] done
// TFS ID: 692

//import android.os.Build;
//import android.os.Build.VERSION;
//import android.os.Build.VERSION_CODES;
//import android.support.annotation.NonNull;
#include "..\osindependent\OsIndependentFragmentActivity.h"
#include "..\osindependent\OsIndependentKeyEvent.h"

//public abstract class BaseActivity extends FragmentActivity {
class BaseActivity : public OsIndependentFragmentActivity
{
private:
  typedef OsIndependentFragmentActivity super;
public:
  //@Override
  virtual bool OnKeyDown(int keyCode, OsIndependentKeyEvent* event)
  {
    return (keyCode == OsIndependentKeyEvent::KEYCODE_MENU && IsMenuWorkaroundRequired()) || super::OnKeyDown(keyCode, event);
  }

  //@Override
  virtual bool OnKeyUp(int keyCode, OsIndependentKeyEvent* event)
  {
    if (keyCode == OsIndependentKeyEvent::KEYCODE_MENU && IsMenuWorkaroundRequired())
    {
      OpenOptionsMenu();
      return true;
    }
    return super::OnKeyUp(keyCode, event);
  }
  static bool IsMenuWorkaroundRequired()
  {
    return false;
    // hopefully no workaraound is required! We are not on android anymore
    //
    // return VERSION.SDK_INT < VERSION_CODES.KITKAT          &&
    //       VERSION.SDK_INT > VERSION_CODES.GINGERBREAD_MR1 &&
    //       ("LGE".equalsIgnoreCase(Build.MANUFACTURER) || "E6710".equalsIgnoreCase(Build.DEVICE));
  }
};
