#pragma once
/*
Port of class DeviceInfo from TextSecure-android
*/

// [x] done
// TFS ID: 280

//import com.fasterxml.jackson.annotation.JsonProperty;

class DeviceInfo
{
private:
  //@JsonProperty
  long id;
  //@JsonProperty
  unsigned char* name;
  //@JsonProperty
  long created;
  //@JsonProperty
  long lastSeen;
public:
  DeviceInfo() {}
  long GetId() { return this->id; }
  unsigned char* GetName() { return this->name; }
  long GetCreated() { return this->created; }
  long GetLastSeen() { return this->lastSeen; }
};
