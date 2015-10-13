#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.IntentFilter
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/IntentFilter.java#IntentFilter
*/

// [ ] done
// TFS ID: 798

#include "..\Factory\Factory.h"

/*
public class  [More ...] IntentFilter implements Parcelable {
*/
class OsIndependentIntentFilter : public OsIndependentParcelable
{
public:
public:
};

/*
needs no Factory, because is abstract
*/
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------+  creates   +--------------------------+
| OsIndependentIntentFilter |<-----------|    FactoryIntentFilter   |
+---------------------------+            +--------------------------+
             ^                                          ^                Plattform independent code
            /|\                                        /|\
             |                                          |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                          |
             |                                          |                Plattform specific code
             |                                          |
+---------------------------+  creates   +--------------------------+
|     Tizen-IntentFilter    |<-----------| TizenFactoryIntentFilter |
+---------------------------+            +--------------------------+
*/
class FactoryIntentFilter
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryIntentFilter* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryIntentFilter* plattformSpecific) { FactoryIntentFilter::instance = plattformSpecific; }
  static FactoryIntentFilter* GetInstance()
  {
    if (FactoryIntentFilter::instance == nullptr)
      throw;
    return FactoryIntentFilter::instance;
  }
  // interface
  virtual OsIndependentIntentFilter* CreateNewIntentFilter(OsIndependentString*) = 0;
};
