#pragma once

/*
Port of NotificationPrivacyPreference.java from TextSecure-android
*/

// [x] done
// TFS ID: 622

class NotificationPrivacyPreference
{
private:
  const unsigned char* preference;

public:
  NotificationPrivacyPreference(unsigned char* preference)
  {
    this->preference = preference;
  }
  bool IsDisplayContact()
  {
    return preference == "all" || preference == "contact";
  }
  bool IsDisplayMessage()
  {
    return preference == "all";
  }
};
