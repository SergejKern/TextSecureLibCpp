#include "IdentityKeyMismatch.h"

IdentityKeyMismatch::~IdentityKeyMismatch()
{
}
IdentityKeyMismatch::IdentityKeyMismatch()
{
}
IdentityKeyMismatch::IdentityKeyMismatch(long recipientId, IdentityKey* identityKey)
{
  this->recipientId = recipientId;
  this->identityKey = identityKey;
}
long IdentityKeyMismatch::GetRecipientId()
{
  return this->recipientId;
}
IdentityKey* IdentityKeyMismatch::GetIdentityKey()
{
  return this->identityKey;
}
////@Override
//bool IdentityKeyMismatch::equals(Object other) {
//  if (other == null || !(other instanceof IdentityKeyMismatch)) {
//    return false;
//  }
//  IdentityKeyMismatch that = (IdentityKeyMismatch)other;
//  return that.recipientId == this.recipientId && that.identityKey.equals(this.identityKey);
//}
////@Override
//int IdentityKeyMismatch::hashCode()
//{
//  return (int)recipientId ^ identityKey.hashCode();
//}
