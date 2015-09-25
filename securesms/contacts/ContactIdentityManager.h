#pragma once
/*
Port of class ContactIdentityManager from TextSecure-android
*/

// [x] done
// TFS ID: 421

#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentUri.h"
//import android.os.Build;

#include "..\..\owntemplates\List.h"

class ContactIdentityManager
{
public:
  static ContactIdentityManager* GetInstance(OsIndependentContext* context)
  {
    // does not belong into os independent part!
    // 
    //if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH)
    //  return new ContactIdentityManagerICS(context);
    //else
    //  return new ContactIdentityManagerGingerbread(context);
  }
protected:
  OsIndependentContext* context;
public:
  ContactIdentityManager(OsIndependentContext* context)
  {
    this->context = context->GetApplicationContext();
  }
  virtual OsIndependentUri* GetSelfIdentityUri() = 0;
  virtual bool IsSelfIdentityAutoDetected() = 0;
  virtual List<long> GetSelfIdentityRawContactIds() = 0;
};
