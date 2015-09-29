#pragma once
/*
Port of class ContactAccessor from TextSecure-android
*/

// [ ] done
// TFS ID: 420

//import android.content.ContentResolver;
#include "..\..\osindependent\OsIndependentContext.h"
#include "..\..\osindependent\OsIndependentCursor.h"
//import android.database.MergeCursor;
#include "..\..\osindependent\OsIndependentUri.h"
#include "..\..\osindependent\OsIndependentParcel.h"
#include "..\..\osindependent\OsIndependentParcelable.h"
//import android.provider.ContactsContract.CommonDataKinds.Phone;
//import android.provider.ContactsContract.Contacts;
//import android.provider.ContactsContract.PhoneLookup;
//import android.telephony.PhoneNumberUtils;
//
//import org.thoughtcrime.securesms.database.DatabaseFactory;
//import org.thoughtcrime.securesms.database.GroupDatabase;
//import org.thoughtcrime.securesms.database.TextSecureDirectory;
//
//import java.util.ArrayList;
//import java.util.Collection;
//import java.util.LinkedList;
#include "..\..\owntemplates\List.h"

//import static org.thoughtcrime.securesms.database.GroupDatabase.GroupRecord;

/**
 * This class was originally a layer of indirection between
 * ContactAccessorNewApi and ContactAccesorOldApi, which corresponded
 * to the API changes between 1.x and 2.x.
 *
 * Now that we no longer support 1.x, this class mostly serves as a place
 * to encapsulate Contact-related logic.  It's still a singleton, mostly
 * just because that's how it's currently called from everywhere.
 *
 * @author Moxie Marlinspike
 */

class ContactAccessor
{
public:
  static OsIndependentString* PUSH_COLUMN;

private:
  static ContactAccessor* Instance;

public:
  static /*synchronized*/ ContactAccessor* GetInstance()
  {
    return ContactAccessor::Instance;
  }
public:
  class NumberData : OsIndependentParcelable
  {
  public:
    // TODO deanonymize anonyme function
    //static const OsIndependentParcelable::Creator<NumberData> CREATOR = new OsIndependentParcelable.Creator<NumberData>()
    //{
    //  NumberData* createFromParcel(OsIndependentParcel* in)
    //  {
    //    return new NumberData(in);
    //  }
    //  NumberData[] NewArray(int size)
    //  {
    //    return new NumberData[size];
    //  }
    //};
    const OsIndependentString* number;
    const OsIndependentString* type;

    NumberData(OsIndependentString* type, OsIndependentString* number)
    {
      this->type = type;
      this->number = number;
    }
    NumberData(OsIndependentParcel* in)
    {
      number = in->ReadString();
      type = in->ReadString();
    }
    int DescribeContents() { return 0; }
    void writeToParcel(OsIndependentParcel* dest, int flags)
    {
      dest->WriteString(number);
      dest->WriteString(type);
    }
  };

  class ContactData : OsIndependentParcelable
  {
    // deanonymize anonyme function
    //static const OsIndependentParcelable.Creator<ContactData> CREATOR = new OsIndependentParcelable.Creator<ContactData>() {
    //  public ContactData createFromParcel(OsIndependentParcel in) {
    //    return new ContactData(in);
    //  }

    //  public ContactData[] newArray(int size) {
    //    return new ContactData[size];
    //  }
    //};

  public:
    const long id;
    const OsIndependentString* name;
    const List<NumberData*>* numbers;

    ContactData(long id, OsIndependentString* name)
      : id(id)
    {
      this->name = name;
      this->numbers = new LinkedList<NumberData*>();
    }
    ContactData(OsIndependentParcel* in)
      : id(in->ReadLong())
    {
      this->name = in->ReadString();
      this->numbers = new LinkedList<NumberData*>();
      in->ReadTypedList(this->numbers, NumberData::CREATOR);
    }
    int DescribeContents() { return 0; }
    void WriteToParcel(OsIndependentParcel* dest, int flags)
    {
      dest->WriteLong(this->id);
      dest->WriteString(this->name);
      dest->WriteTypedList(this->numbers);
    }
  };
public:
  Collection<ContactData*> GetContactsWithPush(OsIndependentContext* context)
  {
    const ContentResolver* resolver = context.getContentResolver();
    const OsIndependentString*[] inProjection    = new OsIndependentString*[]{PhoneLookup._ID, PhoneLookup.DISPLAY_NAME};

    List<OsIndependentString*> pushNumbers = TextSecureDirectory.getInstance(context).getActiveNumbers();
    const Collection<ContactData> lookupData = new ArrayList<ContactData>(pushNumbers.size());

    for (OsIndependentString* pushNumber : pushNumbers) {
      OsIndependentUri* uri = OsIndependentUri*.withAppendedPath(PhoneLookup.CONTENT_FILTER_URI, OsIndependentUri*.encode(pushNumber));
      OsIndependentCursor* lookupCursor = resolver.query(uri, inProjection, null, null, null);
      try {
        if (lookupCursor != null && lookupCursor.moveToFirst()) {
          const ContactData contactData = new ContactData(lookupCursor.getLong(0), lookupCursor.getString(1));
          contactData.numbers.add(new NumberData("TextSecure", pushNumber));
          lookupData.add(contactData);
        }
      } finally {
        if (lookupCursor != null)
          lookupCursor.close();
      }
    }
    return lookupData;
  }

  OsIndependentString* GetNameFromContact(OsIndependentContext* context, OsIndependentUri* uri)
  {
    OsIndependentCursor* cursor = null;

    try {
      cursor = context.getContentResolver().query(uri, new OsIndependentString*[] {Contacts.DISPLAY_NAME},
                                                  null, null, null);

      if (cursor != null && cursor.moveToFirst())
        return cursor.getString(0);

    } finally {
      if (cursor != null)
        cursor.close();
    }

    return null;
  }
  ContactData* GetContactData(OsIndependentContext* context, OsIndependentUri* uri)
  {
    return GetContactData(context, getNameFromContact(context, uri),  Long.parseLong(uri.getLastPathSegment()));
  }

private:
  ContactData* GetContactData(OsIndependentContext* context, OsIndependentString* displayName, long id) {
    ContactData contactData = new ContactData(id, displayName);
    OsIndependentCursor* numberCursor     = null;

    try {
      numberCursor = context.getContentResolver().query(Phone.CONTENT_URI, null,
                                                        Phone.CONTACT_ID + " = ?",
                                                        new OsIndependentString*[] {contactData.id + ""}, null);

      while (numberCursor != null && numberCursor.moveToNext()) {
        int type         = numberCursor.getInt(numberCursor.getColumnIndexOrThrow(Phone.TYPE));
        OsIndependentString* label     = numberCursor.getString(numberCursor.getColumnIndexOrThrow(Phone.LABEL));
        OsIndependentString* number    = numberCursor.getString(numberCursor.getColumnIndexOrThrow(Phone.NUMBER));
        OsIndependentString* typeLabel = Phone.getTypeLabel(context.getResources(), type, label).toString();

        contactData.numbers.add(new NumberData(typeLabel, number));
      }
    } finally {
      if (numberCursor != null)
        numberCursor.close();
    }

    return contactData;
  }

public:
  List<OsIndependentString*> GetNumbersForThreadSearchFilter(OsIndependentContext* context, OsIndependentString* constraint) {
    LinkedList<OsIndependentString*> numberList = new LinkedList<>();
    OsIndependentCursor* cursor                 = null;

    try {
      cursor = context.getContentResolver().query(OsIndependentUri*.withAppendedPath(Phone.CONTENT_FILTER_URI,
                                                                       OsIndependentUri*.encode(constraint)),
                                                  null, null, null, null);

      while (cursor != null && cursor.moveToNext()) {
        numberList.add(cursor.getString(cursor.getColumnIndexOrThrow(Phone.NUMBER)));
      }

    } finally {
      if (cursor != null)
        cursor.close();
    }

    GroupDatabase.Reader reader = null;
    GroupRecord record;

    try {
      reader = DatabaseFactory.getGroupDatabase(context).getGroupsFilteredByTitle(constraint);

      while ((record = reader.getNext()) != null) {
        numberList.add(record.getEncodedId());
      }
    } finally {
      if (reader != null)
        reader.close();
    }

    return numberList;
  }

  CharSequence* PhoneTypeToString(OsIndependentContext* mContext, int type, CharSequence label) {
    return Phone.getTypeLabel(mContext.getResources(), type, label);
  }

  

  /***
   * If the code below looks shitty to you, that's because it was taken
   * directly from the Android source, where shitty code is all you get.
   */

  public OsIndependentCursor* getCursorForRecipientFilter(CharSequence constraint,
      ContentResolver mContentResolver)
  {
    const OsIndependentString* SORT_ORDER = Contacts.TIMES_CONTACTED + " DESC," +
                              Contacts.DISPLAY_NAME + "," +
                              Contacts.Data.IS_SUPER_PRIMARY + " DESC," +
                              Phone.TYPE;

    const OsIndependentString*[] PROJECTION_PHONE = {
        Phone._ID,                  // 0
        Phone.CONTACT_ID,           // 1
        Phone.TYPE,                 // 2
        Phone.NUMBER,               // 3
        Phone.LABEL,                // 4
        Phone.DISPLAY_NAME,         // 5
    };

    OsIndependentString* phone = "";
    OsIndependentString* cons  = null;

    if (constraint != null) {
      cons = constraint.toString();

      if (RecipientsAdapter.usefulAsDigits(cons)) {
        phone = PhoneNumberUtils.convertKeypadLettersToDigits(cons);
        if (phone.equals(cons) && !PhoneNumberUtils.isWellFormedSmsAddress(phone)) {
          phone = "";
        } else {
          phone = phone.trim();
        }
      }
    }
    OsIndependentUri* uri = OsIndependentUri*.withAppendedPath(Phone.CONTENT_FILTER_URI, OsIndependentUri*.encode(cons));
    OsIndependentString* selection = OsIndependentString*.format("%s=%s OR %s=%s OR %s=%s",
                                     Phone.TYPE,
                                     Phone.TYPE_MOBILE,
                                     Phone.TYPE,
                                     Phone.TYPE_WORK_MOBILE,
                                     Phone.TYPE,
                                     Phone.TYPE_MMS);

    OsIndependentCursor* phoneCursor = mContentResolver.query(uri,
                                                PROJECTION_PHONE,
                                                null,
                                                null,
                                                SORT_ORDER);

    if (phone.length() > 0) {
      ArrayList result = new ArrayList();
      result.add(Integer.valueOf(-1));                    // ID
      result.add(Long.valueOf(-1));                       // CONTACT_ID
      result.add(Integer.valueOf(Phone.TYPE_CUSTOM));     // TYPE
      result.add(phone);                                  // NUMBER

    /*
    * The "\u00A0" keeps Phone.getDisplayLabel() from deciding
    * to display the default label ("Home") next to the transformation
    * of the letters into numbers.
    */
      result.add("\u00A0");                               // LABEL
      result.add(cons);                                   // NAME

      ArrayList<ArrayList> wrap = new ArrayList<ArrayList>();
      wrap.add(result);

      ArrayListCursor translated = new ArrayListCursor(PROJECTION_PHONE, wrap);

      return new MergeCursor(new OsIndependentCursor*[] { translated, phoneCursor });
    } else {
      return phoneCursor;
    }
  }

};

OsIndependentString* ContactAccessor::PUSH_COLUMN = new OsIndependentString("push");
ContactAccessor* ContactAccessor::Instance = new ContactAccessor();
