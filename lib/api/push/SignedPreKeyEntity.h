#pragma once
/*
Port of class SignedPreKeyEntity from TextSecure-android
*/

// [ ] done
// TFS ID: 285

//import com.fasterxml.jackson.annotation.JsonProperty;
//import com.fasterxml.jackson.core.JsonGenerator;
//import com.fasterxml.jackson.core.JsonParser;
//import com.fasterxml.jackson.core.JsonProcessingException;
//import com.fasterxml.jackson.databind.DeserializationContext;
//import com.fasterxml.jackson.databind.JsonDeserializer;
//import com.fasterxml.jackson.databind.JsonSerializer;
//import com.fasterxml.jackson.databind.SerializerProvider;
//import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
//import com.fasterxml.jackson.databind.annotation.JsonSerialize;

//import org.whispersystems.libaxolotl.ecc.ECPublicKey;
#include "..\..\internal\push\PreKeyEntity.h"
//import org.whispersystems.textsecure.internal.util.Base64;
//
//import java.io.IOException;

class SignedPreKeyEntity : PreKeyEntity
{
private:
  //@JsonProperty
  //@JsonSerialize(using = ByteArraySerializer.class)
  //@JsonDeserialize(using = ByteArrayDeserializer.class)
  char* signature;

public:
  SignedPreKeyEntity() {}
  SignedPreKeyEntity(int keyId, ECPublicKey* publicKey, char* signature)
    : PreKeyEntity(keyId, publicKey)
  {
    this->signature = signature;
  }
  char* GetSignature() { return this->signature; }

private:
  class ByteArraySerializer : JsonSerializer<char*>
  {
  public:
    //@Override
    void Serialize(char* value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
      gen.writeString(Base64.encodeBytesWithoutPadding(value));
    }
  };

private:
  class ByteArrayDeserializer : JsonDeserializer<char*>
  {
  public:
    //@Override
    char* Deserialize(JsonParser p, DeserializationContext ctxt) throws IOException {
      return Base64.decodeWithoutPadding(p.getValueAsString());
    }
  };
};
