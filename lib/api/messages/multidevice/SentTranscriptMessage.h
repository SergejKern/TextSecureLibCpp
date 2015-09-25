#pragma once
/*
Port of class SentTranscriptMessage from TextSecure-android
*/

// [x] done
// TFS ID: 282

#include "..\TextSecureDataMessage.h"

class SentTranscriptMessage
{
private:
  const unsigned char* destination;
  const long timestamp;
  TextSecureDataMessage* message;

public:
  SentTranscriptMessage(unsigned char* destination, long timestamp, TextSecureDataMessage* message)
    : timestamp(timestamp)
  {
    this->destination = destination;
    this->message = message;
  }
  SentTranscriptMessage(long timestamp, TextSecureDataMessage* message)
    : timestamp(timestamp)
  {
    this->destination = nullptr;
    this->message = message;
  }
  unsigned char* GetDestination()
  {
    return (unsigned char*)this->destination;
  }
  long GetTimestamp()
  {
    return this->timestamp;
  }
  TextSecureDataMessage* GetMessage()
  {
    return this->message;
  }
};
