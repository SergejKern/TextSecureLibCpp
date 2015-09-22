#include "TextSecurePreferences.h"

const unsigned char* TextSecurePreferences::TAG = "TextSecurePreferences";

const unsigned char* TextSecurePreferences::IDENTITY_PREF = "pref_choose_identity";
const unsigned char* TextSecurePreferences::CHANGE_PASSPHRASE_PREF = "pref_change_passphrase";
const unsigned char* TextSecurePreferences::DISABLE_PASSPHRASE_PREF = "pref_disable_passphrase";
const unsigned char* TextSecurePreferences::THEME_PREF = "pref_theme";
const unsigned char* TextSecurePreferences::LANGUAGE_PREF = "pref_language";
const unsigned char* TextSecurePreferences::MMSC_CUSTOM_HOST_PREF = "pref_apn_mmsc_custom_host";
const unsigned char* TextSecurePreferences::MMSC_HOST_PREF = "pref_apn_mmsc_host";
const unsigned char* TextSecurePreferences::MMSC_CUSTOM_PROXY_PREF = "pref_apn_mms_custom_proxy";
const unsigned char* TextSecurePreferences::MMSC_PROXY_HOST_PREF = "pref_apn_mms_proxy";
const unsigned char* TextSecurePreferences::MMSC_CUSTOM_PROXY_PORT_PREF = "pref_apn_mms_custom_proxy_port";
const unsigned char* TextSecurePreferences::MMSC_PROXY_PORT_PREF = "pref_apn_mms_proxy_port";
const unsigned char* TextSecurePreferences::MMSC_CUSTOM_USERNAME_PREF = "pref_apn_mmsc_custom_username";
const unsigned char* TextSecurePreferences::MMSC_USERNAME_PREF = "pref_apn_mmsc_username";
const unsigned char* TextSecurePreferences::MMSC_CUSTOM_PASSWORD_PREF = "pref_apn_mmsc_custom_password";
const unsigned char* TextSecurePreferences::MMSC_PASSWORD_PREF = "pref_apn_mmsc_password";
const unsigned char* TextSecurePreferences::THREAD_TRIM_LENGTH = "pref_trim_length";
const unsigned char* TextSecurePreferences::THREAD_TRIM_NOW = "pref_trim_now";
const unsigned char* TextSecurePreferences::ENABLE_MANUAL_MMS_PREF = "pref_enable_manual_mms";

const unsigned char* TextSecurePreferences::LAST_VERSION_CODE_PREF = "last_version_code";
const unsigned char* TextSecurePreferences::RINGTONE_PREF = "pref_key_ringtone";
const unsigned char* TextSecurePreferences::VIBRATE_PREF = "pref_key_vibrate";
const unsigned char* TextSecurePreferences::NOTIFICATION_PREF = "pref_key_enable_notifications";
const unsigned char* TextSecurePreferences::LED_COLOR_PREF = "pref_led_color";
const unsigned char* TextSecurePreferences::LED_BLINK_PREF = "pref_led_blink";
const unsigned char* TextSecurePreferences::LED_BLINK_PREF_CUSTOM = "pref_led_blink_custom";
const unsigned char* TextSecurePreferences::ALL_MMS_PREF = "pref_all_mms";
const unsigned char* TextSecurePreferences::ALL_SMS_PREF = "pref_all_sms";
const unsigned char* TextSecurePreferences::PASSPHRASE_TIMEOUT_INTERVAL_PREF = "pref_timeout_interval";
const unsigned char* TextSecurePreferences::PASSPHRASE_TIMEOUT_PREF = "pref_timeout_passphrase";
const unsigned char* TextSecurePreferences::SCREEN_SECURITY_PREF = "pref_screen_security";
const unsigned char* TextSecurePreferences::ENTER_SENDS_PREF = "pref_enter_sends";
const unsigned char* TextSecurePreferences::ENTER_PRESENT_PREF = "pref_enter_key";
const unsigned char* TextSecurePreferences::SMS_DELIVERY_REPORT_PREF = "pref_delivery_report_sms";
const unsigned char* TextSecurePreferences::MMS_USER_AGENT = "pref_mms_user_agent";
const unsigned char* TextSecurePreferences::MMS_CUSTOM_USER_AGENT = "pref_custom_mms_user_agent";
const unsigned char* TextSecurePreferences::THREAD_TRIM_ENABLED = "pref_trim_threads";
const unsigned char* TextSecurePreferences::LOCAL_NUMBER_PREF = "pref_local_number";
const unsigned char* TextSecurePreferences::VERIFYING_STATE_PREF = "pref_verifying";
const unsigned char* TextSecurePreferences::REGISTERED_GCM_PREF = "pref_gcm_registered";
const unsigned char* TextSecurePreferences::GCM_PASSWORD_PREF = "pref_gcm_password";
const unsigned char* TextSecurePreferences::PROMPTED_PUSH_REGISTRATION_PREF = "pref_prompted_push_registration";
const unsigned char* TextSecurePreferences::PROMPTED_DEFAULT_SMS_PREF = "pref_prompted_default_sms";
const unsigned char* TextSecurePreferences::SIGNALING_KEY_PREF = "pref_signaling_key";
const unsigned char* TextSecurePreferences::DIRECTORY_FRESH_TIME_PREF = "pref_directory_refresh_time";
const unsigned char* TextSecurePreferences::IN_THREAD_NOTIFICATION_PREF = "pref_key_inthread_notifications";

const unsigned char* TextSecurePreferences::LOCAL_REGISTRATION_ID_PREF = "pref_local_registration_id";
const unsigned char* TextSecurePreferences::SIGNED_PREKEY_REGISTERED_PREF = "pref_signed_prekey_registered";
const unsigned char* TextSecurePreferences::WIFI_SMS_PREF = "pref_wifi_sms";

const unsigned char* TextSecurePreferences::GCM_REGISTRATION_ID_PREF = "pref_gcm_registration_id";
const unsigned char* TextSecurePreferences::GCM_REGISTRATION_ID_VERSION_PREF = "pref_gcm_registration_id_version";
const unsigned char* TextSecurePreferences::WEBSOCKET_REGISTERED_PREF = "pref_websocket_registered";
const unsigned char* TextSecurePreferences::RATING_LATER_PREF = "pref_rating_later";
const unsigned char* TextSecurePreferences::RATING_ENABLED_PREF = "pref_rating_enabled";

const unsigned char* TextSecurePreferences::REPEAT_ALERTS_PREF = "pref_repeat_alerts";
const unsigned char* TextSecurePreferences::NOTIFICATION_PRIVACY_PREF = "pref_notification_privacy";

const unsigned char* TextSecurePreferences::MEDIA_DOWNLOAD_MOBILE_PREF = "pref_media_download_mobile";
const unsigned char* TextSecurePreferences::MEDIA_DOWNLOAD_WIFI_PREF = "pref_media_download_wifi";
const unsigned char* TextSecurePreferences::MEDIA_DOWNLOAD_ROAMING_PREF = "pref_media_download_roaming";

NotificationPrivacyPreference* TextSecurePreferences::GetNotificationPrivacy(OsIndependentContext* context)
{
  return new NotificationPrivacyPreference(GetStringPreference(context, (unsigned char*)NOTIFICATION_PRIVACY_PREF, (unsigned char*)"all"));
}
long TextSecurePreferences::GetRatingLaterTimestamp(OsIndependentContext* context)
{
  return GetLongPreference(context, (unsigned char*)RATING_LATER_PREF, 0);
}
void TextSecurePreferences::SetRatingLaterTimestamp(OsIndependentContext* context, long timestamp)
{
  SetLongPreference(context, (unsigned char*)RATING_LATER_PREF, timestamp);
}
bool TextSecurePreferences::IsRatingEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)RATING_ENABLED_PREF, true);
}
void TextSecurePreferences::SetRatingEnabled(OsIndependentContext* context, bool enabled)
{
  SetBooleanPreference(context, (unsigned char*)RATING_ENABLED_PREF, enabled);
}
bool TextSecurePreferences::IsWebsocketRegistered(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)WEBSOCKET_REGISTERED_PREF, false);
}
void TextSecurePreferences::SetWebsocketRegistered(OsIndependentContext* context, bool registered)
{
  SetBooleanPreference(context, (unsigned char*)WEBSOCKET_REGISTERED_PREF, registered);
}
bool TextSecurePreferences::IsWifiSmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)WIFI_SMS_PREF, false);
}
int TextSecurePreferences::GetRepeatAlertsCount(OsIndependentContext* context)
{
  //try
  //{
  return Integer.parseInt(GetStringPreference(context, (unsigned char*)REPEAT_ALERTS_PREF, (unsigned char*)"0"));
  //}
  //catch (NumberFormatException e) {
  //  Log.w(TAG, e);
  //  return 0;
  //}
}
void TextSecurePreferences::SetRepeatAlertsCount(OsIndependentContext* context, int count)
{
  SetStringPreference(context, (unsigned char*)REPEAT_ALERTS_PREF, unsigned char*.valueOf(count));
}
bool TextSecurePreferences::IsSignedPreKeyRegistered(OsIndependentContext* context)
{
  return SetBooleanPreference(context, (unsigned char*)SIGNED_PREKEY_REGISTERED_PREF, false);
}
void TextSecurePreferences::SetSignedPreKeyRegistered(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)SIGNED_PREKEY_REGISTERED_PREF, value);
}
void TextSecurePreferences::SetGcmRegistrationId(OsIndependentContext* context, unsigned char* registrationId)
{
  SetStringPreference(context, (unsigned char*)GCM_REGISTRATION_ID_PREF, registrationId);
  SetIntegerPrefrence(context, (unsigned char*)GCM_REGISTRATION_ID_VERSION_PREF, Util::getCurrentApkReleaseVersion(context));
}
unsigned char* TextSecurePreferences::GetGcmRegistrationId(OsIndependentContext* context)
{
  int storedRegistrationIdVersion = GetIntegerPreference(context, (unsigned char*)GCM_REGISTRATION_ID_VERSION_PREF, 0);
  if (storedRegistrationIdVersion != Util::getCurrentApkReleaseVersion(context))
  {
    return nullptr;
  }
  else {
    return GetStringPreference(context, (unsigned char*)GCM_REGISTRATION_ID_PREF, nullptr);
  }
}
bool TextSecurePreferences::IsSmsEnabled(OsIndependentContext* context)
{
  if (Build::VERSION.SDK_INT >= Build::VERSION_CODES.KITKAT) {
    return Util::IsDefaultSmsProvider(context);
  }
  else {
    return IsInterceptAllSmsEnabled(context);
  }
}
int TextSecurePreferences::GetLocalRegistrationId(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (unsigned char*)LOCAL_REGISTRATION_ID_PREF, 0);
}
void TextSecurePreferences::SetLocalRegistrationId(OsIndependentContext* context, int registrationId)
{
  SetIntegerPrefrence(context, (unsigned char*)LOCAL_REGISTRATION_ID_PREF, registrationId);
}
bool TextSecurePreferences::IsInThreadNotifications(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)IN_THREAD_NOTIFICATION_PREF, true);
}
long TextSecurePreferences::GetDirectoryRefreshTime(OsIndependentContext* context)
{
  return GetLongPreference(context, (unsigned char*)DIRECTORY_FRESH_TIME_PREF, 0L);
}
void TextSecurePreferences::SetDirectoryRefreshTime(OsIndependentContext* context, long value)
{
  SetLongPreference(context, (unsigned char*)DIRECTORY_FRESH_TIME_PREF, value);
}
unsigned char* TextSecurePreferences::GetLocalNumber(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)LOCAL_NUMBER_PREF, (unsigned char*)"No Stored Number");
}
void TextSecurePreferences::SetLocalNumber(OsIndependentContext* context, unsigned char* localNumber)
{
  SetStringPreference(context, (unsigned char*)LOCAL_NUMBER_PREF, localNumber);
}
unsigned char* TextSecurePreferences::GetPushServerPassword(OsIndependentContext* context) {
  return GetStringPreference(context, (unsigned char*)GCM_PASSWORD_PREF, nullptr);
}
void TextSecurePreferences::SetPushServerPassword(OsIndependentContext* context, unsigned char* password)
{
  SetStringPreference(context, (unsigned char*)GCM_PASSWORD_PREF, password);
}
void TextSecurePreferences::SetSignalingKey(OsIndependentContext* context, unsigned char* signalingKey)
{
  SetStringPreference(context, (unsigned char*)SIGNALING_KEY_PREF, signalingKey);
}
unsigned char* TextSecurePreferences::GetSignalingKey(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)SIGNALING_KEY_PREF, nullptr);
}
bool TextSecurePreferences::IsEnterImeKeyEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)ENTER_PRESENT_PREF, false);
}
bool TextSecurePreferences::IsEnterSendsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)ENTER_SENDS_PREF, false);
}
bool TextSecurePreferences::IsPasswordDisabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)DISABLE_PASSPHRASE_PREF, false);
}
void TextSecurePreferences::SetPasswordDisabled(OsIndependentContext* context, bool disabled)
{
  SetBooleanPreference(context, (unsigned char*)DISABLE_PASSPHRASE_PREF, disabled);
}
bool TextSecurePreferences::GetUseCustomMmsc(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_HOST_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmsc(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_HOST_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmscUrl(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)MMSC_HOST_PREF, "");
}
void TextSecurePreferences::SetMmscUrl(OsIndependentContext* context, unsigned char* mmsc)
{
  SetStringPreference(context, (unsigned char*)MMSC_HOST_PREF, mmsc);
}
bool TextSecurePreferences::GetUseCustomMmscProxy(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PROXY_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscProxy(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PROXY_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmscProxy(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)MMSC_PROXY_HOST_PREF, "");
}
void TextSecurePreferences::SetMmscProxy(OsIndependentContext* context, unsigned char* value)
{
  SetStringPreference(context, (unsigned char*)MMSC_PROXY_HOST_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscProxyPort(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PROXY_PORT_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscProxyPort(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PROXY_PORT_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmscProxyPort(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)MMSC_PROXY_PORT_PREF, (unsigned char*)"");
}
void TextSecurePreferences::SetMmscProxyPort(OsIndependentContext* context, unsigned char* value)
{
  SetStringPreference(context, (unsigned char*)MMSC_PROXY_PORT_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscUsername(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_USERNAME_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscUsername(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_USERNAME_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmscUsername(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)MMSC_USERNAME_PREF, (unsigned char*)"");
}
void TextSecurePreferences::SetMmscUsername(OsIndependentContext* context, unsigned char* value)
{
  SetStringPreference(context, (unsigned char*)MMSC_USERNAME_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscPassword(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PASSWORD_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscPassword(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)MMSC_CUSTOM_PASSWORD_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmscPassword(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)MMSC_PASSWORD_PREF, "");
}
void TextSecurePreferences::SetMmscPassword(OsIndependentContext* context, unsigned char* value)
{
  SetStringPreference(context, (unsigned char*)MMSC_PASSWORD_PREF, value);
}
unsigned char* TextSecurePreferences::GetMmsUserAgent(OsIndependentContext* context, unsigned char* defaultUserAgent)
{
  bool useCustom = GetBooleanPreference(context, (unsigned char*)MMS_CUSTOM_USER_AGENT, false);
  if (useCustom)
    return GetStringPreference(context, (unsigned char*)MMS_USER_AGENT, defaultUserAgent);
  else
    return defaultUserAgent;
}
unsigned char* TextSecurePreferences::GetIdentityContactUri(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)IDENTITY_PREF, nullptr);
}
void TextSecurePreferences::SetIdentityContactUri(OsIndependentContext* context, unsigned char* identityUri)
{
  SetStringPreference(context, (unsigned char*)IDENTITY_PREF, identityUri);
}
bool TextSecurePreferences::IsScreenSecurityEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)SCREEN_SECURITY_PREF, true);
}
bool TextSecurePreferences::IsLegacyUseLocalApnsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)ENABLE_MANUAL_MMS_PREF, false);
}
int TextSecurePreferences::GetLastVersionCode(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (unsigned char*)LAST_VERSION_CODE_PREF, 0);
}
void TextSecurePreferences::SetLastVersionCode(OsIndependentContext* context, int versionCode) /*throws IOException*/
{
  if (!SetIntegerPrefrenceBlocking(context, (unsigned char*)LAST_VERSION_CODE_PREF, versionCode))
  {
    /* TODO throw new IOException("couldn't write version code to sharedpreferences");*/
  }
}
unsigned char* TextSecurePreferences::GetTheme(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)THEME_PREF, (unsigned char*)"light");
}
bool TextSecurePreferences::IsVerifying(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)VERIFYING_STATE_PREF, false);
}
void TextSecurePreferences::SetVerifying(OsIndependentContext* context, bool verifying)
{
  SetBooleanPreference(context, (unsigned char*)VERIFYING_STATE_PREF, verifying);
}
bool TextSecurePreferences::IsPushRegistered(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)REGISTERED_GCM_PREF, false);
}
void TextSecurePreferences::SetPushRegistered(OsIndependentContext* context, bool registered)
{
  //  Log.w("TextSecurePreferences", "Setting push registered: " + registered);
  SetBooleanPreference(context, (unsigned char*)REGISTERED_GCM_PREF, registered);
}
bool TextSecurePreferences::IsPassphraseTimeoutEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)PASSPHRASE_TIMEOUT_PREF, false);
}
int TextSecurePreferences::GetPassphraseTimeoutInterval(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (unsigned char*)PASSPHRASE_TIMEOUT_INTERVAL_PREF, 5 * 60);
}
void TextSecurePreferences::SetPassphraseTimeoutInterval(OsIndependentContext* context, int interval)
{
  SetIntegerPrefrence(context, (unsigned char*)PASSPHRASE_TIMEOUT_INTERVAL_PREF, interval);
}
unsigned char* TextSecurePreferences::GetLanguage(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)LANGUAGE_PREF, "zz");
}
void TextSecurePreferences::SetLanguage(OsIndependentContext* context, unsigned char* language)
{
  SetStringPreference(context, (unsigned char*)LANGUAGE_PREF, language);
}
bool TextSecurePreferences::IsSmsDeliveryReportsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)SMS_DELIVERY_REPORT_PREF, false);
}
bool TextSecurePreferences::HasPromptedPushRegistration(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)PROMPTED_PUSH_REGISTRATION_PREF, false);
}
void TextSecurePreferences::SetPromptedPushRegistration(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)PROMPTED_PUSH_REGISTRATION_PREF, value);
}
bool TextSecurePreferences::HasPromptedDefaultSmsProvider(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)PROMPTED_DEFAULT_SMS_PREF, false);
}
void TextSecurePreferences::SetPromptedDefaultSmsProvider(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (unsigned char*)PROMPTED_DEFAULT_SMS_PREF, value);
}
bool TextSecurePreferences::IsInterceptAllMmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)ALL_MMS_PREF, true);
}
bool TextSecurePreferences::IsInterceptAllSmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)ALL_SMS_PREF, true);
}
bool TextSecurePreferences::IsNotificationsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)NOTIFICATION_PREF, true);
}
unsigned char* TextSecurePreferences::GetNotificationRingtone(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)RINGTONE_PREF, Settings::System::DEFAULT_NOTIFICATION_URI.toString());
}
bool TextSecurePreferences::IsNotificationVibrateEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)VIBRATE_PREF, true);
}
unsigned char* TextSecurePreferences::GetNotificationLedColor(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)LED_COLOR_PREF, (unsigned char*)"blue");
}
unsigned char* TextSecurePreferences::GetNotificationLedPattern(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)LED_BLINK_PREF, (unsigned char*)"500,2000");
}
unsigned char* TextSecurePreferences::GetNotificationLedPatternCustom(OsIndependentContext* context)
{
  return GetStringPreference(context, (unsigned char*)LED_BLINK_PREF_CUSTOM, (unsigned char*)"500,2000");
}
void TextSecurePreferences::SetNotificationLedPatternCustom(OsIndependentContext* context, unsigned char* pattern)
{
  SetStringPreference(context, (unsigned char*)LED_BLINK_PREF_CUSTOM, pattern);
}
bool TextSecurePreferences::IsThreadLengthTrimmingEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (unsigned char*)THREAD_TRIM_ENABLED, false);
}
int TextSecurePreferences::GetThreadTrimLength(OsIndependentContext* context)
{
  return Integer.parseInt(GetStringPreference(context, (unsigned char*)THREAD_TRIM_LENGTH, (unsigned char*)"500"));
}
Set<unsigned char*> TextSecurePreferences::GetMobileMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (unsigned char*)MEDIA_DOWNLOAD_MOBILE_PREF, R.array.pref_media_download_mobile_data_default);
}
Set<unsigned char*> TextSecurePreferences::GetWifiMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (unsigned char*)MEDIA_DOWNLOAD_WIFI_PREF, R.array.pref_media_download_wifi_default);
}
Set<unsigned char*> TextSecurePreferences::GetRoamingMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (unsigned char*)MEDIA_DOWNLOAD_ROAMING_PREF, R.array.pref_media_download_roaming_default);
}
Set<unsigned char*> TextSecurePreferences::GetMediaDownloadAllowed(OsIndependentContext* context, unsigned char* key, int defaultValuesRes)
{
  return GetStringSetPreference(context,
    key,
    new HashSet<>(Arrays.asList(context.getResources().getStringArray(defaultValuesRes))));
}
void TextSecurePreferences::SetBooleanPreference(OsIndependentContext* context, unsigned char* key, bool value)
{
  PreferenceManager::GetDefaultSharedPreferences(context).edit().putBoolean(key, value).apply();
}
bool TextSecurePreferences::GetBooleanPreference(OsIndependentContext* context, unsigned char* key, bool defaultValue)
{
  return PreferenceManager::GetDefaultSharedPreferences(context).getBoolean(key, defaultValue);
}
void TextSecurePreferences::SetStringPreference(OsIndependentContext* context, unsigned char* key, unsigned char* value)
{
  PreferenceManager::getDefaultSharedPreferences(context).edit().putString(key, value).apply();
}
unsigned char* TextSecurePreferences::GetStringPreference(OsIndependentContext* context, unsigned char* key, unsigned char* defaultValue)
{
  return PreferenceManager::getDefaultSharedPreferences(context).getString(key, defaultValue);
}
int TextSecurePreferences::GetIntegerPreference(OsIndependentContext* context, unsigned char* key, int defaultValue)
{
  return PreferenceManager::getDefaultSharedPreferences(context).getInt(key, defaultValue);
}
void TextSecurePreferences::SetIntegerPrefrence(OsIndependentContext* context, unsigned char* key, int value)
{
  PreferenceManager::getDefaultSharedPreferences(context).edit().putInt(key, value).apply();
}
bool TextSecurePreferences::SetIntegerPrefrenceBlocking(OsIndependentContext* context, unsigned char* key, int value)
{
  return PreferenceManager::GetDefaultSharedPreferences(context).edit().putInt(key, value).commit();
}
long TextSecurePreferences::GetLongPreference(OsIndependentContext* context, unsigned char* key, long defaultValue)
{
  return PreferenceManager::GetDefaultSharedPreferences(context).getLong(key, defaultValue);
}
void TextSecurePreferences::SetLongPreference(OsIndependentContext* context, unsigned char* key, long value) {
  PreferenceManager::GetDefaultSharedPreferences(context).edit().putLong(key, value).apply();
}
Set<unsigned char*> TextSecurePreferences::GetStringSetPreference(OsIndependentContext* context, unsigned char* key, Set<unsigned char*> defaultValues)
{
  final SharedPreferences prefs = PreferenceManager::GetDefaultSharedPreferences(context);
  if (prefs.contains(key))
  {
    return SharedPreferenceCompat::GetStringSet(PreferenceManager::GetDefaultSharedPreferences(context),
      key,
      Collections.<unsigned char*>emptySet());
  }
  else {
    return defaultValues;
  }
}
