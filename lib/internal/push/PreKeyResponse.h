#pragma once
/*
Port of class PreKeyResponse from TextSecure-android
*/

// [x] done
// TFS ID: 345

#include "PreKeyResponseItem.h"

//import com.fasterxml.jackson.annotation.JsonProperty;
//import com.fasterxml.jackson.core.JsonGenerator;
//import com.fasterxml.jackson.core.JsonParser;
//import com.fasterxml.jackson.databind.DeserializationContext;
//import com.fasterxml.jackson.databind.JsonDeserializer;
//import com.fasterxml.jackson.databind.JsonSerializer;
//import com.fasterxml.jackson.databind.SerializerProvider;
//import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
//import com.fasterxml.jackson.databind.annotation.JsonSerialize;
//
#include "..\..\..\otherproject\IdentityKey.h"
//import org.whispersystems.libaxolotl.InvalidKeyException;
//import org.whispersystems.textsecure.internal.util.Base64;
//import org.whispersystems.textsecure.internal.util.JsonUtil;
//
//import java.io.IOException;
#include "..\..\..\owntemplates\List.h"

class PreKeyResponse
{
private:
  /*@JsonProperty
  @JsonSerialize(using = JsonUtil.IdentityKeySerializer.class)
  @JsonDeserialize(using = JsonUtil.IdentityKeyDeserializer.class)*/
  IdentityKey* identityKey;
  //@JsonProperty
  List<PreKeyResponseItem*>* devices;
public:
  IdentityKey* GetIdentityKey() { return this->identityKey; }
  List<PreKeyResponseItem*>* GetDevices() { return this->devices; }
};
