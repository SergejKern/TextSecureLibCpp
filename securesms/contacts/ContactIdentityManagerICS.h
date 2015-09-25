#pragma once
/*
Port of class ContactIdentityManager from TextSecure-android
*/

// [x] done
// TFS ID: 423

#include "ContactIdentityManager.h"

//import android.annotation.SuppressLint;
#include "..\..\osindependent\OsIndependentContext.h"
//import android.database.Cursor;
//import android.net.Uri;
//import android.provider.ContactsContract;
//import android.provider.ContactsContract.Contacts;
//import android.provider.ContactsContract.PhoneLookup;
//
//import java.util.LinkedList;
//import java.util.List;

// a class to support android > 4.0
// IGNORE!!!
class ContactIdentityManagerICS : ContactIdentityManager
{
};
