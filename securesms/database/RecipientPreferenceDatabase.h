#pragma once
/*
Port of class SmsDatabase from TextSecure-android
*/

// [ ] done
// TFS ID: 485

#include "Database.h"
//#include "..\..\osindependent\OsIndependentCursor.h"
//#include "..\..\osindependent\OsIndependentContext.h"
//#include "..\..\osindependent\OsIndependentSQLiteOpenHelper.h"
#include "..\..\osindependent\OsIndependentUri.h"
//#include "..\..\otherproject\JobManager.h"
//#include "model\SmsMessageRecord.h"
//#include "..\sms\IncomingTextMessage.h"
#include "..\color\MaterialColor.h"
//#include "..\..\owntemplates\Pair.h"

class RecipientPreferenceDatabase : public Database
{
public:
  enum VibrateState {default, enabled, disabled};
  class RecipientsPreferences
  {
  private:
    const bool blocked;
    const long muteUntil;
    VibrateState vibrateState;
    OsIndependentUri* notification;
    MaterialColor* color;

  public:
    RecipientsPreferences(bool blocked, long muteUntil,
      VibrateState vibrateState,
      OsIndependentUri* notification,
      MaterialColor* color) : blocked(blocked), muteUntil(muteUntil), notification(notification), vibrateState(vibrateState)
    {
      this->color = color;
    }
    MaterialColor* GetColor() { return this->color; }
    bool IsBlocked() { return this->blocked; }
    long GetMuteUntil() { return this->muteUntil; }
    VibrateState GetVibrateState() { return this->vibrateState; }
    OsIndependentUri* GetRingtone() { return this->notification; }
  };
};
