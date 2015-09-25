#pragma once
/*
Port of class AuthorizationFailedException from TextSecure-android
*/

// [x] done
// TFS ID: 289

#include "..\..\..\otherproject\IdentityKey.h"
#include "..\..\..\javastuff\Exception.h"

class UntrustedIdentityException : public Exception
{
private:
  IdentityKey* identityKey;
  const unsigned char* e164number;
public:
  UntrustedIdentityException(unsigned char* s, unsigned char* e164number, IdentityKey* identityKey)
    : Exception(s)
  {
    this->e164number = e164number;
    this->identityKey = identityKey;
  }
  UntrustedIdentityException(UntrustedIdentityException* e)
    : Exception(e->GetMessage())
  {
    this->e164number = e->GetE164Number();
    this->identityKey = e->GetIdentityKey();
  }
  IdentityKey* GetIdentityKey() { return this->identityKey; }
  const unsigned char* GetE164Number() { return this->e164number; }
};
