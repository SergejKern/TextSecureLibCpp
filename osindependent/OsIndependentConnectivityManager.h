#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.ConnectivityManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/ConnectivityManager.java#ConnectivityManager
*/

// [ ] done
// TFS ID: 672

#include "OsIndependentNetworkInfo.h"

class OsIndependentConnectivityManager
{
private:
public:
  virtual OsIndependentNetworkInfo* GetActiveNetworkInfo() = 0;
};
