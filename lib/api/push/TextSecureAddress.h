#pragma once
/*
Port of class SendMessageResponse from TextSecure-android
*/

// [x] done
// TFS ID: 286

class TextSecureAddress
{
public:
  static const int DEFAULT_DEVICE_ID = 1;
private:
  const unsigned char* e164number;
  const unsigned char* relay;
public:
  TextSecureAddress(unsigned char* e164number, unsigned char* relay);
  TextSecureAddress(unsigned char* e164number);
  const unsigned char* GetNumber() { return this->e164number; }
  const unsigned char* GetRelay() { return this->relay; }
//  //@Override
//  bool equals(Object other);
//  //@Override
//  int hashCode();
//private:
//  // TODO override operatoe = if needed
//  bool equals(unsigned char* one, unsigned char* two);
};
