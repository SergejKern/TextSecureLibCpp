#pragma once

/*
Port of class Recipient from TextSecure-android
*/

// [ ] done
// TFS ID: 306

#include "RecipientDetails.h"
#include "..\contacts\avatars\ContactPhoto.h"
#include "..\color\MaterialColor.h"

class Recipient
{
public:
  class RecipientModifiedListener
  {
    virtual void onModified(Recipient* recipient) = 0;
  };
private:
  const static unsigned char* TAG; // = Recipient.class.getSimpleName();
  const RecipientModifiedListener* listenersSet; // = Collections.newSetFromMap(new WeakHashMap<RecipientModifiedListener, Boolean>());
  const long recipientId;
  unsigned char* number;
  unsigned char* name;
  bool stale;
  ContactPhoto* contactPhoto;
  //Uri* contactUri;
  void* contactUri; // TODO
  MaterialColor* color;
public:
  virtual ~Recipient();
  //Recipient(long recipientId, char* number, Recipient* stale, ListenableFutureTask<RecipientDetails> future);
  Recipient(long recipientId, unsigned char* number, Recipient* stale, void* future);
  Recipient(long recipientId, RecipientDetails* details);
  void* GetContactUri();
  unsigned char* GetName();
  MaterialColor* GetColor();
  void SetColor(MaterialColor* color);
  unsigned char* GetNumber();
  long GetRecipientId();
  bool IsGroupRecipient();
  void AddListener(RecipientModifiedListener* listener);
  void RemoveListener(RecipientModifiedListener* listener);
  unsigned char* ToShortString();
  ContactPhoto* GetContactPhoto();
  static Recipient* getUnknownRecipient();
  //@Override
  // bool Equals(void* o);
  //@Override
  // int hashCode();
  void NotifyListeners();
  bool IsStale();
  void SetStale();
};
