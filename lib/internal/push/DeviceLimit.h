#pragma once
/*
Port of class SendMessageResponse from TextSecure-android
*/

// [x] done
// TFS ID: 339

//import com.fasterxml.jackson.annotation.JsonProperty;

class DeviceLimit
{
private:
  //@JsonProperty
  int current;
  //@JsonProperty
  int max;
public:
  int GetCurrent() { return this->current; }
  int GetMax() { return this->max; }
};
