#pragma once

/*
Port of class Recipient from TextSecure-android
*/

#include "RecipientDetails.h"

class Recipient
{
public:
  class RecipientModifiedListener
  {
    virtual void onModified(Recipient* recipient) = 0;
  };
private:
  const static char* TAG; // = Recipient.class.getSimpleName();
  const RecipientModifiedListener* listenersSet; // = Collections.newSetFromMap(new WeakHashMap<RecipientModifiedListener, Boolean>());
  const long recipientId;
  char* number;
  char* name;
  bool stale;
  //ContactPhoto* contactPhoto;
  void* contactPhoto; // TODO
  //Uri* contactUri;
  void* contactUri; // TODO
  // MaterialColor* color;
  void* color; // TODO
public:
  virtual ~Recipient();
  //Recipient(long recipientId, char* number, Recipient* stale, ListenableFutureTask<RecipientDetails> future);
  Recipient(long recipientId, char* number, Recipient* stale, void* future);
  Recipient(long recipientId, RecipientDetails* details);
  void* GetContactUri();
  char* GetName();
  void* GetColor();
  void SetColor(void* color);
  char* GetNumber();
  long GetRecipientId();
  bool IsGroupRecipient();
  void AddListener(RecipientModifiedListener* listener);
  void RemoveListener(RecipientModifiedListener* listener);
  char* ToShortString();
  void* GetContactPhoto();
  static Recipient* getUnknownRecipient();
  //@Override
  // bool Equals(void* o);
  //@Override
  // int hashCode();
  void NotifyListeners();
  bool IsStale();
  void SetStale();
};
