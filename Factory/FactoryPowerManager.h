#pragma once
/*
*/

// [x] done
// TFS ID: none

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------+  creates   +--------------------------+
| OsIndependentPowerManager |<-----------|    FactoryPowerManager   |
+---------------------------+            +--------------------------+
              ^                                       ^                Plattform independent code
             /|\                                     /|\
              |                                       |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                       |
              |                                       |                Plattform specific code
              |                                       |
+---------------------------+  creates   +--------------------------+
|     Tizen-PowerManager    |<-----------| TizenFactoryPowerManager |
+---------------------------+            +--------------------------+


*/

#include "..\osindependent\OsIndependentPowerManager.h"

/*
a abstract class to be overvritten for every platform
*/
class FactoryPowerManager
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryPowerManager* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryPowerManager* plattformSpecific) { FactoryPowerManager::instance = plattformSpecific; }
  static FactoryPowerManager* GetInstance()
  {
    if (FactoryPowerManager::instance == nullptr)
      throw;
    return FactoryPowerManager::instance;
  }
  // interface
  virtual OsIndependentPowerManager* CreateNewPowerManager() = 0;
};
