#include "NetworkFailure.h"

NetworkFailure::~NetworkFailure()
{
}
NetworkFailure::NetworkFailure(long recipientId)
{
  this->recipientId = recipientId;
}
NetworkFailure::NetworkFailure() {}
long NetworkFailure::GetRecipientId()
{
  return this->recipientId;
}
////@Override
//bool NetworkFailure::equals(void* other)
//{
//  if (other == null || !(other instanceof NetworkFailure)) return false;
//
//  NetworkFailure that = (NetworkFailure)other;
//  return this.recipientId == that.recipientId;
//}
////@Override
//int NetworkFailure::hashCode()
//{
//  return (int)recipientId;
//}
