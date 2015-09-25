#include "TextSecureAddress.h"

TextSecureAddress::TextSecureAddress(unsigned char* e164number, unsigned char* relay)
{
  this->e164number = e164number;
  this->relay = relay;
}
TextSecureAddress::TextSecureAddress(unsigned char* e164number)
{
  this->e164number = e164number;
  this->relay = nullptr;
}
////@Override
//bool TextSecureAddress::equals(Object other)
//{
//  if (other == null || !(other instanceof TextSecureAddress)) return false;
//
//  TextSecureAddress that = (TextSecureAddress)other;
//
//  return equals(this.e164number, that.e164number) &&
//    equals(this.relay, that.relay);
//}
////@Override
//int TextSecureAddress::hashCode()
//{
//  int hashCode = 0;
//
//  if (this.e164number != null) hashCode ^= this.e164number.hashCode();
//  if (this.relay.isPresent())  hashCode ^= this.relay.get().hashCode();
//
//  return hashCode;
//}
//// TODO override operatoe = if needed
//bool TextSecureAddress::equals(unsigned char* one, unsigned char* two)
//{
//  if (one == null) return two == null;
//  return one.equals(two);
//}
