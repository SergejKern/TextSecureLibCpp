#pragma once

/*
Port of RedPhoneCallTypes.java from TextSecure-android
*/

// [x] done
// TFS ID: 248

#include "..\..\osindependent\OsIndependentContext.h"
#include "TextSecurePreferences.h"
#include "Util.h"
//import android.content.pm.PackageManager;

//import java.io.IOException;

class VersionTracker
{
public:
  static int GetLastSeenVersion(OsIndependentContext* context)
  {
    return TextSecurePreferences::GetLastVersionCode(context);
  }

  static void UpdateLastSeenVersion(OsIndependentContext* context)
  {
    //try TODO exceptions
    //{
      int currentVersionCode = Util::GetCurrentApkReleaseVersion(context);
      TextSecurePreferences::SetLastVersionCode(context, currentVersionCode);
    //}
    //catch (IOException ioe)
    //{
    //  throw new AssertionError(ioe);
    //}
  }
};
