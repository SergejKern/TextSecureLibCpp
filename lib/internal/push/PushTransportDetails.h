#pragma once
/*
Port of class PushTransportDetails from TextSecure-android
*/

// [ ] done
// TFS ID: 353

//import org.whispersystems.libaxolotl.logging.Log;

class PushTransportDetails
{
private:
  static const unsigned char* TAG;
  const int messageVersion;

public:
  PushTransportDetails(int messageVersion);
  char* GetStrippedPaddingMessageBody(char* messageWithPadding);
  char* GetPaddedMessageBody(char* messageBody);
private:
  int GetPaddedMessageLength(int messageLength);
};

const unsigned char* PushTransportDetails::TAG = "PushTransportDetails";
