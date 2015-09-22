#pragma once

/*
Port of ServiceUtil.java from TextSecure-android
*/

// [x] done
// TFS ID: 239

#include "..\..\osindependent\OsIndependentActivity.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentConnectivityManager.h"
#include "..\..\osindependent\OsIndependentWindowManager.h"
#include "..\..\osindependent\OsIndependentInputMethodManager.h"

class ServiceUtil
{
public:
  static OsIndependentInputMethodManager* GetInputMethodManager(OsIndependentContext* context)
  {
    return (OsIndependentInputMethodManager*)context->GetSystemService((unsigned char*)OsIndependentContext::INPUT_METHOD_SERVICE);
  }
  static OsIndependentWindowManager* GetWindowManager(OsIndependentContext* context)
  {
    return (OsIndependentWindowManager*)context->GetSystemService((unsigned char*)OsIndependentActivity::WINDOW_SERVICE);
  }
  static OsIndependentConnectivityManager* GetConnectivityManager(OsIndependentContext* context)
  {
    return (OsIndependentConnectivityManager*)context->GetSystemService((unsigned char*)OsIndependentActivity::CONNECTIVITY_SERVICE);
  }
};
