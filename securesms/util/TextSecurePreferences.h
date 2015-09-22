#pragma once

/*
Port of TextSecurePreferences.java from TextSecure-android
*/

// [ ] done
// TFS ID: 245

#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\owntemplates\Set.h"
#include "..\preferences\NotificationPrivacyPreference.h"

class TextSecurePreferences
{
private:
  static const unsigned char* TAG;

public:
  static const unsigned char* IDENTITY_PREF;
  static const unsigned char* CHANGE_PASSPHRASE_PREF;
  static const unsigned char* DISABLE_PASSPHRASE_PREF;
  static const unsigned char* THEME_PREF;
  static const unsigned char* LANGUAGE_PREF;
  static const unsigned char* MMSC_CUSTOM_HOST_PREF;
  static const unsigned char* MMSC_HOST_PREF;
  static const unsigned char* MMSC_CUSTOM_PROXY_PREF;
  static const unsigned char* MMSC_PROXY_HOST_PREF;
  static const unsigned char* MMSC_CUSTOM_PROXY_PORT_PREF;
  static const unsigned char* MMSC_PROXY_PORT_PREF;
  static const unsigned char* MMSC_CUSTOM_USERNAME_PREF;
  static const unsigned char* MMSC_USERNAME_PREF;
  static const unsigned char* MMSC_CUSTOM_PASSWORD_PREF;
  static const unsigned char* MMSC_PASSWORD_PREF;
  static const unsigned char* THREAD_TRIM_LENGTH;
  static const unsigned char* THREAD_TRIM_NOW;
  static const unsigned char* ENABLE_MANUAL_MMS_PREF;

  static const unsigned char* LAST_VERSION_CODE_PREF;
  static const unsigned char* RINGTONE_PREF;
  static const unsigned char* VIBRATE_PREF;
  static const unsigned char* NOTIFICATION_PREF;
  static const unsigned char* LED_COLOR_PREF;
  static const unsigned char* LED_BLINK_PREF;
  static const unsigned char* LED_BLINK_PREF_CUSTOM;
  static const unsigned char* ALL_MMS_PREF;
  static const unsigned char* ALL_SMS_PREF;
  static const unsigned char* PASSPHRASE_TIMEOUT_INTERVAL_PREF;
  static const unsigned char* PASSPHRASE_TIMEOUT_PREF;
  static const unsigned char* SCREEN_SECURITY_PREF;
  static const unsigned char* ENTER_SENDS_PREF;
  static const unsigned char* ENTER_PRESENT_PREF;
  static const unsigned char* SMS_DELIVERY_REPORT_PREF;
  static const unsigned char* MMS_USER_AGENT;
  static const unsigned char* MMS_CUSTOM_USER_AGENT;
  static const unsigned char* THREAD_TRIM_ENABLED;
  static const unsigned char* LOCAL_NUMBER_PREF;
  static const unsigned char* VERIFYING_STATE_PREF;
  static const unsigned char* REGISTERED_GCM_PREF;
  static const unsigned char* GCM_PASSWORD_PREF;
  static const unsigned char* PROMPTED_PUSH_REGISTRATION_PREF;
  static const unsigned char* PROMPTED_DEFAULT_SMS_PREF;
  static const unsigned char* SIGNALING_KEY_PREF;
  static const unsigned char* DIRECTORY_FRESH_TIME_PREF;
  static const unsigned char* IN_THREAD_NOTIFICATION_PREF;

  static const unsigned char* LOCAL_REGISTRATION_ID_PREF;
  static const unsigned char* SIGNED_PREKEY_REGISTERED_PREF;
  static const unsigned char* WIFI_SMS_PREF;

  static const unsigned char* GCM_REGISTRATION_ID_PREF;
  static const unsigned char* GCM_REGISTRATION_ID_VERSION_PREF;
  static const unsigned char* WEBSOCKET_REGISTERED_PREF;
  static const unsigned char* RATING_LATER_PREF;
  static const unsigned char* RATING_ENABLED_PREF;

  static const unsigned char* REPEAT_ALERTS_PREF;
  static const unsigned char* NOTIFICATION_PRIVACY_PREF;

  static const unsigned char* MEDIA_DOWNLOAD_MOBILE_PREF;
  static const unsigned char* MEDIA_DOWNLOAD_WIFI_PREF;
  static const unsigned char* MEDIA_DOWNLOAD_ROAMING_PREF;

public:
  static NotificationPrivacyPreference* GetNotificationPrivacy(OsIndependentContext* context);
  static long GetRatingLaterTimestamp(OsIndependentContext* context);
  static void SetRatingLaterTimestamp(OsIndependentContext* context, long timestamp);
  static bool IsRatingEnabled(OsIndependentContext* context);
  static void SetRatingEnabled(OsIndependentContext* context, bool enabled);
  static bool IsWebsocketRegistered(OsIndependentContext* context);
  static void SetWebsocketRegistered(OsIndependentContext* context, bool registered);
  static bool IsWifiSmsEnabled(OsIndependentContext* context);
  static int GetRepeatAlertsCount(OsIndependentContext* context);
  static void SetRepeatAlertsCount(OsIndependentContext* context, int count);
  static bool IsSignedPreKeyRegistered(OsIndependentContext* context);
  static void SetSignedPreKeyRegistered(OsIndependentContext* context, bool value);
  static void SetGcmRegistrationId(OsIndependentContext* context, unsigned char* registrationId);
  static unsigned char* GetGcmRegistrationId(OsIndependentContext* context);
  static bool IsSmsEnabled(OsIndependentContext* context);
  static int GetLocalRegistrationId(OsIndependentContext* context);
  static void SetLocalRegistrationId(OsIndependentContext* context, int registrationId);
  static bool IsInThreadNotifications(OsIndependentContext* context);
  static long GetDirectoryRefreshTime(OsIndependentContext* context);
  static void SetDirectoryRefreshTime(OsIndependentContext* context, long value);
  static unsigned char* GetLocalNumber(OsIndependentContext* context);
  static void SetLocalNumber(OsIndependentContext* context, unsigned char* localNumber);
  static unsigned char* GetPushServerPassword(OsIndependentContext* context);
  static void SetPushServerPassword(OsIndependentContext* context, unsigned char* password);
  static void SetSignalingKey(OsIndependentContext* context, unsigned char* signalingKey);
  static unsigned char* GetSignalingKey(OsIndependentContext* context);
  static bool IsEnterImeKeyEnabled(OsIndependentContext* context);
  static bool IsEnterSendsEnabled(OsIndependentContext* context);
  static bool IsPasswordDisabled(OsIndependentContext* context);
  static void SetPasswordDisabled(OsIndependentContext* context, bool disabled);
  static bool GetUseCustomMmsc(OsIndependentContext* context);
  static void SetUseCustomMmsc(OsIndependentContext* context, bool value);
  static unsigned char* GetMmscUrl(OsIndependentContext* context);
  static void SetMmscUrl(OsIndependentContext* context, unsigned char* mmsc);
  static bool GetUseCustomMmscProxy(OsIndependentContext* context);
  static void SetUseCustomMmscProxy(OsIndependentContext* context, bool value);
  static unsigned char* GetMmscProxy(OsIndependentContext* context);
  static void SetMmscProxy(OsIndependentContext* context, unsigned char* value);
  static bool GetUseCustomMmscProxyPort(OsIndependentContext* context);
  static void SetUseCustomMmscProxyPort(OsIndependentContext* context, bool value);
  static unsigned char* GetMmscProxyPort(OsIndependentContext* context);
  static void SetMmscProxyPort(OsIndependentContext* context, unsigned char* value);
  static bool GetUseCustomMmscUsername(OsIndependentContext* context);
  static void SetUseCustomMmscUsername(OsIndependentContext* context, bool value);
  static unsigned char* GetMmscUsername(OsIndependentContext* context);
  static void SetMmscUsername(OsIndependentContext* context, unsigned char* value);
  static bool GetUseCustomMmscPassword(OsIndependentContext* context);
  static void SetUseCustomMmscPassword(OsIndependentContext* context, bool value);
  static unsigned char* GetMmscPassword(OsIndependentContext* context);
  static void SetMmscPassword(OsIndependentContext* context, unsigned char* value);
  static unsigned char* GetMmsUserAgent(OsIndependentContext* context, unsigned char* defaultUserAgent);
  static unsigned char* GetIdentityContactUri(OsIndependentContext* context);
  static void SetIdentityContactUri(OsIndependentContext* context, unsigned char* identityUri);
  static bool IsScreenSecurityEnabled(OsIndependentContext* context);
  static bool IsLegacyUseLocalApnsEnabled(OsIndependentContext* context);
  static int GetLastVersionCode(OsIndependentContext* context);
  static void SetLastVersionCode(OsIndependentContext* context, int versionCode); /*throws IOException*/
  static unsigned char* GetTheme(OsIndependentContext* context);
  static bool IsVerifying(OsIndependentContext* context);
  static void SetVerifying(OsIndependentContext* context, bool verifying);
  static bool IsPushRegistered(OsIndependentContext* context);
  static void SetPushRegistered(OsIndependentContext* context, bool registered);
  static bool IsPassphraseTimeoutEnabled(OsIndependentContext* context);
  static int GetPassphraseTimeoutInterval(OsIndependentContext* context);
  static void SetPassphraseTimeoutInterval(OsIndependentContext* context, int interval);
  static unsigned char* GetLanguage(OsIndependentContext* context);
  static void SetLanguage(OsIndependentContext* context, unsigned char* language);
  static bool IsSmsDeliveryReportsEnabled(OsIndependentContext* context);
  static bool HasPromptedPushRegistration(OsIndependentContext* context);
  static void SetPromptedPushRegistration(OsIndependentContext* context, bool value);
  static bool HasPromptedDefaultSmsProvider(OsIndependentContext* context);
  static void SetPromptedDefaultSmsProvider(OsIndependentContext* context, bool value);
  static bool IsInterceptAllMmsEnabled(OsIndependentContext* context);
  static bool IsInterceptAllSmsEnabled(OsIndependentContext* context);
  static bool IsNotificationsEnabled(OsIndependentContext* context);
  static unsigned char* GetNotificationRingtone(OsIndependentContext* context);
  static bool IsNotificationVibrateEnabled(OsIndependentContext* context);
  static unsigned char* GetNotificationLedColor(OsIndependentContext* context);
  static unsigned char* GetNotificationLedPattern(OsIndependentContext* context);
  static unsigned char* GetNotificationLedPatternCustom(OsIndependentContext* context);
  static void SetNotificationLedPatternCustom(OsIndependentContext* context, unsigned char* pattern);
  static bool IsThreadLengthTrimmingEnabled(OsIndependentContext* context);
  static int GetThreadTrimLength(OsIndependentContext* context);
  static Set<unsigned char*> GetMobileMediaDownloadAllowed(OsIndependentContext* context);
  static Set<unsigned char*> GetWifiMediaDownloadAllowed(OsIndependentContext* context);
  static Set<unsigned char*> GetRoamingMediaDownloadAllowed(OsIndependentContext* context);
private:
  static Set<unsigned char*> GetMediaDownloadAllowed(OsIndependentContext* context, unsigned char* key, /*@ArrayRes*/ int defaultValuesRes);
public:
  static void SetBooleanPreference(OsIndependentContext* context, unsigned char* key, bool value);
  static bool GetBooleanPreference(OsIndependentContext* context, unsigned char* key, bool defaultValue);
  static void SetStringPreference(OsIndependentContext* context, unsigned char* key, unsigned char* value);
  static unsigned char* GetStringPreference(OsIndependentContext* context, unsigned char* key, unsigned char* defaultValue);
  static int GetIntegerPreference(OsIndependentContext* context, unsigned char* key, int defaultValue);
  static void SetIntegerPrefrence(OsIndependentContext* context, unsigned char* key, int value);
  static bool SetIntegerPrefrenceBlocking(OsIndependentContext* context, unsigned char* key, int value);
  static long GetLongPreference(OsIndependentContext* context, unsigned char* key, long defaultValue);
  static void SetLongPreference(OsIndependentContext* context, unsigned char* key, long value);
  static Set<unsigned char*> GetStringSetPreference(OsIndependentContext* context, unsigned char* key, Set<unsigned char*> defaultValues);
};
