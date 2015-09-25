#pragma once
/*
Port of class OutgoingPushMessage from TextSecure-android
*/

// [x] done
// TFS ID: 342

//import com.fasterxml.jackson.annotation.JsonProperty;

class OutgoingPushMessage
{
private:
  //@JsonProperty
  int type;
  //@JsonProperty
  int destinationDeviceId;
  //@JsonProperty
  int destinationRegistrationId;
  //@JsonProperty
  unsigned char* body;
  //@JsonProperty
  unsigned char* content;

public:
  OutgoingPushMessage(int type, int destinationDeviceId, int destinationRegistrationId, unsigned char* legacyMessage, unsigned char* content)
  {
    this->type = type;
    this->destinationDeviceId = destinationDeviceId;
    this->destinationRegistrationId = destinationRegistrationId;
    this->body = legacyMessage;
    this->content = content;
  }
};
