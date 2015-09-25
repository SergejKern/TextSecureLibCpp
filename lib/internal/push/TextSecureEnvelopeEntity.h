#pragma once
/*
Port of class TextSecureEnvelopeEntityList from TextSecure-android
*/

// [x] done
// TFS ID: 356

//import com.fasterxml.jackson.annotation.JsonProperty;

class TextSecureEnvelopeEntity
{
private:
  //@JsonProperty
  int type;
  //@JsonProperty
  unsigned char* relay;
  //@JsonProperty
  long timestamp;
  //@JsonProperty
  unsigned char* source;
  //@JsonProperty
  int sourceDevice;
  //@JsonProperty
  char* message;
  //@JsonProperty
  char* content;
public:
  TextSecureEnvelopeEntity() {}
  int GetType() { return this->type; }
  unsigned char* GetRelay() { return this->relay; }
  long GetTimestamp() { return this->timestamp; }
  unsigned char* GetSource() { return this->source; }
  int GetSourceDevice() { return this->sourceDevice; }
  char* GetMessage() { return this->message; }
  char* GetContent() { return this->content; }
};
