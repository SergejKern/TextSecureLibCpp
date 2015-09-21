#include "Recipients.h"

Recipients::Recipients()
{
  this->recipients = new LinkedList<Recipient>();
}

Recipients::~Recipients()
{
}

Recipients::Recipients(List<Recipient> recipients, RecipientPreferenceDatabase::RecipientsPreferences* preferences)
{
  this->recipients = recipients;

  if (preferences != nullptr)
  {
    ringtone = preferences->GetRingtone();
    mutedUntil = preferences->GetMuteUntil();
    vibrate = preferences->GetVibrateState();
    blocked = preferences->IsBlocked();
  }
}

void Recipients::SetRingtone(OsIndependentUri* ringtone)
{
/* TODO synchronized(this) {
    this.ringtone = ringtone;
  }

  notifyListeners(); */
}
bool Recipients::IsMuted()
{
  return false;
  // TODO OS SPECIFIC return System.currentTimeMillis() <= mutedUntil;
}
void Recipients::SetMuted(long mutedUntil)
{
  /* TODO synchronized(this) {
    this.mutedUntil = mutedUntil;
  }
  notifyListeners();
  */
}
void Recipients::SetBlocked(bool blocked)
{
  /* TODO synchronized(this) {
    this.blocked = blocked;
  }
  notifyListeners(); */
}
void Recipients::SetVibrate(RecipientPreferenceDatabase::VibrateState vibrate)
{
  /* TODO synchronized(this) {
    this.vibrate = vibrate;
  }
  notifyListeners(); */
}
ContactPhoto* Recipients::GetContactPhoto()
{
  if (recipients.Size() == 1)
  {
    return recipients.Get(0)->GetContactPhoto();
  }
  else
  {
    return ContactPhotoFactory::GetDefaultGroupPhoto();
  }
}
MaterialColor* Recipients::GetColor()
{
  if (!IsSingleRecipient() || IsGroupRecipient())
  {
    return MaterialColor::GROUP;
  }
  else if (IsEmpty())
  {
    return ContactColors::UNKNOWN_COLOR;
  }
  else
  {
    return recipients.Get(0)->GetColor();
  }
}
void Recipients::SetColor(MaterialColor* color)
{
  if (!IsSingleRecipient() || IsGroupRecipient())
    throw new AssertionError("Groups don't have colors!");
  else if (!IsEmpty())
    recipients.Get(0)->SetColor(color);
}
void Recipients::AddListener(Recipient::RecipientsModifiedListener* listener)
{
  if (listeners.IsEmpty())
  {
    for (Recipient recipient : recipients) {
      recipient.addListener(this);
    }
  }

  synchronized(this) {
    listeners.add(listener);
  }
}
Recipients::Recipients(List<Recipient> recipients, Recipients* stale, ListenableFutureTask<RecipientPreferenceDatabase::RecipientsPreferences> preferences)
{
  this->recipients = recipients;

  if (stale != nullptr)
  {
    ringtone = stale->ringtone;
    mutedUntil = stale->mutedUntil;
    vibrate = stale->vibrate;
    blocked = stale->blocked;
  }

  /* TODO preferences.addListener(new FutureTaskListener<RecipientsPreferences>() {
    @Override
      public void onSuccess(RecipientsPreferences result) {
      if (result != null) {

        Set<RecipientsModifiedListener> localListeners;

        synchronized(Recipients.this) {
          ringtone = result.getRingtone();
          mutedUntil = result.getMuteUntil();
          vibrate = result.getVibrateState();
          blocked = result.isBlocked();

          localListeners = new HashSet<>(listeners);
        }

        for (RecipientsModifiedListener listener : localListeners) {
          listener.onModified(Recipients.this);
        }
      }
    }

    @Override
      public void onFailure(Throwable error) {
      Log.w(TAG, error);
    }
  });*/
}
void Recipients::RemoveListener(Recipients::RecipientsModifiedListener* listener)
{
  this->listeners.Remove(listener);

  if (listeners.IsEmpty()) {
    for (Recipient recipient : recipients) {
      recipient.removeListener(this);
    }
  }
}
bool Recipients::IsEmailRecipient()
{
  for (Recipient recipient : recipients) {
    if (NumberUtil.isValidEmail(recipient.getNumber()))
      return true;
  }
  return false;
}
bool Recipients::IsGroupRecipient()
{
  return IsSingleRecipient() && GroupUtil::IsEncodedGroup(recipients.Get(0)->GetNumber());
}

Recipient* Recipients::GetPrimaryRecipient()
{
  if (!IsEmpty())
    return this->recipients.Get(0);
  else
    return nullptr;
}
unsigned char* Recipients::GetSortedIdsString()
{
  //Set<long> recipientSet = new HashSet<>();

  //for (Recipient recipient : this->recipients)
  //{
  //  recipientSet.add(recipient.getRecipientId());
  //}

  //long[] recipientArray = new long[recipientSet.size()];
  //int i = 0;

  //for (Long recipientId : recipientSet) {
  //  recipientArray[i++] = recipientId;
  //}

  //Arrays.sort(recipientArray);

  //return Util.join(recipientArray, " ");
}
long* Recipients::GetIds()
{
  //long ids[] = new long[recipients.Size()];
  //for (int i = 0; i < recipients.Size(); i++) {
  //  ids[i] = recipients.Get(i)->getRecipientId();
  //}
  //return ids;
}
unsigned char** Recipients::ToNumberStringArray(bool scrub)
{
  //String[] recipientsArray = new String[recipients.size()];
  //Iterator<Recipient> iterator = recipients.iterator();
  //int i = 0;

  //while (iterator.hasNext()) {
  //  String number = iterator.next().getNumber();

  //  if (scrub && number != null &&
  //    !Patterns.EMAIL_ADDRESS.matcher(number).matches() &&
  //    !GroupUtil.isEncodedGroup(number))
  //  {
  //    number = number.replaceAll("[^0-9+]", "");
  //  }

  //  recipientsArray[i++] = number;
  //}

  //return recipientsArray;
}
unsigned char* Recipients::ToShortString()
{
  //String fromString = "";

  //for (int i = 0; i<recipients.size(); i++) {
  //  fromString += recipients.get(i).toShortString();

  //  if (i != recipients.size() - 1)
  //    fromString += ", ";
  //}

  //return fromString;
}
Iterator<Recipient> Recipients::iterator()
{
  return recipients.iterator();
}
void Recipients::OnModified(Recipient* recipient)
{
  NotifyListeners();
}
void Recipients::NotifyListeners()
{
  //Set<RecipientsModifiedListener> localListeners;

  //synchronized(this) {
  //  localListeners = new HashSet<>(listeners);
  //}

  //for (RecipientsModifiedListener listener : localListeners) {
  //  listener.onModified(this);
  //}
}
