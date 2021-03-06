#pragma once

/*
Port of MessageRecord.java from TextSecure-android
*/

// [ ] done
// TFS ID: 302

#include "DisplayRecord.h"
#include "..\..\recipients\Recipient.h"
#include "..\documents\NetworkFailure.h"
#include "..\documents\IdentityKeyMismatch.h"
#include "..\..\..\osindependent\OsIndependentContext.h"

class MessageRecord :
  public DisplayRecord
{
public:
  static const int DELIVERY_STATUS_NONE = 0;
  static const int DELIVERY_STATUS_RECEIVED = 1;
  static const int DELIVERY_STATUS_PENDING = 2;
  static const int DELIVERY_STATUS_FAILED = 3;
private:
  const int MAX_DISPLAY_LENGTH = 2000;
  Recipient* IndividualRecipient;
  const int RecipientDeviceId;
  const long Id;
  const int DeliveryStatus;
  const int ReceiptCount;
  IdentityKeyMismatch* MismatchesList;
  NetworkFailure* NetworkFailuresList;
public:
  virtual ~MessageRecord();

  MessageRecord(OsIndependentContext* context, long id, Body* body, Recipients* recipients,
    Recipient* individualRecipient, int recipientDeviceId,
    long dateSent, long dateReceived, long threadId,
    int deliveryStatus, int receiptCount, long type,
    IdentityKeyMismatch* mismatches,
    NetworkFailure* networkFailures);

  virtual bool IsMms() = 0;
  virtual bool IsMmsNotification() = 0;

  bool IsFailed();
  bool IsOutgoing();
  bool IsPending();
  bool IsSecure();
  bool IsLegacyMessage();
  bool IsAsymmetricEncryption();
  //@Override
  unsigned char* GetDisplayBody();
  long GetId();
  int GetDeliveryStatus();
  bool IsDelivered();
  bool IsPush();
  bool IsForcedSms();
  bool IsStaleKeyExchange();
  bool IsProcessedKeyExchange();
  bool IsPendingInsecureSmsFallback();
  bool IsIdentityMismatchFailure();
  bool IsBundleKeyExchange();
  bool IsIdentityUpdate();
  bool IsCorruptedKeyExchange();
  bool IsInvalidVersionKeyExchange();
  Recipient* GetIndividualRecipient();
  int GetRecipientDeviceId();
  long GetType();
  IdentityKeyMismatch* getIdentityKeyMismatches();
  NetworkFailure* GetNetworkFailures();
  bool HasNetworkFailures();

protected:
  unsigned char* emphasisAdded(unsigned char* sequence);

public:
  // override of java objects, comment out until needed
  // bool equals(void* other);
  // int hashCode();
};
