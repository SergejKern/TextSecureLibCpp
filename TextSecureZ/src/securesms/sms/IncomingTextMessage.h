/* 
  Port of IncomingTextMessage.java from TextSecure-android
  */

#ifndef INCOMMINGTEXTMESSAGE_H_
#define INCOMMINGTEXTMESSAGE_H_

// package org.thoughtcrime.securesms.sms;

// import android.os.Parcel;
// import android.os.Parcelable;
// import android.telephony.SmsMessage;

// import org.thoughtcrime.securesms.util.GroupUtil;
// import org.whispersystems.libaxolotl.util.guava.Optional;
// import org.whispersystems.textsecure.api.messages.TextSecureGroup;
// import org.whispersystems.textsecure.api.push.TextSecureAddress;

// import java.util.List;

//public class IncomingTextMessage implements Parcelable
class IncomingTextMessage
{

/*  public static final Parcelable.Creator<IncomingTextMessage> CREATOR = new Parcelable.Creator<IncomingTextMessage>() {
    @Override
    public IncomingTextMessage createFromParcel(Parcel in) {
      return new IncomingTextMessage(in);
    }

    @Override
    public IncomingTextMessage[] newArray(int size) {
      return new IncomingTextMessage[size];
    }
  };
*/
private:
  String message;
  String sender;
  int senderDeviceId;
  int protocol;
  String serviceCenterAddress;
  bool replyPathPresent;
  String pseudoSubject;
  long sentTimestampMillis;
  String groupId;
  bool push;

protected:
  // Constructor from sender and group-id
  IncomingTextMessage(String sender, String groupId);
public:
  // Constructor from SmsMessage
  IncomingTextMessage(SmsMessage message);
  // Constructor from sender
  IncomingTextMessage(String sender, int senderDeviceId, long sentTimestampMillis, String encodedBody, Optional<TextSecureGroup> group);
  // Parcel in TIZEN?
  // public IncomingTextMessage(Parcel in);
  // Copy constructor
  IncomingTextMessage(IncomingTextMessage base, String newBody);
  // use c++templates?
  // public IncomingTextMessage(List<IncomingTextMessage> fragments);
  long GetSentTimestampMillis();
  String GetPseudoSubject();
  String GetMessageBody();
  IncomingTextMessage WithMessageBody(String message);
  String getSender();
  int GetSenderDeviceId();
  int GetProtocol();
  String GetServiceCenterAddress();
  bool IsReplyPathPresent();
  bool IsSecureMessage();
  bool IsPreKeyBundle();
  bool IsEndSession();
  bool IsPush();
  String GetGroupId();
  bool IsGroup();

  //@Override
  int DescribeContents();

  //@Override
  //void writeToParcel(Parcel out, int flags);
}


#endif
