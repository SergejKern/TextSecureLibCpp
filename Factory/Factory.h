#pragma once
/*
  includes all factory classes
*/

// [ ] done
// TFS ID: none

#include "..\osindependent\OsIndependentAbstractThreadedSyncAdapter.h"
#include "..\osindependent\OsIndependentAccount.h"
#include "..\osindependent\OsIndependentActivity.h"
#include "..\osindependent\OsIndependentAttributeSet.h"
#include "..\osindependent\OsIndependentBitmap.h"
#include "..\osindependent\OsIndependentBundle.h"
#include "..\osindependent\OsIndependentConnectivityManager.h"
#include "..\osindependent\OsIndependentContentObserver.h"
#include "..\osindependent\OsIndependentContentProviderClient.h"
#include "..\osindependent\OsIndependentContentResolver.h"
#include "..\osindependent\OsIndependentContentValues.h"
#include "..\osindependent\OsIndependentContext.h"
#include "..\osindependent\OsIndependentCursor.h"
#include "..\osindependent\OsIndependentDrawable.h"
#include "..\osindependent\OsIndependentFragmentActivity.h"
#include "..\osindependent\OsIndependentFragmentManager.h"
#include "..\osindependent\OsIndependentInputMethodManager.h"
#include "..\osindependent\OsIndependentInputStream.h"
#include "..\osindependent\OsIndependentIntent.h"
#include "..\osindependent\OsIndependentKeyEvent.h"
#include "..\osindependent\OsIndependentNetworkInfo.h"
#include "..\osindependent\OsIndependentOutputStream.h"
#include "..\osindependent\OsIndependentPackageInfo.h"
#include "..\osindependent\OsIndependentPackageManager.h"
#include "..\osindependent\OsIndependentParcel.h"
#include "..\osindependent\OsIndependentParcelable.h"
#include "..\osindependent\OsIndependentPowerManager.h"
#include "..\osindependent\OsIndependentResources.h"
#include "..\osindependent\OsIndependentRingtonePreference.h"
#include "..\osindependent\OsIndependentSQLiteClosable.h"
#include "..\osindependent\OsIndependentSQLiteCursorDriver.h"
#include "..\osindependent\OsIndependentSQLiteDatabase.h"
#include "..\osindependent\OsIndependentSQLiteOpenHelper.h"
#include "..\osindependent\OsIndependentSQLiteProgram.h"
#include "..\osindependent\OsIndependentSQLiteQuery.h"
#include "..\osindependent\OsIndependentSQLiteStatement.h"
#include "..\osindependent\OsIndependentString.h"
#include "..\osindependent\OsIndependentStringBuilder.h"
#include "..\osindependent\OsIndependentSyncResult.h"
#include "..\osindependent\OsIndependentSystem.h"
#include "..\osindependent\OsIndependentThread.h"
#include "..\osindependent\OsIndependentUri.h"
#include "..\osindependent\OsIndependentWindowManager.h"

//// bad idea
//template <typename E> class Factory
//{
//private:
//  // a Instance of implemented plattform specific factory
//  // which has to be set in plattform specific code
//  static Factory<E>* instance;
//public:
//  // has to be called in plattform specific code
//  static void SetInstance(Factory<E>* plattformSpecific) { Factory::instance = plattformSpecific; }
//  static Factory<E>* GetInstance()
//  {
//    if (Factory::instance == nullptr)
//      throw;
//    return Factory::instance;
//  }
//  // interface
//  virtual E* CreateNewObject() = 0;
//};
