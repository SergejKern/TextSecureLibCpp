#pragma once
/*
Port of class SendMessageResponse from TextSecure-android
*/

// [x] done
// TFS ID: 354

class SendMessageResponse
{
private:
  bool needsSync;
public:
  SendMessageResponse() {}
  SendMessageResponse(bool needsSync)
  {
    this->needsSync = needsSync;
  }
  bool getNeedsSync() { return this->needsSync; }
};
