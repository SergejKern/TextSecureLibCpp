#pragma once
/*
  abstract class OsIndependentCursor to replace java.lang.Thread
  http://developer.android.com/reference/android/net/Uri.html
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/Uri.java#Uri
*/

// [ ] done
// TFS ID: 784

#include "..\javastuff\Runnable.h"

// class  [More ...] Thread implements Runnable {
class OsIndependentThread : public Runnable
{
private:
public:
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------+  creates   +--------------------+
| OsIndependentThread |<-----------|    FactoryThread   |
+---------------------+            +--------------------+
           ^                                 ^                Plattform independent code
          /|\                               /|\
           |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                 |
           |                                 |                Plattform specific code
           |                                 |
+---------------------+  creates   +--------------------+
|     Tizen-Thread    |<-----------| TizenFactoryThread |
+---------------------+            +--------------------+
*/
class FactoryThread
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryThread* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryThread* plattformSpecific) { FactoryThread::instance = plattformSpecific; }
  static FactoryThread* GetInstance()
  {
    if (FactoryThread::instance == nullptr)
      throw;
    return FactoryThread::instance;
  }
  // interface
  virtual OsIndependentThread* CreateNewThread(OsIndependentString*) = 0;
};
