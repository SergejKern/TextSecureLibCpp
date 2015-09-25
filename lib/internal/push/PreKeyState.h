#pragma once
/*
Port of class SendMessageResponse from TextSecure-android
*/

// [x] done
// TFS ID: 347

#include "PreKeyEntity.h"

//import com.fasterxml.jackson.annotation.JsonProperty;
//import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
//import com.fasterxml.jackson.databind.annotation.JsonSerialize;

#include "..\..\..\otherproject\IdentityKey.h"
#include "..\..\api\push\SignedPreKeyEntity.h"
//import org.whispersystems.textsecure.api.push.SignedPreKeyEntity;
//import org.whispersystems.textsecure.internal.util.JsonUtil;

#include "..\..\..\owntemplates\List.h"

class PreKeyState
{
private:
  //@JsonProperty
  //@JsonSerialize(using = JsonUtil.IdentityKeySerializer.class)
  //@JsonDeserialize(using = JsonUtil.IdentityKeyDeserializer.class)
  IdentityKey* identityKey;
  //@JsonProperty
  List<PreKeyEntity*>* preKeys;
  //@JsonProperty
  PreKeyEntity* lastResortKey;
  //@JsonProperty
  SignedPreKeyEntity* signedPreKey;
public:
  PreKeyState(List<PreKeyEntity*>* preKeys, PreKeyEntity* lastResortKey,
                     SignedPreKeyEntity* signedPreKey, IdentityKey* identityKey)
  {
    this->preKeys = preKeys;
    this->lastResortKey = lastResortKey;
    this->signedPreKey = signedPreKey;
    this->identityKey = identityKey;
  }
};
