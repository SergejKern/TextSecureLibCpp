#pragma once
/*
Port of class PreKeyResponseItem from TextSecure-android
*/

// [ ] done
// TFS ID: 346

//import com.fasterxml.jackson.annotation.JsonProperty;

//import org.whispersystems.textsecure.api.push.SignedPreKeyEntity;

class PreKeyResponseItem
{
private:
  //@JsonProperty
  int deviceId;
  //@JsonProperty
  int registrationId;
  //@JsonProperty
  SignedPreKeyEntity* signedPreKey;
  //@JsonProperty
  PreKeyEntity* preKey;
public:
  int GetDeviceId() { return this->deviceId; }
  int GetRegistrationId() { return this->registrationId; }
  SignedPreKeyEntity* GetSignedPreKey() { return this->signedPreKey; }
  PreKeyEntity* GetPreKey() { return this->preKey; }
};
