#include "PushTransportDetails.h"

PushTransportDetails::PushTransportDetails(int messageVersion)
  : messageVersion(messageVersion)
{ }
char* PushTransportDetailsGetStrippedPaddingMessageBody(char* messageWithPadding)
{
  if (messageVersion < 2)
    throw new AssertionError("Unknown version: " + messageVersion);
  else if (messageVersion == 2)
    return messageWithPadding;
  int paddingStart = 0;
  for (int i = messageWithPadding.length - 1; i >= 0; i--)
  {
    if (messageWithPadding[i] == (char)0x80)
    {
      paddingStart = i;
      break;
    }
    else if (messageWithPadding[i] != (char)0x00)
    {
      //        Log.w(TAG, "Padding byte is malformed, returning unstripped padding.");
      return messageWithPadding;
    }
  }
  char* strippedMessage = new char[paddingStart];
  System::arraycopy(messageWithPadding, 0, strippedMessage, 0, strippedMessage.length);
  return strippedMessage;
}
char* PushTransportDetails::GetPaddedMessageBody(char* messageBody)
{
  if (messageVersion < 2) throw new AssertionError("Unknown version: " + messageVersion);
  else if (messageVersion == 2) return messageBody;

  // NOTE: This is dumb.  We have our own padding scheme, but so does the cipher.
  // The +1 -1 here is to make sure the Cipher has room to add one padding byte,
  // otherwise it'll add a full 16 extra bytes.
  char* paddedMessage = new byte[getPaddedMessageLength(messageBody.length + 1) - 1];
  System.arraycopy(messageBody, 0, paddedMessage, 0, messageBody.length);
  paddedMessage[messageBody.length] = (byte)0x80;

  return paddedMessage;
}
int PushTransportDetails::GetPaddedMessageLength(int messageLength)
{
  int messageLengthWithTerminator = messageLength + 1;
  int messagePartCount = messageLengthWithTerminator / 160;

  if (messageLengthWithTerminator % 160 != 0) {
    messagePartCount++;
  }

  return messagePartCount * 160;
}
