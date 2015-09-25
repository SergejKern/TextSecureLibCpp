#pragma once
/*
Port of class AccountAttributes from TextSecure-android
*/

// [x] done
// TFS ID: 334

//import com.fasterxml.jackson.annotation.JsonProperty;

class AccountAttributes
{
private:
  //@JsonProperty
  unsigned char* signalingKey;

  //@JsonProperty
  bool supportsSms;

  //@JsonProperty
  int registrationId;

public:
  AccountAttributes(unsigned char* signalingKey, bool supportsSms, int registrationId)
  {
    this->signalingKey = signalingKey;
    this->supportsSms = supportsSms;
    this->registrationId = registrationId;
  }
  AccountAttributes() {}
  unsigned char* GetSignalingKey() { return this->signalingKey; }
  bool IsSupportsSms() { return this->supportsSms; }
  int GetRegistrationId() { return this->registrationId; }
};
