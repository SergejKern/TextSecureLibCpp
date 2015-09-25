#pragma once
/*
Port of class TextSecureEnvelopeEntityList from TextSecure-android
*/

// [x] done
// TFS ID: 357

// import org.whispersystems.textsecure.api.messages.TextSecureEnvelope; ??
#include "TextSecureEnvelopeEntity.h"
#include "..\..\..\owntemplates\List.h"

class TextSecureEnvelopeEntityList
{
private:
  List<TextSecureEnvelopeEntity*>* messages;
public:
  TextSecureEnvelopeEntityList() {}
  List<TextSecureEnvelopeEntity*>* GetMessages() { return this->messages; }
};
