#pragma once
/*
Port of class PreKeyStatus from TextSecure-android
*/

// [x] done
// TFS ID: 348

//import com.fasterxml.jackson.annotation.JsonProperty;

class PreKeyStatus
{
private:
  //@JsonProperty
  int count;
public:
  PreKeyStatus() {}
  int GetCount() { return this->count; }
};
