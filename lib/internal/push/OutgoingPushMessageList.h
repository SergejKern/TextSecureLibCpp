#pragma once
/*
Port of class OutgoingPushMessageList from TextSecure-android
*/

// [x] done
// TFS ID: 343

//import com.fasterxml.jackson.annotation.JsonProperty;

#include "..\..\..\owntemplates\List.h"
#include "OutgoingPushMessage.h"

class OutgoingPushMessageList
{
private:
  //@JsonProperty
  unsigned char* destination;
  //@JsonProperty
  unsigned char* relay;
  //@JsonProperty
  long timestamp;
  //@JsonProperty
  List<OutgoingPushMessage*>* messages;
public:
  OutgoingPushMessageList(unsigned char* destination, long timestamp, unsigned char* relay, List<OutgoingPushMessage*>* messages)
  {
    this->timestamp = timestamp;
    this->destination = destination;
    this->relay = relay;
    this->messages = messages;
  }
  unsigned char* GetDestination() { return this->destination; }
  List<OutgoingPushMessage*>* GetMessages() { return this->messages; }
  unsigned char* GetRelay() { return this->relay; }
  long GetTimestamp() { return this->timestamp; }
};
