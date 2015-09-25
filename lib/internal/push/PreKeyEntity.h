#pragma once
/*
Port of class PreKeyEntity from TextSecure-android
*/

// [ ] done
// TFS ID: 344

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
//import org.whispersystems.libaxolotl.InvalidKeyException;
//import org.whispersystems.libaxolotl.ecc.Curve;
//import org.whispersystems.libaxolotl.ecc.ECPublicKey;
//import org.whispersystems.textsecure.internal.util.Base64;
//
//import java.io.IOException;

class PreKeyEntity
{
private:
  //@JsonProperty
  int keyId;
  //@JsonProperty
  //@JsonSerialize(using = ECPublicKeySerializer.class)
  //@JsonDeserialize(using = ECPublicKeyDeserializer.class)
  ECPublicKey* publicKey;
public:
  PreKeyEntity() {}
  PreKeyEntity(int keyId, ECPublicKey* publicKey)
  {
    this->keyId = keyId;
    this->publicKey = publicKey;
  }
  int GetKeyId() { return this->keyId; }
  ECPublicKey* getPublicKey() {
    return publicKey;
  }
private:
  class ECPublicKeySerializer : JsonSerializer<ECPublicKey>
  {
  public:
    //@Override
    void Serialize(ECPublicKey value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
      gen.writeString(Base64.encodeBytesWithoutPadding(value.serialize()));
    }
  };
  class ECPublicKeyDeserializer : JsonDeserializer<ECPublicKey>
  {
  public:
    //@Override
    ECPublicKey* Deserialize(JsonParser p, DeserializationContext ctxt) throws IOException
    {
      try {
        return Curve.decodePoint(Base64.decodeWithoutPadding(p.getValueAsString()), 0);
      } catch (InvalidKeyException e) {
        throw new IOException(e);
      }
    }
  };
};
