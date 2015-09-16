/* 
  Port of IncomingTextMessage.java from TextSecure-android
  */

#pragma once
#include "TextSecureGroup.h"

class IncomingTextMessage
{
private:
  char* message;
  char* sender;
  int senderDeviceId;
  int protocol;
  char* serviceCenterAddress;
  bool replyPathPresent;
  char* pseudoSubject;
  long sentTimestampMillis;
  char* groupId;
  bool push;
protected:
  // Constructor from sender and group-id
  IncomingTextMessage(char* sender, char* groupId);
public:
  // Constructor from SmsMessage
  // SmsMessage is Android class android.telephony.SmsMessage
  // IncomingTextMessage(SmsMessage message);
  // Constructor from sender
  IncomingTextMessage(char* sender, int senderDeviceId, long sentTimestampMillis, char* encodedBody, TextSecureGroup* group);
  // Parcel in TIZEN?
  // public IncomingTextMessage(Parcel in);
  // Copy constructor
  IncomingTextMessage(IncomingTextMessage base, char* newBody);
  // use c++templates?
  // public IncomingTextMessage(List<IncomingTextMessage> fragments);
  virtual ~IncomingTextMessage();

  long GetSentTimestampMillis();
  char* GetPseudoSubject();
  char* GetMessageBody();
  IncomingTextMessage WithMessageBody(char* message);
  char* getSender();
  int GetSenderDeviceId();
  int GetProtocol();
  char* GetServiceCenterAddress();
  bool IsReplyPathPresent();
  bool IsSecureMessage();
  bool IsPreKeyBundle();
  bool IsEndSession();
  bool IsPush();
  char* GetGroupId();
  bool IsGroup();

  //@Override
  int DescribeContents();

  //@Override
  //void writeToParcel(Parcel out, int flags);
};
