#pragma once
/*
Port of class ProvisioningMessage from TextSecure-android
*/

// [x] done
// TFS ID: 349

//import com.fasterxml.jackson.annotation.JsonProperty;

class ProvisioningMessage
{

  //@JsonProperty
private:
  unsigned char* body;

public:
  ProvisioningMessage(unsigned char* body)
  {
    this->body = body;
  }
};
