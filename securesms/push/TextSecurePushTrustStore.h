#pragma once
/*
Port of class TextSecurePushTrustStore from TextSecure-android
*/

// [x] done
// TFS ID: 635

#include "..\..\osindependent\OsIndependentContext.h"

#include "..\R.h"

#include "..\..\lib\api\push\TrustStore.h"
#include "..\..\lib\internal\push\PushServiceSocket.h"

#include "..\..\osindependent\OsIndependentInputStream.h"

class TextSecurePushTrustStore : TrustStore
{
private:
  OsIndependentContext* context;
public:
  TextSecurePushTrustStore(OsIndependentContext* context)
  {
    this->context = context->GetApplicationContext();
  }
  //@Override
  OsIndependentInputStream* GetKeyStoreInputStream()
  {
    return context->GetResources()->OpenRawResource(R::Raw::whisper);
  }
  //@Override
  OsIndependentString* GetKeyStorePassword()
  {
    // TODO OS SPECIFIC FACTORY
    return new OsIndependentString("whisper");
  }
};
