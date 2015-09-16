
/* 
  Port of IncomingTextMessage.java from TextSecure-android
  */

#include "IncomingTextMessage.h"

// SmsMessage is Android class android.telephony.SmsMessage
/*IncomingTextMessage::IncomingTextMessage(SmsMessage* message)
{
  this->message              = message->getDisplayMessageBody();
  this->sender               = message->getDisplayOriginatingAddress();
  this->senderDeviceId       = TextSecureAddress::DEFAULT_DEVICE_ID;
  this->protocol             = message->getProtocolIdentifier();
  this->serviceCenterAddress = message->getServiceCenterAddress();
  this->replyPathPresent     = message->isReplyPathPresent();
  this->pseudoSubject        = message->getPseudoSubject();
  this->sentTimestampMillis  = message->getTimestampMillis();
  this->groupId              = null;
  this->push                 = false;
}*/

IncomingTextMessage::IncomingTextMessage(String sender, int senderDeviceId, long sentTimestampMillis, String encodedBody, Optional<TextSecureGroup>* group)
{
  this->message              = encodedBody;
  this->sender               = sender;
  this->senderDeviceId       = senderDeviceId;
  this->protocol             = 31337;
  this->serviceCenterAddress = "GCM";
  this->replyPathPresent     = true;
  this->pseudoSubject        = "";
  this->sentTimestampMillis  = sentTimestampMillis;
  this->push                 = true;

  if (group->isPresent())
  {
    this->groupId = GroupUtil.getEncodedId(group.get().getGroupId());
  }
  else
  {
    this->groupId = null;
  }
}

/*
IncomingTextMessage::IncomingTextMessage(Parcel in)
{
    this.message              = in.readString();
    this.sender               = in.readString();
    this.senderDeviceId       = in.readInt();
    this.protocol             = in.readInt();
    this.serviceCenterAddress = in.readString();
    this.replyPathPresent     = (in.readInt() == 1);
    this.pseudoSubject        = in.readString();
    this.sentTimestampMillis  = in.readLong();
    this.groupId              = in.readString();
    this.push                 = (in.readInt() == 1);
}
*/
IncomingTextMessage::IncomingTextMessage(IncomingTextMessage* base, String newBody)
{
  this->message              = newBody;
  this->sender               = base->getSender();
  this->senderDeviceId       = base->getSenderDeviceId();
  this->protocol             = base->getProtocol();
  this->serviceCenterAddress = base->getServiceCenterAddress();
  this->replyPathPresent     = base->isReplyPathPresent();
  this->pseudoSubject        = base->getPseudoSubject();
  this->sentTimestampMillis  = base->getSentTimestampMillis();
  this->groupId              = base->getGroupId();
  this->push                 = base->isPush();
}
/*
IncomingTextMessage::IncomingTextMessage(List<IncomingTextMessage> fragments)
{
    StringBuilder body = new StringBuilder();

    for (IncomingTextMessage message : fragments) {
      body.append(message.getMessageBody());
    }

    this.message              = body.toString();
    this.sender               = fragments.get(0).getSender();
    this.senderDeviceId       = fragments.get(0).getSenderDeviceId();
    this.protocol             = fragments.get(0).getProtocol();
    this.serviceCenterAddress = fragments.get(0).getServiceCenterAddress();
    this.replyPathPresent     = fragments.get(0).isReplyPathPresent();
    this.pseudoSubject        = fragments.get(0).getPseudoSubject();
    this.sentTimestampMillis  = fragments.get(0).getSentTimestampMillis();
    this.groupId              = fragments.get(0).getGroupId();
    this.push                 = fragments.get(0).isPush();
}
*/
IncomingTextMessage::IncomingTextMessage(String sender, String groupId)
{
  this->message              = "";
  this->sender               = sender;
  this->senderDeviceId       = TextSecureAddress::DEFAULT_DEVICE_ID;
  this->protocol             = 31338;
  this->serviceCenterAddress = "Outgoing";
  this->replyPathPresent     = true;
  this->pseudoSubject        = "";
                               // ???
  this->sentTimestampMillis  = System.currentTimeMillis();
  this->groupId              = groupId;
  this->push                 = true;
}

long IncomingTextMessage::getSentTimestampMillis()
{
  return this->sentTimestampMillis;
}

String IncomingTextMessage::GetPseudoSubject()
{
  return this->pseudoSubject;
}

String IncomingTextMessage::getMessageBody()
{
  return this->message;
}

IncomingTextMessage* IncomingTextMessage::WithMessageBody(String message)
{
  return new IncomingTextMessage(this, message);
}

String IncomingTextMessage::GetSender()
{
  return this->sender;
}

int IncomingTextMessage::GetSenderDeviceId()
{
  return this->senderDeviceId;
}

int IncomingTextMessage::GetProtocol()
{
  return protocol;
}

String IncomingTextMessage::GetServiceCenterAddress() {
  return this->serviceCenterAddress;
}

bool IncomingTextMessage::IsReplyPathPresent()
{
  return this->replyPathPresent;
}

booln IncomingTextMessage::IsSecureMessage()
{
  return false;
}

bool IncomingTextMessage::isPreKeyBundle()
{
  return false;
}

bool IncomingTextMessage::IsEndSession()
{
  return false;
}

bool IncomingTextMessage::IsPush()
{
  return this->push;
}

String IncomingTextMessage::GetGroupId()
{
  return this->groupId;
}

boolean IsGroup()
{
  return false;
}

//@Override
int IncomingTextMessage::describeContents()
{
  return 0;
}

/*  @Override
  public void writeToParcel(Parcel out, int flags) {
    out.writeString(message);
    out.writeString(sender);
    out.writeInt(senderDeviceId);
    out.writeInt(protocol);
    out.writeString(serviceCenterAddress);
    out.writeInt(replyPathPresent ? 1 : 0);
    out.writeString(pseudoSubject);
    out.writeLong(sentTimestampMillis);
    out.writeString(groupId);
    out.writeInt(push ? 1 : 0);
  }
*/
