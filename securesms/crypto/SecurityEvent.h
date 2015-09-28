#pragma once

/*
Port of SecurityEvent from TextSecure-android
*/

// [ ] done
// TFS ID: 454

#include "..\..\osindependent\OsIndependentString.h"
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentIntent.h"

#include "..\service\KeyCachingService.h"

/**
 * This class processes key exchange interactions.
 *
 * @author Moxie Marlinspike
 */
class SecurityEvent
{
public:
  static const OsIndependentString* SECURITY_UPDATE_EVENT;
  static void BroadcastSecurityUpdateEvent(OsIndependentContext* context)
  {
    BroadcastSecurityUpdateEvent(context, -2);
  }
  static void BroadcastSecurityUpdateEvent(OsIndependentContext* context, long threadId)
  {
    //                           TODO : OS SPECIFIC FACTORY
    OsIndependentIntent* intent = new OsIndependentIntent(SECURITY_UPDATE_EVENT);
    intent->PutExtra(new OsIndependentString("thread_id"), threadId);
    intent->SetPackage(context->GetPackageName());
    context->SendBroadcast(intent, (OsIndependentString*)KeyCachingService::KEY_PERMISSION);
  }
};

const OsIndependentString* SecurityEvent::SECURITY_UPDATE_EVENT = new OsIndependentString("org.thoughtcrime.securesms.KEY_EXCHANGE_UPDATE");
