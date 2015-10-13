#pragma once

/*
Port of TextSecurePreferences.java from TextSecure-android
*/

// [x] done
// TFS ID: 245

#include <set>
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\owntemplates\Set.h"
#include "..\preferences\NotificationPrivacyPreference.h"
#include "..\..\Factory\Factory.h"

class TextSecurePreferences
{
private:
  static const OsIndependentString* TAG;

public:
  static const OsIndependentString* IDENTITY_PREF;
  static const OsIndependentString* CHANGE_PASSPHRASE_PREF;
  static const OsIndependentString* DISABLE_PASSPHRASE_PREF;
  static const OsIndependentString* THEME_PREF;
  static const OsIndependentString* LANGUAGE_PREF;
  static const OsIndependentString* MMSC_CUSTOM_HOST_PREF;
  static const OsIndependentString* MMSC_HOST_PREF;
  static const OsIndependentString* MMSC_CUSTOM_PROXY_PREF;
  static const OsIndependentString* MMSC_PROXY_HOST_PREF;
  static const OsIndependentString* MMSC_CUSTOM_PROXY_PORT_PREF;
  static const OsIndependentString* MMSC_PROXY_PORT_PREF;
  static const OsIndependentString* MMSC_CUSTOM_USERNAME_PREF;
  static const OsIndependentString* MMSC_USERNAME_PREF;
  static const OsIndependentString* MMSC_CUSTOM_PASSWORD_PREF;
  static const OsIndependentString* MMSC_PASSWORD_PREF;
  static const OsIndependentString* THREAD_TRIM_LENGTH;
  static const OsIndependentString* THREAD_TRIM_NOW;
  static const OsIndependentString* ENABLE_MANUAL_MMS_PREF;

  static const OsIndependentString* LAST_VERSION_CODE_PREF;
  static const OsIndependentString* RINGTONE_PREF;
  static const OsIndependentString* VIBRATE_PREF;
  static const OsIndependentString* NOTIFICATION_PREF;
  static const OsIndependentString* LED_COLOR_PREF;
  static const OsIndependentString* LED_BLINK_PREF;
  static const OsIndependentString* LED_BLINK_PREF_CUSTOM;
  static const OsIndependentString* ALL_MMS_PREF;
  static const OsIndependentString* ALL_SMS_PREF;
  static const OsIndependentString* PASSPHRASE_TIMEOUT_INTERVAL_PREF;
  static const OsIndependentString* PASSPHRASE_TIMEOUT_PREF;
  static const OsIndependentString* SCREEN_SECURITY_PREF;
  static const OsIndependentString* ENTER_SENDS_PREF;
  static const OsIndependentString* ENTER_PRESENT_PREF;
  static const OsIndependentString* SMS_DELIVERY_REPORT_PREF;
  static const OsIndependentString* MMS_USER_AGENT;
  static const OsIndependentString* MMS_CUSTOM_USER_AGENT;
  static const OsIndependentString* THREAD_TRIM_ENABLED;
  static const OsIndependentString* LOCAL_NUMBER_PREF;
  static const OsIndependentString* VERIFYING_STATE_PREF;
  static const OsIndependentString* REGISTERED_GCM_PREF;
  static const OsIndependentString* GCM_PASSWORD_PREF;
  static const OsIndependentString* PROMPTED_PUSH_REGISTRATION_PREF;
  static const OsIndependentString* PROMPTED_DEFAULT_SMS_PREF;
  static const OsIndependentString* SIGNALING_KEY_PREF;
  static const OsIndependentString* DIRECTORY_FRESH_TIME_PREF;
  static const OsIndependentString* IN_THREAD_NOTIFICATION_PREF;

  static const OsIndependentString* LOCAL_REGISTRATION_ID_PREF;
  static const OsIndependentString* SIGNED_PREKEY_REGISTERED_PREF;
  static const OsIndependentString* WIFI_SMS_PREF;

  static const OsIndependentString* GCM_REGISTRATION_ID_PREF;
  static const OsIndependentString* GCM_REGISTRATION_ID_VERSION_PREF;
  static const OsIndependentString* WEBSOCKET_REGISTERED_PREF;
  static const OsIndependentString* RATING_LATER_PREF;
  static const OsIndependentString* RATING_ENABLED_PREF;

  static const OsIndependentString* REPEAT_ALERTS_PREF;
  static const OsIndependentString* NOTIFICATION_PRIVACY_PREF;

  static const OsIndependentString* MEDIA_DOWNLOAD_MOBILE_PREF;
  static const OsIndependentString* MEDIA_DOWNLOAD_WIFI_PREF;
  static const OsIndependentString* MEDIA_DOWNLOAD_ROAMING_PREF;

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
  static void SetGcmRegistrationId(OsIndependentContext* context, OsIndependentString* registrationId);
  static OsIndependentString* GetGcmRegistrationId(OsIndependentContext* context);
  static bool IsSmsEnabled(OsIndependentContext* context);
  static int GetLocalRegistrationId(OsIndependentContext* context);
  static void SetLocalRegistrationId(OsIndependentContext* context, int registrationId);
  static bool IsInThreadNotifications(OsIndependentContext* context);
  static long GetDirectoryRefreshTime(OsIndependentContext* context);
  static void SetDirectoryRefreshTime(OsIndependentContext* context, long value);
  static OsIndependentString* GetLocalNumber(OsIndependentContext* context);
  static void SetLocalNumber(OsIndependentContext* context, OsIndependentString* localNumber);
  static OsIndependentString* GetPushServerPassword(OsIndependentContext* context);
  static void SetPushServerPassword(OsIndependentContext* context, OsIndependentString* password);
  static void SetSignalingKey(OsIndependentContext* context, OsIndependentString* signalingKey);
  static OsIndependentString* GetSignalingKey(OsIndependentContext* context);
  static bool IsEnterImeKeyEnabled(OsIndependentContext* context);
  static bool IsEnterSendsEnabled(OsIndependentContext* context);
  static bool IsPasswordDisabled(OsIndependentContext* context);
  static void SetPasswordDisabled(OsIndependentContext* context, bool disabled);
  static bool GetUseCustomMmsc(OsIndependentContext* context);
  static void SetUseCustomMmsc(OsIndependentContext* context, bool value);
  static OsIndependentString* GetMmscUrl(OsIndependentContext* context);
  static void SetMmscUrl(OsIndependentContext* context, OsIndependentString* mmsc);
  static bool GetUseCustomMmscProxy(OsIndependentContext* context);
  static void SetUseCustomMmscProxy(OsIndependentContext* context, bool value);
  static OsIndependentString* GetMmscProxy(OsIndependentContext* context);
  static void SetMmscProxy(OsIndependentContext* context, OsIndependentString* value);
  static bool GetUseCustomMmscProxyPort(OsIndependentContext* context);
  static void SetUseCustomMmscProxyPort(OsIndependentContext* context, bool value);
  static OsIndependentString* GetMmscProxyPort(OsIndependentContext* context);
  static void SetMmscProxyPort(OsIndependentContext* context, OsIndependentString* value);
  static bool GetUseCustomMmscUsername(OsIndependentContext* context);
  static void SetUseCustomMmscUsername(OsIndependentContext* context, bool value);
  static OsIndependentString* GetMmscUsername(OsIndependentContext* context);
  static void SetMmscUsername(OsIndependentContext* context, OsIndependentString* value);
  static bool GetUseCustomMmscPassword(OsIndependentContext* context);
  static void SetUseCustomMmscPassword(OsIndependentContext* context, bool value);
  static OsIndependentString* GetMmscPassword(OsIndependentContext* context);
  static void SetMmscPassword(OsIndependentContext* context, OsIndependentString* value);
  static OsIndependentString* GetMmsUserAgent(OsIndependentContext* context, OsIndependentString* defaultUserAgent);
  static OsIndependentString* GetIdentityContactUri(OsIndependentContext* context);
  static void SetIdentityContactUri(OsIndependentContext* context, OsIndependentString* identityUri);
  static bool IsScreenSecurityEnabled(OsIndependentContext* context);
  static bool IsLegacyUseLocalApnsEnabled(OsIndependentContext* context);
  static int GetLastVersionCode(OsIndependentContext* context);
  static void SetLastVersionCode(OsIndependentContext* context, int versionCode); /*throws IOException*/
  static OsIndependentString* GetTheme(OsIndependentContext* context);
  static bool IsVerifying(OsIndependentContext* context);
  static void SetVerifying(OsIndependentContext* context, bool verifying);
  static bool IsPushRegistered(OsIndependentContext* context);
  static void SetPushRegistered(OsIndependentContext* context, bool registered);
  static bool IsPassphraseTimeoutEnabled(OsIndependentContext* context);
  static int GetPassphraseTimeoutInterval(OsIndependentContext* context);
  static void SetPassphraseTimeoutInterval(OsIndependentContext* context, int interval);
  static OsIndependentString* GetLanguage(OsIndependentContext* context);
  static void SetLanguage(OsIndependentContext* context, OsIndependentString* language);
  static bool IsSmsDeliveryReportsEnabled(OsIndependentContext* context);
  static bool HasPromptedPushRegistration(OsIndependentContext* context);
  static void SetPromptedPushRegistration(OsIndependentContext* context, bool value);
  static bool HasPromptedDefaultSmsProvider(OsIndependentContext* context);
  static void SetPromptedDefaultSmsProvider(OsIndependentContext* context, bool value);
  static bool IsInterceptAllMmsEnabled(OsIndependentContext* context);
  static bool IsInterceptAllSmsEnabled(OsIndependentContext* context);
  static bool IsNotificationsEnabled(OsIndependentContext* context);
  static OsIndependentString* GetNotificationRingtone(OsIndependentContext* context);
  static bool IsNotificationVibrateEnabled(OsIndependentContext* context);
  static OsIndependentString* GetNotificationLedColor(OsIndependentContext* context);
  static OsIndependentString* GetNotificationLedPattern(OsIndependentContext* context);
  static OsIndependentString* GetNotificationLedPatternCustom(OsIndependentContext* context);
  static void SetNotificationLedPatternCustom(OsIndependentContext* context, OsIndependentString* pattern);
  static bool IsThreadLengthTrimmingEnabled(OsIndependentContext* context);
  static int GetThreadTrimLength(OsIndependentContext* context);
  static std::set<OsIndependentString*>* GetMobileMediaDownloadAllowed(OsIndependentContext* context);
  static std::set<OsIndependentString*>* GetWifiMediaDownloadAllowed(OsIndependentContext* context);
  static std::set<OsIndependentString*>* GetRoamingMediaDownloadAllowed(OsIndependentContext* context);
private:
  static std::set<OsIndependentString*>* GetMediaDownloadAllowed(OsIndependentContext* context, OsIndependentString* key, /*@ArrayRes*/ int defaultValuesRes);
public:
  static void SetBooleanPreference(OsIndependentContext* context, OsIndependentString* key, bool value);
  static bool GetBooleanPreference(OsIndependentContext* context, OsIndependentString* key, bool defaultValue);
  static void SetStringPreference(OsIndependentContext* context, OsIndependentString* key, OsIndependentString* value);
  static OsIndependentString* GetStringPreference(OsIndependentContext* context, OsIndependentString* key, OsIndependentString* defaultValue);
  static int GetIntegerPreference(OsIndependentContext* context, OsIndependentString* key, int defaultValue);
  static void SetIntegerPrefrence(OsIndependentContext* context, OsIndependentString* key, int value);
  static bool SetIntegerPrefrenceBlocking(OsIndependentContext* context, OsIndependentString* key, int value);
  static long GetLongPreference(OsIndependentContext* context, OsIndependentString* key, long defaultValue);
  static void SetLongPreference(OsIndependentContext* context, OsIndependentString* key, long value);
  static std::set<OsIndependentString*>* GetStringSetPreference(OsIndependentContext* context, OsIndependentString* key, std::set<OsIndependentString*>* defaultValues);
};
