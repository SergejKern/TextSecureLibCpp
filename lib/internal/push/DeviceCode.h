#pragma once
/*
Port of class DeviceCode from TextSecure-android
*/

// [x] done
// TFS ID: 337

//import com.fasterxml.jackson.annotation.JsonProperty;

class DeviceCode
{
private:
  //@JsonProperty
  unsigned char* verificationCode;
public:
  unsigned char* GetVerificationCode()
  {
    return this->verificationCode;
  }
};
