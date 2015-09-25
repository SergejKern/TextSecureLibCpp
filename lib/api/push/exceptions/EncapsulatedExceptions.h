#pragma once
/*
Port of class AuthorizationFailedException from TextSecure-android
*/

// [x] done
// TFS ID: 289

#include "..\..\crypto\UntrustedIdentityException.h"
#include "..\..\..\..\owntemplates\List.h"
#include "..\..\..\..\javastuff\Throwable.h"
#include "UnregisteredUserException.h"
#include "NetworkFailureException.h"

class EncapsulatedExceptions : Throwable
{
private:
  List<UntrustedIdentityException*>* untrustedIdentityExceptions;
  List<UnregisteredUserException*>* unregisteredUserExceptions;
  List<NetworkFailureException*>* networkExceptions;

public:
  EncapsulatedExceptions(List<UntrustedIdentityException*>* untrustedIdentities, List<UnregisteredUserException*>* unregisteredUsers, List<NetworkFailureException*>* networkExceptions)
  {
    this->untrustedIdentityExceptions = untrustedIdentities;
    this->unregisteredUserExceptions = unregisteredUsers;
    this->networkExceptions = networkExceptions;
  }
  EncapsulatedExceptions(UntrustedIdentityException* e)
  {
    this->untrustedIdentityExceptions = new LinkedList<UntrustedIdentityException*>();
    this->unregisteredUserExceptions = new LinkedList<UnregisteredUserException*>();
    this->networkExceptions = new LinkedList<NetworkFailureException*>();
    this->untrustedIdentityExceptions->Add(e);
  }
  List<UntrustedIdentityException*>* GetUntrustedIdentityExceptions() { return this->untrustedIdentityExceptions; }
  List<UnregisteredUserException*>* GetUnregisteredUserExceptions() { return this->unregisteredUserExceptions; }
  List<NetworkFailureException*>* GetNetworkExceptions() { return this->networkExceptions; }
};
