#pragma once

/*
Port of class Recipients from TextSecure-android
*/

#include "..\..\owntemplates\Iterable.h"
#include "..\..\owntemplates\Set.h"
#include "..\..\owntemplates\List.h"
#include "..\..\osindependent\OsIndependentUri.h"
#include "..\..\otherproject\ListenableFutureTask.h"
#include "Recipient.h"
#include "..\database\RecipientPreferenceDatabase.h"
#include "..\util\GroupUtil.h"


class Recipients : 
  Iterable<Recipient>,
  Recipient::RecipientModifiedListener
{
public:
  virtual ~Recipients();

  class RecipientsModifiedListener
  {
  public:
    virtual void OnModified(Recipients* recipient) = 0;
  };

private:
  static const unsigned char* TAG;

  Set<Recipients::RecipientsModifiedListener> listeners; // TODO = Collections.newSetFromMap(new WeakHashMap<RecipientsModifiedListener, Boolean>());
  List<Recipient> recipients;

  OsIndependentUri* ringtone = nullptr;
  long mutedUntil = 0;
  bool blocked = false;
  RecipientPreferenceDatabase::VibrateState vibrate = RecipientPreferenceDatabase::VibrateState::default;
  bool stale = false;

  Recipients();
  Recipients(List<Recipient> recipients, RecipientPreferenceDatabase::RecipientsPreferences* preferences);
  Recipients(List<Recipient> recipients, Recipients* stale, ListenableFutureTask<RecipientPreferenceDatabase::RecipientsPreferences> preferences);
  OsIndependentUri* GetRingtone() { return this->ringtone; }
  void SetRingtone(OsIndependentUri* ringtone);
  bool IsMuted();
  void SetMuted(long mutedUntil);
  bool IsBlocked() { return this->blocked; }
  void SetBlocked(bool blocked);
  RecipientPreferenceDatabase::VibrateState getVibrate() { return this->vibrate; }
  void SetVibrate(RecipientPreferenceDatabase::VibrateState vibrate);
  ContactPhoto* GetContactPhoto();
  MaterialColor* GetColor();
  void SetColor(MaterialColor* color);
  void AddListener(Recipients::RecipientsModifiedListener* listener);
  void RemoveListener(Recipients::RecipientsModifiedListener* listener);
  bool IsEmailRecipient();
  bool IsGroupRecipient();
  bool IsEmpty() { return this->recipients.IsEmpty(); }
  bool IsSingleRecipient() { return this->recipients.Size() == 1; }
  Recipient* GetPrimaryRecipient();
  List<Recipient> GetRecipientsList() { return this->recipients; }
  long* GetIds();
  unsigned char* GetSortedIdsString();
  unsigned char** ToNumberStringArray(bool scrub);
  unsigned char* ToShortString();
  //@Override
  Iterator<Recipient> iterator();
  //@Override
  void OnModified(Recipient* recipient);
  void NotifyListeners();
  bool IsStale() { return this->stale; }
  void SetStale() { this->stale = true; }
};

const unsigned char* Recipients::TAG = (unsigned char*)"Recipients";
