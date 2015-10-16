#pragma once
/*
  abstract class OsIndependentIntent to replace java.lang.System
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/lang/System.java#System
*/

// [ ] done
// TFS ID: 676

class OsIndependentSystem
{
private:
public:
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/net/Uri.html
  */
  virtual int GetColorTransparent() = 0;
  virtual long CurrentTimeMillis() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentSystem  |<-----------|    FactorySystem    |
+----------------------+            +---------------------+
           ^                                 ^                Plattform independent code
          /|\                               /|\
           |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                 |
           |                                 |                Plattform specific code
           |                                 |
+----------------------+  creates   +---------------------+
|     Tizen-System     |<-----------| TizenFactorySystem  |
+----------------------+            +---------------------+
*/
class FactorySystem
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactorySystem* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactorySystem* plattformSpecific) { FactorySystem::instance = plattformSpecific; }
  static FactorySystem* GetInstance()
  {
    if (FactorySystem::instance == nullptr)
      throw;
    return FactorySystem::instance;
  }
  // interface
  virtual OsIndependentSystem* CreateNewSystem() = 0;
};
