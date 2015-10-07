#pragma once
/*
  abstract class OsIndependentAttributeSet to replace android.util.AttributeSet
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/util/AttributeSet.java#AttributeSet
*/

// [ ] done
// TFS ID: 667

#include "..\Factory\Factory.h"

/* public interface AttributeSet { */
class OsIndependentAttributeSet
{
private:
public:
  /*
  */
  
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------+  creates   +--------------------------+
| OsIndependentAttributeSet |<-----------|    FactoryAttributeSet   |
+---------------------------+            +--------------------------+
              ^                                 ^                Plattform independent code
             /|\                               /|\
              |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                 |
              |                                 |                Plattform specific code
              |                                 |
+---------------------------+  creates   +--------------------------+
|     Tizen-AttributeSet    |<-----------| TizenFactoryAttributeSet |
+---------------------------+            +--------------------------+
*/
class FactoryAttributeSet
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryAttributeSet* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryAttributeSet* plattformSpecific) { FactoryAttributeSet::instance = plattformSpecific; }
  static FactoryAttributeSet* GetInstance()
  {
    if (FactoryAttributeSet::instance == nullptr)
      throw;
    return FactoryAttributeSet::instance;
  }
  // interface
  virtual OsIndependentAttributeSet* CreateNewAttributeSet() = 0;
};
