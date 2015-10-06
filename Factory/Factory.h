#pragma once
/*
  includes all factory classes
*/

// [ ] done
// TFS ID: none

#include "FactoryContentValues.h"
#include "FactoryContext.h"
#include "FactoryCursor.h"
#include "FactoryPowerManager.h"
#include "FactorySQLiteCursorDriver.h"
#include "FactorySQLiteDatabase.h"
#include "FactorySQLiteOpenHelper.h"
#include "FactorySQLiteQuery.h"
#include "FactoryString.h"
#include "FactoryThread.h"

// bad idea
//template <typename E> class Factory
//{
//private:
//  // a Instance of implemented plattform specific factory
//  // which has to be set in plattform specific code
//  static Factory* instance;
//public:
//  // has to be called in plattform specific code
//  static void SetInstance(Factory* plattformSpecific) { Factory::instance = plattformSpecific; }
//  static Factory* GetInstance()
//  {
//    if (Factory::instance == nullptr)
//      throw;
//    return Factory::instance;
//  }
//  // interface
//  virtual E* CreateNewObject() = 0;
//};
