#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.PowerManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/PowerManager.java#PowerManager
*/

// [ ] done
// TFS ID: 765

#include "..\Factory\Factory.h"

/*
public final class  PowerManager {
*/
class OsIndependentPowerManager
{
public:
  class WakeLock
  {
  public:
    virtual void Acquire() = 0;
    virtual void Acquire(long timeout) = 0;
    virtual bool IsHeld() = 0;
    virtual void Release() = 0;
  };
public:
  static const int PARTIAL_WAKE_LOCK = 0x00000001;
public:
  virtual WakeLock* NewWakeLock(int levelAndFlags, OsIndependentString* tag) = 0;
};
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
