#pragma once
/*
Port of class ContactIdentityManager from TextSecure-android
*/

// [x] done
// TFS ID: 422

#include "ContactIdentityManager.h"

//import android.content.Context;
//import android.content.SharedPreferences;
//import android.database.Cursor;
//import android.net.Uri;
//import android.preference.PreferenceManager;
//import android.provider.ContactsContract;
//import android.provider.ContactsContract.Contacts;
//import android.provider.ContactsContract.PhoneLookup;
//import android.provider.ContactsContract.RawContacts;
//import android.telephony.TelephonyManager;
//
//import org.thoughtcrime.securesms.ApplicationPreferencesActivity;
//import org.thoughtcrime.securesms.util.TextSecurePreferences;
//
//import java.util.ArrayList;
//import java.util.List;

// a class to support android > 2.3 and < 4.0
// IGNORE!!!
class ContactIdentityManagerGingerbread : ContactIdentityManager
{ };
