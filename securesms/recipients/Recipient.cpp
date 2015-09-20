#include "Recipient.h"
#include "..\contacts\avatars\ContactPhoto.h"
#include "..\contacts\avatars\ContactPhotoFactory.h"
#include "..\contacts\avatars\ContactColors.h"
#include "..\util\GroupUtil.h"
#include <mbstring.h>

Recipient::~Recipient()
{
}

Recipient::Recipient(long recipientId, unsigned char* number, Recipient* stale, void* future) : recipientId(recipientId)
{
  this->number = number;
  this->contactPhoto = ContactPhotoFactory::GetLoadingPhoto();
  this->color = nullptr;

  if (stale != nullptr) {
    this->name = stale->name;
    this->contactUri = stale->contactUri;
    this->contactPhoto = stale->contactPhoto;
    this->color = stale->color;
  }

  /* TODO
  future.addListener(new FutureTaskListener<RecipientDetails>() {
    @Override
      public void onSuccess(RecipientDetails result) {
      if (result != null) {
        synchronized(Recipient.this) {
          Recipient.this.name = result.name;
          Recipient.this.number = result.number;
          Recipient.this.contactUri = result.contactUri;
          Recipient.this.contactPhoto = result.avatar;
          Recipient.this.color = result.color;
        }

        notifyListeners();
      }
    }

    @Override
      public void onFailure(Throwable error) {
      Log.w(TAG, error);
    }
  });*/
}
Recipient::Recipient(long recipientId, RecipientDetails* details) : recipientId(recipientId)
{
  _mbscpy(details->number, this->number);
  this->contactUri = details->contactUri;
  this->name = details->name;
  this->contactPhoto = details->avatar;
  this->color = details->color;
}
void* Recipient::GetContactUri()
{
  return this->contactUri;
}
unsigned char* Recipient::GetName()
{
  return this->name;
}
MaterialColor* Recipient::GetColor()
{
  if (color != nullptr)
  {
    return color;
  }
  else if (name != nullptr)
  {
    return ContactColors::GenerateFor(name);
  }
  else
  {
    return ContactColors::UNKNOWN_COLOR;
  }
}
void Recipient::SetColor(MaterialColor* color)
{
  // TODO synchronized(this) {
    this->color = color;
  //}

  NotifyListeners();
}
unsigned char* Recipient::GetNumber()
{
  return this->number;
}
long Recipient::GetRecipientId()
{
  return this->recipientId;
}
bool Recipient::IsGroupRecipient()
{
  return GroupUtil::IsEncodedGroup(this->number);
}
void Recipient::AddListener(RecipientModifiedListener* listener)
{
  // TODO this->listenersSet->add(listener);
}
void Recipient::RemoveListener(RecipientModifiedListener* listener)
{
  // TODO this->listenersSet->remove(listener);
}
unsigned char* Recipient::ToShortString()
{
  return (this->name == nullptr ? this->number : this->name);
}
ContactPhoto* Recipient::GetContactPhoto()
{
  return this->contactPhoto;
}
Recipient* Recipient::getUnknownRecipient()
{
  // TODO - remove cast
  return new Recipient(-1, new RecipientDetails((unsigned char*)"Unknown", (unsigned char*)"Unknown", nullptr, ContactPhotoFactory::GetDefaultContactPhoto(nullptr), nullptr));
}
//@Override
// bool Recipient::Equals(void* o);
//@Override
/* int Recipient::hashCode()
{
  return 31 + (int)this.recipientId;
}
*/
void Recipient::NotifyListeners()
{
  // TODO
  // Set<RecipientModifiedListener> localListeners;

  // TODO synchronized(this) {
  //  localListeners = new HashSet<>(listeners);
  //}

  //for (RecipientModifiedListener listener : localListeners)
  //    listener.onModified(Recipient.this);
}
bool Recipient::IsStale()
{
  return this->stale;
}
void Recipient::SetStale()
{
  this->stale = true;
}
