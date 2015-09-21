#pragma once
/*
Port of interface MmsSmsColumns from TextSecure-android
*/

// [x] done
// TFS ID: 475

class MmsSmsColumns
{
public:
  static const unsigned char* ID;
  static const unsigned char* NORMALIZED_DATE_SENT;
  static const unsigned char* NORMALIZED_DATE_RECEIVED;
  static const unsigned char* THREAD_ID;
  static const unsigned char* READ;
  static const unsigned char* BODY;
  static const unsigned char* ADDRESS;
  static const unsigned char* ADDRESS_DEVICE_ID;
  static const unsigned char* RECEIPT_COUNT;
  static const unsigned char* MISMATCHED_IDENTITIES;

  class Types
  {
  public:
    static const long TOTAL_MASK = 0xFFFFFFFF;
    // Base Types
    static const long BASE_TYPE_MASK = 0x1F;
    static const long BASE_INBOX_TYPE = 20;
    static const long BASE_OUTBOX_TYPE = 21;
    static const long BASE_SENDING_TYPE = 22;
    static const long BASE_SENT_TYPE = 23;
    static const long BASE_SENT_FAILED_TYPE = 24;
    static const long BASE_PENDING_SECURE_SMS_FALLBACK = 25;
    static const long BASE_PENDING_INSECURE_SMS_FALLBACK = 26;
    static const long BASE_DRAFT_TYPE = 27;
    static const long OUTGOING_MESSAGE_TYPES[];

    // Message attributes
    static const long MESSAGE_ATTRIBUTE_MASK = 0xE0;
    static const long MESSAGE_FORCE_SMS_BIT = 0x40;

    // Key Exchange Information
    static const long KEY_EXCHANGE_MASK = 0xFF00;
    static const long KEY_EXCHANGE_BIT = 0x8000;
    static const long KEY_EXCHANGE_STALE_BIT = 0x4000;
    static const long KEY_EXCHANGE_PROCESSED_BIT = 0x2000;
    static const long KEY_EXCHANGE_CORRUPTED_BIT = 0x1000;
    static const long KEY_EXCHANGE_INVALID_VERSION_BIT = 0x800;
    static const long KEY_EXCHANGE_BUNDLE_BIT = 0x400;
    static const long KEY_EXCHANGE_IDENTITY_UPDATE_BIT = 0x200;

    // Secure Message Information
    static const long SECURE_MESSAGE_BIT = 0x800000;
    static const long END_SESSION_BIT = 0x400000;
    static const long PUSH_MESSAGE_BIT = 0x200000;

    // Group Message Information
    static const long GROUP_UPDATE_BIT = 0x10000;
    static const long GROUP_QUIT_BIT = 0x20000;

    // Encrypted Storage Information
    static const long ENCRYPTION_MASK = 0xFF000000;
    static const long ENCRYPTION_SYMMETRIC_BIT = 0x80000000;
    static const long ENCRYPTION_ASYMMETRIC_BIT = 0x40000000;
    static const long ENCRYPTION_REMOTE_BIT = 0x20000000;
    static const long ENCRYPTION_REMOTE_FAILED_BIT = 0x10000000;
    static const long ENCRYPTION_REMOTE_NO_SESSION_BIT = 0x08000000;
    static const long ENCRYPTION_REMOTE_DUPLICATE_BIT = 0x04000000;
    static const long ENCRYPTION_REMOTE_LEGACY_BIT = 0x02000000;

  public:
    static bool IsDraftMessageType(long type);
    static bool IsFailedMessageType(long type);
    static bool IsOutgoingMessageType(long type);
    static bool IsForcedSms(long type);
    static bool IsPendingMessageType(long type);
    static bool IsPendingSmsFallbackType(long type);
    static bool IsPendingSecureSmsFallbackType(long type);
    static bool IsPendingInsecureSmsFallbackType(long type);
    static bool IsInboxType(long type);
    static bool IsSecureType(long type);
    static bool IsPushType(long type);
    static bool IsEndSessionType(long type);
    static bool IsKeyExchangeType(long type);
    static bool IsStaleKeyExchange(long type);
    static bool IsProcessedKeyExchange(long type);
    static bool IsCorruptedKeyExchange(long type);
    static bool IsInvalidVersionKeyExchange(long type);
    static bool IsBundleKeyExchange(long type);
    static bool IsIdentityUpdate(long type);
    static bool IsGroupUpdate(long type);
    static bool IsGroupQuit(long type);
    static bool IsSymmetricEncryption(long type);
    static bool IsAsymmetricEncryption(long type);
    static bool IsFailedDecryptType(long type);
    static bool IsDuplicateMessageType(long type);
    static bool IsDecryptInProgressType(long type);
    static bool IsNoRemoteSessionType(long type);
    static bool IsLegacyType(long type);
    static long TranslateFromSystemBaseType(long theirType);
    static int TranslateToSystemBaseType(long type);
  };
};

const unsigned char* MmsSmsColumns::ID = (unsigned char*)"_id";
const unsigned char* MmsSmsColumns::NORMALIZED_DATE_SENT = (unsigned char*)"date_sent";
const unsigned char* MmsSmsColumns::NORMALIZED_DATE_RECEIVED = (unsigned char*)"date_received";
const unsigned char* MmsSmsColumns::THREAD_ID = (unsigned char*)"thread_id";
const unsigned char* MmsSmsColumns::READ = (unsigned char*)"read";
const unsigned char* MmsSmsColumns::BODY = (unsigned char*)"body";
const unsigned char* MmsSmsColumns::ADDRESS = (unsigned char*)"address";
const unsigned char* MmsSmsColumns::ADDRESS_DEVICE_ID = (unsigned char*)"address_device_id";
const unsigned char* MmsSmsColumns::RECEIPT_COUNT = (unsigned char*)"delivery_receipt_count";
const unsigned char* MmsSmsColumns::MISMATCHED_IDENTITIES = (unsigned char*)"mismatched_identities";
const long MmsSmsColumns::Types::OUTGOING_MESSAGE_TYPES[] = 
{ 
  BASE_OUTBOX_TYPE, 
  BASE_SENT_TYPE,
  BASE_SENDING_TYPE, 
  BASE_SENT_FAILED_TYPE,
  BASE_PENDING_SECURE_SMS_FALLBACK,
  BASE_PENDING_INSECURE_SMS_FALLBACK
};
