#pragma once

/*
Port of IdentityKeyMismatch from TextSecure-android
*/

// [ ] done
// TFS ID: 313

//import android.util.Log;
//
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
//import org.thoughtcrime.securesms.util.Base64;
#include "..\..\..\otherproject\IdentityKey.h"
//import org.whispersystems.libaxolotl.InvalidKeyException;
//
//import java.io.IOException;

class IdentityKeyMismatch
{
private:
  static class IdentityKeySerializer : JsonSerializer<IdentityKey>
  {
  public:
    //@Override
    void serialize(IdentityKey value, JsonGenerator jsonGenerator, SerializerProvider serializers)
      /*throws IOException*/
    {
      jsonGenerator.writeString(Base64.encodeBytes(value.serialize()));
    }
  };

  static class IdentityKeyDeserializer : JsonDeserializer<IdentityKey>
  {
  public:
    //@Override
    IdentityKey* deserialize(JsonParser jsonParser, DeserializationContext ctxt)
      /*throws IOException*/
    {
      try
      {
        return new IdentityKey(Base64.decode(jsonParser.getValueAsString()), 0);
      }
      catch (InvalidKeyException e)
      {
        Log.w(TAG, e);
        throw new IOException(e);
      }
    }
  };
public:
  virtual ~IdentityKeyMismatch();
private:
  static const unsigned char* TAG = "IdentityKeyMismatch";
  //@JsonProperty(value = "r")
  long recipientId;
  //@JsonProperty(value = "k")
  //@JsonSerialize(using = IdentityKeySerializer.class)
  //@JsonDeserialize(using = IdentityKeyDeserializer.class)
  IdentityKey* identityKey;
  IdentityKeyMismatch();
  IdentityKeyMismatch(long recipientId, IdentityKey* identityKey);
  long GetRecipientId();
  IdentityKey* GetIdentityKey();
  //@Override
  bool equals(Object other);
  //@Override
  int hashCode();
};
