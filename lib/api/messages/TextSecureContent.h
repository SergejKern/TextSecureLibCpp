#pragma once
/*
Port of class TextSecureContent from TextSecure-android
*/

// [x] done
// TFS ID: 268

#include "multidevice\TextSecureSyncMessage.h";
#include "TextSecureDataMessage.h";

class TextSecureContent
{
private:
  TextSecureDataMessage* message;
  TextSecureSyncMessage* synchronizeMessage;
public:
  TextSecureContent()
  {
    this->message = nullptr;
    this->synchronizeMessage = nullptr;
  }
  TextSecureContent(TextSecureDataMessage* message)
  {
    this->message = message;
    this->synchronizeMessage = nullptr;
  }
  TextSecureContent(TextSecureSyncMessage* synchronizeMessage)
  {
    this->message = nullptr;
    this->synchronizeMessage = synchronizeMessage;
  }
  TextSecureDataMessage* GetDataMessage() { return this->message; }
  TextSecureSyncMessage* GetSyncMessage() { return this->synchronizeMessage; }
};
