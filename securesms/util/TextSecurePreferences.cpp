#include "TextSecurePreferences.h"
#include "TextSecurePreferences.h"
#include "Util.h"
#include "..\R.h"

const OsIndependentString* TextSecurePreferences::TAG = FactoryString::GetInstance()->CreateNewString("TextSecurePreferences");

const OsIndependentString* TextSecurePreferences::IDENTITY_PREF = FactoryString::GetInstance()->CreateNewString("pref_choose_identity");
const OsIndependentString* TextSecurePreferences::CHANGE_PASSPHRASE_PREF = FactoryString::GetInstance()->CreateNewString("pref_change_passphrase");
const OsIndependentString* TextSecurePreferences::DISABLE_PASSPHRASE_PREF = FactoryString::GetInstance()->CreateNewString("pref_disable_passphrase");
const OsIndependentString* TextSecurePreferences::THEME_PREF = FactoryString::GetInstance()->CreateNewString("pref_theme");
const OsIndependentString* TextSecurePreferences::LANGUAGE_PREF = FactoryString::GetInstance()->CreateNewString("pref_language");
const OsIndependentString* TextSecurePreferences::MMSC_CUSTOM_HOST_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_custom_host");
const OsIndependentString* TextSecurePreferences::MMSC_HOST_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_host");
const OsIndependentString* TextSecurePreferences::MMSC_CUSTOM_PROXY_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mms_custom_proxy");
const OsIndependentString* TextSecurePreferences::MMSC_PROXY_HOST_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mms_proxy");
const OsIndependentString* TextSecurePreferences::MMSC_CUSTOM_PROXY_PORT_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mms_custom_proxy_port");
const OsIndependentString* TextSecurePreferences::MMSC_PROXY_PORT_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mms_proxy_port");
const OsIndependentString* TextSecurePreferences::MMSC_CUSTOM_USERNAME_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_custom_username");
const OsIndependentString* TextSecurePreferences::MMSC_USERNAME_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_username");
const OsIndependentString* TextSecurePreferences::MMSC_CUSTOM_PASSWORD_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_custom_password");
const OsIndependentString* TextSecurePreferences::MMSC_PASSWORD_PREF = FactoryString::GetInstance()->CreateNewString("pref_apn_mmsc_password");
const OsIndependentString* TextSecurePreferences::THREAD_TRIM_LENGTH = FactoryString::GetInstance()->CreateNewString("pref_trim_length");
const OsIndependentString* TextSecurePreferences::THREAD_TRIM_NOW = FactoryString::GetInstance()->CreateNewString("pref_trim_now");
const OsIndependentString* TextSecurePreferences::ENABLE_MANUAL_MMS_PREF = FactoryString::GetInstance()->CreateNewString("pref_enable_manual_mms");

const OsIndependentString* TextSecurePreferences::LAST_VERSION_CODE_PREF = FactoryString::GetInstance()->CreateNewString("last_version_code");
const OsIndependentString* TextSecurePreferences::RINGTONE_PREF = FactoryString::GetInstance()->CreateNewString("pref_key_ringtone");
const OsIndependentString* TextSecurePreferences::VIBRATE_PREF = FactoryString::GetInstance()->CreateNewString("pref_key_vibrate");
const OsIndependentString* TextSecurePreferences::NOTIFICATION_PREF = FactoryString::GetInstance()->CreateNewString("pref_key_enable_notifications");
const OsIndependentString* TextSecurePreferences::LED_COLOR_PREF = FactoryString::GetInstance()->CreateNewString("pref_led_color");
const OsIndependentString* TextSecurePreferences::LED_BLINK_PREF = FactoryString::GetInstance()->CreateNewString("pref_led_blink");
const OsIndependentString* TextSecurePreferences::LED_BLINK_PREF_CUSTOM = FactoryString::GetInstance()->CreateNewString("pref_led_blink_custom");
const OsIndependentString* TextSecurePreferences::ALL_MMS_PREF = FactoryString::GetInstance()->CreateNewString("pref_all_mms");
const OsIndependentString* TextSecurePreferences::ALL_SMS_PREF = FactoryString::GetInstance()->CreateNewString("pref_all_sms");
const OsIndependentString* TextSecurePreferences::PASSPHRASE_TIMEOUT_INTERVAL_PREF = FactoryString::GetInstance()->CreateNewString("pref_timeout_interval");
const OsIndependentString* TextSecurePreferences::PASSPHRASE_TIMEOUT_PREF = FactoryString::GetInstance()->CreateNewString("pref_timeout_passphrase");
const OsIndependentString* TextSecurePreferences::SCREEN_SECURITY_PREF = FactoryString::GetInstance()->CreateNewString("pref_screen_security");
const OsIndependentString* TextSecurePreferences::ENTER_SENDS_PREF = FactoryString::GetInstance()->CreateNewString("pref_enter_sends");
const OsIndependentString* TextSecurePreferences::ENTER_PRESENT_PREF = FactoryString::GetInstance()->CreateNewString("pref_enter_key");
const OsIndependentString* TextSecurePreferences::SMS_DELIVERY_REPORT_PREF = FactoryString::GetInstance()->CreateNewString("pref_delivery_report_sms");
const OsIndependentString* TextSecurePreferences::MMS_USER_AGENT = FactoryString::GetInstance()->CreateNewString("pref_mms_user_agent");
const OsIndependentString* TextSecurePreferences::MMS_CUSTOM_USER_AGENT = FactoryString::GetInstance()->CreateNewString("pref_custom_mms_user_agent");
const OsIndependentString* TextSecurePreferences::THREAD_TRIM_ENABLED = FactoryString::GetInstance()->CreateNewString("pref_trim_threads");
const OsIndependentString* TextSecurePreferences::LOCAL_NUMBER_PREF = FactoryString::GetInstance()->CreateNewString("pref_local_number");
const OsIndependentString* TextSecurePreferences::VERIFYING_STATE_PREF = FactoryString::GetInstance()->CreateNewString("pref_verifying");
const OsIndependentString* TextSecurePreferences::REGISTERED_GCM_PREF = FactoryString::GetInstance()->CreateNewString("pref_gcm_registered");
const OsIndependentString* TextSecurePreferences::GCM_PASSWORD_PREF = FactoryString::GetInstance()->CreateNewString("pref_gcm_password");
const OsIndependentString* TextSecurePreferences::PROMPTED_PUSH_REGISTRATION_PREF = FactoryString::GetInstance()->CreateNewString("pref_prompted_push_registration");
const OsIndependentString* TextSecurePreferences::PROMPTED_DEFAULT_SMS_PREF = FactoryString::GetInstance()->CreateNewString("pref_prompted_default_sms");
const OsIndependentString* TextSecurePreferences::SIGNALING_KEY_PREF = FactoryString::GetInstance()->CreateNewString("pref_signaling_key");
const OsIndependentString* TextSecurePreferences::DIRECTORY_FRESH_TIME_PREF = FactoryString::GetInstance()->CreateNewString("pref_directory_refresh_time");
const OsIndependentString* TextSecurePreferences::IN_THREAD_NOTIFICATION_PREF = FactoryString::GetInstance()->CreateNewString("pref_key_inthread_notifications");

const OsIndependentString* TextSecurePreferences::LOCAL_REGISTRATION_ID_PREF = FactoryString::GetInstance()->CreateNewString("pref_local_registration_id");
const OsIndependentString* TextSecurePreferences::SIGNED_PREKEY_REGISTERED_PREF = FactoryString::GetInstance()->CreateNewString("pref_signed_prekey_registered");
const OsIndependentString* TextSecurePreferences::WIFI_SMS_PREF = FactoryString::GetInstance()->CreateNewString("pref_wifi_sms");

const OsIndependentString* TextSecurePreferences::GCM_REGISTRATION_ID_PREF = FactoryString::GetInstance()->CreateNewString("pref_gcm_registration_id");
const OsIndependentString* TextSecurePreferences::GCM_REGISTRATION_ID_VERSION_PREF = FactoryString::GetInstance()->CreateNewString("pref_gcm_registration_id_version");
const OsIndependentString* TextSecurePreferences::WEBSOCKET_REGISTERED_PREF = FactoryString::GetInstance()->CreateNewString("pref_websocket_registered");
const OsIndependentString* TextSecurePreferences::RATING_LATER_PREF = FactoryString::GetInstance()->CreateNewString("pref_rating_later");
const OsIndependentString* TextSecurePreferences::RATING_ENABLED_PREF = FactoryString::GetInstance()->CreateNewString("pref_rating_enabled");

const OsIndependentString* TextSecurePreferences::REPEAT_ALERTS_PREF = FactoryString::GetInstance()->CreateNewString("pref_repeat_alerts");
const OsIndependentString* TextSecurePreferences::NOTIFICATION_PRIVACY_PREF = FactoryString::GetInstance()->CreateNewString("pref_notification_privacy");

const OsIndependentString* TextSecurePreferences::MEDIA_DOWNLOAD_MOBILE_PREF = FactoryString::GetInstance()->CreateNewString("pref_media_download_mobile");
const OsIndependentString* TextSecurePreferences::MEDIA_DOWNLOAD_WIFI_PREF = FactoryString::GetInstance()->CreateNewString("pref_media_download_wifi");
const OsIndependentString* TextSecurePreferences::MEDIA_DOWNLOAD_ROAMING_PREF = FactoryString::GetInstance()->CreateNewString("pref_media_download_roaming");

NotificationPrivacyPreference* TextSecurePreferences::GetNotificationPrivacy(OsIndependentContext* context)
{
  return new NotificationPrivacyPreference(GetStringPreference(context, (OsIndependentString*)NOTIFICATION_PRIVACY_PREF, (OsIndependentString*)"all"));
}
long TextSecurePreferences::GetRatingLaterTimestamp(OsIndependentContext* context)
{
  return GetLongPreference(context, (OsIndependentString*)RATING_LATER_PREF, 0);
}
void TextSecurePreferences::SetRatingLaterTimestamp(OsIndependentContext* context, long timestamp)
{
  SetLongPreference(context, (OsIndependentString*)RATING_LATER_PREF, timestamp);
}
bool TextSecurePreferences::IsRatingEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)RATING_ENABLED_PREF, true);
}
void TextSecurePreferences::SetRatingEnabled(OsIndependentContext* context, bool enabled)
{
  SetBooleanPreference(context, (OsIndependentString*)RATING_ENABLED_PREF, enabled);
}
bool TextSecurePreferences::IsWebsocketRegistered(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)WEBSOCKET_REGISTERED_PREF, false);
}
void TextSecurePreferences::SetWebsocketRegistered(OsIndependentContext* context, bool registered)
{
  SetBooleanPreference(context, (OsIndependentString*)WEBSOCKET_REGISTERED_PREF, registered);
}
bool TextSecurePreferences::IsWifiSmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)WIFI_SMS_PREF, false);
}
int TextSecurePreferences::GetRepeatAlertsCount(OsIndependentContext* context)
{
  //try
  //{
  return GetStringPreference(context, (OsIndependentString*)REPEAT_ALERTS_PREF, (OsIndependentString*)"0")->ConvertToInt();
  //}
  //catch (NumberFormatException e) {
  //  Log.w(TAG, e);
  //  return 0;
  //}
}
void TextSecurePreferences::SetRepeatAlertsCount(OsIndependentContext* context, int count)
{
  SetStringPreference(context, (OsIndependentString*)REPEAT_ALERTS_PREF, FactoryString::GetInstance()->CreateNewString(count));
}
bool TextSecurePreferences::IsSignedPreKeyRegistered(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)SIGNED_PREKEY_REGISTERED_PREF, false);
}
void TextSecurePreferences::SetSignedPreKeyRegistered(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)SIGNED_PREKEY_REGISTERED_PREF, value);
}
void TextSecurePreferences::SetGcmRegistrationId(OsIndependentContext* context, OsIndependentString* registrationId)
{
  SetStringPreference(context, (OsIndependentString*)GCM_REGISTRATION_ID_PREF, registrationId);
  SetIntegerPrefrence(context, (OsIndependentString*)GCM_REGISTRATION_ID_VERSION_PREF, Util::GetCurrentApkReleaseVersion(context));
}
OsIndependentString* TextSecurePreferences::GetGcmRegistrationId(OsIndependentContext* context)
{
  int storedRegistrationIdVersion = GetIntegerPreference(context, (OsIndependentString*)GCM_REGISTRATION_ID_VERSION_PREF, 0);
  if (storedRegistrationIdVersion != Util::GetCurrentApkReleaseVersion(context))
  {
    return nullptr;
  }
  else {
    return GetStringPreference(context, (OsIndependentString*)GCM_REGISTRATION_ID_PREF, nullptr);
  }
}
bool TextSecurePreferences::IsSmsEnabled(OsIndependentContext* context)
{
  //if (Build::VERSION::SDK_INT >= Build::VERSION_CODES::KITKAT)
  if (Util::CanAskForDefaultSmsProvider())
  {
    return Util::IsDefaultSmsProvider(context);
  }
  else
  {
    return IsInterceptAllSmsEnabled(context);
  }
}
int TextSecurePreferences::GetLocalRegistrationId(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (OsIndependentString*)LOCAL_REGISTRATION_ID_PREF, 0);
}
void TextSecurePreferences::SetLocalRegistrationId(OsIndependentContext* context, int registrationId)
{
  SetIntegerPrefrence(context, (OsIndependentString*)LOCAL_REGISTRATION_ID_PREF, registrationId);
}
bool TextSecurePreferences::IsInThreadNotifications(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)IN_THREAD_NOTIFICATION_PREF, true);
}
long TextSecurePreferences::GetDirectoryRefreshTime(OsIndependentContext* context)
{
  return GetLongPreference(context, (OsIndependentString*)DIRECTORY_FRESH_TIME_PREF, 0L);
}
void TextSecurePreferences::SetDirectoryRefreshTime(OsIndependentContext* context, long value)
{
  SetLongPreference(context, (OsIndependentString*)DIRECTORY_FRESH_TIME_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetLocalNumber(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)LOCAL_NUMBER_PREF, (OsIndependentString*)"No Stored Number");
}
void TextSecurePreferences::SetLocalNumber(OsIndependentContext* context, OsIndependentString* localNumber)
{
  SetStringPreference(context, (OsIndependentString*)LOCAL_NUMBER_PREF, localNumber);
}
OsIndependentString* TextSecurePreferences::GetPushServerPassword(OsIndependentContext* context) {
  return GetStringPreference(context, (OsIndependentString*)GCM_PASSWORD_PREF, nullptr);
}
void TextSecurePreferences::SetPushServerPassword(OsIndependentContext* context, OsIndependentString* password)
{
  SetStringPreference(context, (OsIndependentString*)GCM_PASSWORD_PREF, password);
}
void TextSecurePreferences::SetSignalingKey(OsIndependentContext* context, OsIndependentString* signalingKey)
{
  SetStringPreference(context, (OsIndependentString*)SIGNALING_KEY_PREF, signalingKey);
}
OsIndependentString* TextSecurePreferences::GetSignalingKey(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)SIGNALING_KEY_PREF, nullptr);
}
bool TextSecurePreferences::IsEnterImeKeyEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)ENTER_PRESENT_PREF, false);
}
bool TextSecurePreferences::IsEnterSendsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)ENTER_SENDS_PREF, false);
}
bool TextSecurePreferences::IsPasswordDisabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)DISABLE_PASSPHRASE_PREF, false);
}
void TextSecurePreferences::SetPasswordDisabled(OsIndependentContext* context, bool disabled)
{
  SetBooleanPreference(context, (OsIndependentString*)DISABLE_PASSPHRASE_PREF, disabled);
}
bool TextSecurePreferences::GetUseCustomMmsc(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_HOST_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmsc(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_HOST_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmscUrl(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)MMSC_HOST_PREF, FactoryString::GetInstance()->CreateNewString(""));
}
void TextSecurePreferences::SetMmscUrl(OsIndependentContext* context, OsIndependentString* mmsc)
{
  SetStringPreference(context, (OsIndependentString*)MMSC_HOST_PREF, mmsc);
}
bool TextSecurePreferences::GetUseCustomMmscProxy(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PROXY_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscProxy(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PROXY_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmscProxy(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)MMSC_PROXY_HOST_PREF, FactoryString::GetInstance()->CreateNewString(""));
}
void TextSecurePreferences::SetMmscProxy(OsIndependentContext* context, OsIndependentString* value)
{
  SetStringPreference(context, (OsIndependentString*)MMSC_PROXY_HOST_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscProxyPort(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PROXY_PORT_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscProxyPort(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PROXY_PORT_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmscProxyPort(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)MMSC_PROXY_PORT_PREF, FactoryString::GetInstance()->CreateNewString(""));
}
void TextSecurePreferences::SetMmscProxyPort(OsIndependentContext* context, OsIndependentString* value)
{
  SetStringPreference(context, (OsIndependentString*)MMSC_PROXY_PORT_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscUsername(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_USERNAME_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscUsername(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_USERNAME_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmscUsername(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)MMSC_USERNAME_PREF, FactoryString::GetInstance()->CreateNewString(""));
}
void TextSecurePreferences::SetMmscUsername(OsIndependentContext* context, OsIndependentString* value)
{
  SetStringPreference(context, (OsIndependentString*)MMSC_USERNAME_PREF, value);
}
bool TextSecurePreferences::GetUseCustomMmscPassword(OsIndependentContext* context)
{
  bool legacy = TextSecurePreferences::IsLegacyUseLocalApnsEnabled(context);
  return GetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PASSWORD_PREF, legacy);
}
void TextSecurePreferences::SetUseCustomMmscPassword(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)MMSC_CUSTOM_PASSWORD_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmscPassword(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)MMSC_PASSWORD_PREF, FactoryString::GetInstance()->CreateNewString(""));
}
void TextSecurePreferences::SetMmscPassword(OsIndependentContext* context, OsIndependentString* value)
{
  SetStringPreference(context, (OsIndependentString*)MMSC_PASSWORD_PREF, value);
}
OsIndependentString* TextSecurePreferences::GetMmsUserAgent(OsIndependentContext* context, OsIndependentString* defaultUserAgent)
{
  bool useCustom = GetBooleanPreference(context, (OsIndependentString*)MMS_CUSTOM_USER_AGENT, false);
  if (useCustom)
    return GetStringPreference(context, (OsIndependentString*)MMS_USER_AGENT, defaultUserAgent);
  else
    return defaultUserAgent;
}
OsIndependentString* TextSecurePreferences::GetIdentityContactUri(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)IDENTITY_PREF, nullptr);
}
void TextSecurePreferences::SetIdentityContactUri(OsIndependentContext* context, OsIndependentString* identityUri)
{
  SetStringPreference(context, (OsIndependentString*)IDENTITY_PREF, identityUri);
}
bool TextSecurePreferences::IsScreenSecurityEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)SCREEN_SECURITY_PREF, true);
}
bool TextSecurePreferences::IsLegacyUseLocalApnsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)ENABLE_MANUAL_MMS_PREF, false);
}
int TextSecurePreferences::GetLastVersionCode(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (OsIndependentString*)LAST_VERSION_CODE_PREF, 0);
}
void TextSecurePreferences::SetLastVersionCode(OsIndependentContext* context, int versionCode) /*throws IOException*/
{
  if (!SetIntegerPrefrenceBlocking(context, (OsIndependentString*)LAST_VERSION_CODE_PREF, versionCode))
  {
    /* TODO throw new IOException("couldn't write version code to sharedpreferences");*/
  }
}
OsIndependentString* TextSecurePreferences::GetTheme(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)THEME_PREF, FactoryString::GetInstance()->CreateNewString("light"));
}
bool TextSecurePreferences::IsVerifying(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)VERIFYING_STATE_PREF, false);
}
void TextSecurePreferences::SetVerifying(OsIndependentContext* context, bool verifying)
{
  SetBooleanPreference(context, (OsIndependentString*)VERIFYING_STATE_PREF, verifying);
}
bool TextSecurePreferences::IsPushRegistered(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)REGISTERED_GCM_PREF, false);
}
void TextSecurePreferences::SetPushRegistered(OsIndependentContext* context, bool registered)
{
  //  Log.w("TextSecurePreferences", "Setting push registered: " + registered);
  SetBooleanPreference(context, (OsIndependentString*)REGISTERED_GCM_PREF, registered);
}
bool TextSecurePreferences::IsPassphraseTimeoutEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)PASSPHRASE_TIMEOUT_PREF, false);
}
int TextSecurePreferences::GetPassphraseTimeoutInterval(OsIndependentContext* context)
{
  return GetIntegerPreference(context, (OsIndependentString*)PASSPHRASE_TIMEOUT_INTERVAL_PREF, 5 * 60);
}
void TextSecurePreferences::SetPassphraseTimeoutInterval(OsIndependentContext* context, int interval)
{
  SetIntegerPrefrence(context, (OsIndependentString*)PASSPHRASE_TIMEOUT_INTERVAL_PREF, interval);
}
OsIndependentString* TextSecurePreferences::GetLanguage(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)LANGUAGE_PREF, FactoryString::GetInstance()->CreateNewString("zz"));
}
void TextSecurePreferences::SetLanguage(OsIndependentContext* context, OsIndependentString* language)
{
  SetStringPreference(context, (OsIndependentString*)LANGUAGE_PREF, language);
}
bool TextSecurePreferences::IsSmsDeliveryReportsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)SMS_DELIVERY_REPORT_PREF, false);
}
bool TextSecurePreferences::HasPromptedPushRegistration(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)PROMPTED_PUSH_REGISTRATION_PREF, false);
}
void TextSecurePreferences::SetPromptedPushRegistration(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)PROMPTED_PUSH_REGISTRATION_PREF, value);
}
bool TextSecurePreferences::HasPromptedDefaultSmsProvider(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)PROMPTED_DEFAULT_SMS_PREF, false);
}
void TextSecurePreferences::SetPromptedDefaultSmsProvider(OsIndependentContext* context, bool value)
{
  SetBooleanPreference(context, (OsIndependentString*)PROMPTED_DEFAULT_SMS_PREF, value);
}
bool TextSecurePreferences::IsInterceptAllMmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)ALL_MMS_PREF, true);
}
bool TextSecurePreferences::IsInterceptAllSmsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)ALL_SMS_PREF, true);
}
bool TextSecurePreferences::IsNotificationsEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)NOTIFICATION_PREF, true);
}
OsIndependentString* TextSecurePreferences::GetNotificationRingtone(OsIndependentContext* context)
{
  // public static final Uri DEFAULT_NOTIFICATION_URI = getUriFor(NOTIFICATION_SOUND)
  // public static final String NOTIFICATION_SOUND = "notification_sound";
  return GetStringPreference(context, (OsIndependentString*)RINGTONE_PREF, FactoryString::GetInstance()->CreateNewString("notification_sound"));
}
bool TextSecurePreferences::IsNotificationVibrateEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)VIBRATE_PREF, true);
}
OsIndependentString* TextSecurePreferences::GetNotificationLedColor(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)LED_COLOR_PREF, FactoryString::GetInstance()->CreateNewString("blue"));
}
OsIndependentString* TextSecurePreferences::GetNotificationLedPattern(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)LED_BLINK_PREF, FactoryString::GetInstance()->CreateNewString("500,2000"));
}
OsIndependentString* TextSecurePreferences::GetNotificationLedPatternCustom(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)LED_BLINK_PREF_CUSTOM, FactoryString::GetInstance()->CreateNewString("500,2000"));
}
void TextSecurePreferences::SetNotificationLedPatternCustom(OsIndependentContext* context, OsIndependentString* pattern)
{
  SetStringPreference(context, (OsIndependentString*)LED_BLINK_PREF_CUSTOM, pattern);
}
bool TextSecurePreferences::IsThreadLengthTrimmingEnabled(OsIndependentContext* context)
{
  return GetBooleanPreference(context, (OsIndependentString*)THREAD_TRIM_ENABLED, false);
}
int TextSecurePreferences::GetThreadTrimLength(OsIndependentContext* context)
{
  return GetStringPreference(context, (OsIndependentString*)THREAD_TRIM_LENGTH, FactoryString::GetInstance()->CreateNewString("500"))->ConvertToInt();
}
std::set<OsIndependentString*>* TextSecurePreferences::GetMobileMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (OsIndependentString*)MEDIA_DOWNLOAD_MOBILE_PREF, R::Array::pref_media_download_mobile_data_default);
}
std::set<OsIndependentString*>* TextSecurePreferences::GetWifiMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (OsIndependentString*)MEDIA_DOWNLOAD_WIFI_PREF, R::Array::pref_media_download_wifi_default);
}
std::set<OsIndependentString*>* TextSecurePreferences::GetRoamingMediaDownloadAllowed(OsIndependentContext* context)
{
  return GetMediaDownloadAllowed(context, (OsIndependentString*)MEDIA_DOWNLOAD_ROAMING_PREF, R::Array::pref_media_download_roaming_default);
}
std::set<OsIndependentString*>* TextSecurePreferences::GetMediaDownloadAllowed(OsIndependentContext* context, OsIndependentString* key, int defaultValuesRes)
{
  std::set<OsIndependentString*>* set = new std::set<OsIndependentString*>();
  auto list = context->GetResources()->GetStringArray(defaultValuesRes);
  for (std::list<OsIndependentString*>::iterator it = list->begin(); it != list->end(); ++it)
  {
    set->insert(*it);
  }
  return GetStringSetPreference(context, key, set);
}
void TextSecurePreferences::SetBooleanPreference(OsIndependentContext* context, OsIndependentString* key, bool value)
{
  FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->Edit()->PutBoolean(key, value)->Apply();
}
bool TextSecurePreferences::GetBooleanPreference(OsIndependentContext* context, OsIndependentString* key, bool defaultValue)
{
  return FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->GetBoolean(key, defaultValue);
}
void TextSecurePreferences::SetStringPreference(OsIndependentContext* context, OsIndependentString* key, OsIndependentString* value)
{
  FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->Edit()->PutString(key, value)->Apply();
}
OsIndependentString* TextSecurePreferences::GetStringPreference(OsIndependentContext* context, OsIndependentString* key, OsIndependentString* defaultValue)
{
  return FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->GetString(key, defaultValue);
}
int TextSecurePreferences::GetIntegerPreference(OsIndependentContext* context, OsIndependentString* key, int defaultValue)
{
  return FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->GetInt(key, defaultValue);
}
void TextSecurePreferences::SetIntegerPrefrence(OsIndependentContext* context, OsIndependentString* key, int value)
{
  FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->Edit()->PutInt(key, value)->Apply();
}
bool TextSecurePreferences::SetIntegerPrefrenceBlocking(OsIndependentContext* context, OsIndependentString* key, int value)
{
  return FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->Edit()->PutInt(key, value)->Commit();
}
long TextSecurePreferences::GetLongPreference(OsIndependentContext* context, OsIndependentString* key, long defaultValue)
{
  return FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->GetLong(key, defaultValue);
}
void TextSecurePreferences::SetLongPreference(OsIndependentContext* context, OsIndependentString* key, long value)
{
  FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context)->Edit()->PutLong(key, value)->Apply();
}
std::set<OsIndependentString*>* TextSecurePreferences::GetStringSetPreference(OsIndependentContext* context, OsIndependentString* key, std::set<OsIndependentString*>* defaultValues)
{
  auto prefs = FactoryPreferenceManager::GetInstance()->CreateNewPreferenceManager()->
    GetDefaultSharedPreferences(context);

  if (prefs->Contains(key))
  {
    return prefs->GetStringSet(key, nullptr);
  }
  else
  {
    return defaultValues;
  }
}
