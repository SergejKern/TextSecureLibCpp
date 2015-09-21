/*
Port of IncomingTextMessage.java from TextSecure-android
*/

#pragma once
#include "..\..\lib\api\messages\TextSecureGroup.h"

// [ ] done
// TFS ID: 196

class IncomingTextMessage
{
private:
  unsigned char* message;
  unsigned char* sender;
  int senderDeviceId;
  int protocol;
  unsigned char* serviceCenterAddress;
  bool replyPathPresent;
  char* pseudoSubject;
  long sentTimestampMillis;
  char* groupId;
  bool push;
protected:
  // Constructor from sender and group-id
  IncomingTextMessage(unsigned char* sender, unsigned char* groupId);
public:
  // Constructor from SmsMessage
  // SmsMessage is Android class android.telephony.SmsMessage
  // TODO OS SPECIFIC IncomingTextMessage(SmsMessage message);
  // Constructor from sender
  IncomingTextMessage(unsigned char* sender, int senderDeviceId, long sentTimestampMillis, unsigned char* encodedBody, TextSecureGroup* group);
  // Parcel in TIZEN?
  // public IncomingTextMessage(Parcel in);
  // Copy constructor
  IncomingTextMessage(IncomingTextMessage* base, unsigned char* newBody);
  // use c++templates?
  // public IncomingTextMessage(List<IncomingTextMessage> fragments);
  virtual ~IncomingTextMessage();

  long GetSentTimestampMillis();
  unsigned char* GetPseudoSubject();
  unsigned char* GetMessageBody();
  IncomingTextMessage* WithMessageBody(unsigned char* message);
  unsigned char* GetSender();
  int GetSenderDeviceId();
  int GetProtocol();
  unsigned char* GetServiceCenterAddress();
  bool IsReplyPathPresent();
  bool IsSecureMessage();
  bool IsPreKeyBundle();
  bool IsEndSession();
  bool IsPush();
  unsigned char* GetGroupId();
  bool IsGroup();

  //@Override
  int DescribeContents();

  //@Override
  //void writeToParcel(TODO OS SPECIFIC Parcel out, int flags);
};

