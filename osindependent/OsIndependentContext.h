#pragma once
/*
  abstract class OsIndependentCursor to replace android.content.Context
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/Context.java#Context
*/

// [ ] done
// TFS ID: 658

#include "..\Factory\Factory.h"

class OsIndependentContext
{
public:
  static const OsIndependentString* INPUT_METHOD_SERVICE;
  static const OsIndependentString* CONNECTIVITY_SERVICE;
  static const OsIndependentString* POWER_SERVICE;
public:
  /*
  Return the context of the single, global Application object of the current process. This generally should only be used if you need a Context whose lifecycle is separate from the current context, that is tied to the lifetime of the process rather than the current component.
  Consider for example how this interacts with registerReceiver(BroadcastReceiver, IntentFilter):
  - If used from an Activity context, the receiver is being registered within that activity. This means that you are expected to unregister before the activity is done being destroyed; in fact if you do not do so, the framework will clean up your leaked registration as it removes the activity and log an error. Thus, if you use the Activity context to register a receiver that is static (global to the process, not associated with an Activity instance) then that registration will be removed on you at whatever point the activity you used is destroyed.
  - If used from the Context returned here, the receiver is being registered with the global state associated with your application. Thus it will never be unregistered for you. This is necessary if the receiver is associated with static data, not a particular component. However using the ApplicationContext elsewhere can easily lead to serious leaks if you forget to unregister, unbind, etc. 
  http://developer.android.com/reference/android/content/Context.html#getApplicationContext%28%29
  */
  virtual OsIndependentContext* GetApplicationContext() = 0;
  virtual OsIndependentPackageManager* GetPackageManager() = 0;
  virtual OsIndependentString* GetPackageName() = 0;
  // public abstract Object  [More ...] getSystemService(@ServiceName @NonNull String name);
  virtual void* GetSystemService(OsIndependentString* name) = 0;
  virtual OsIndependentResources* GetResources() = 0;
  // public abstract ContentResolver getContentResolver();
  virtual OsIndependentContentResolver* GetContentResolver() = 0;
  virtual void SendBroadcast(OsIndependentIntent* intent, OsIndependentString* receiverPermission) = 0;
  virtual OsIndependentString* GetString(int resId) = 0;
  //public final String[More ...] getString(int resId, Object... formatArgs) {
  virtual OsIndependentString* GetString(int resId, OsIndependentString*) = 0;
  // public abstract Intent  [More ...] registerReceiver(@Nullable BroadcastReceiver receiver, IntentFilter filter);
  virtual OsIndependentIntent* RegisterReceiver(OsIndependentBroadcastReceiver*, OsIndependentIntentFilter*) = 0;

};

const OsIndependentString* OsIndependentContext::INPUT_METHOD_SERVICE = FactoryString::GetInstance()->CreateNewString("input_method");
const OsIndependentString* OsIndependentContext::CONNECTIVITY_SERVICE = FactoryString::GetInstance()->CreateNewString("connectivity");
const OsIndependentString* OsIndependentContext::POWER_SERVICE = FactoryString::GetInstance()->CreateNewString("power");

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+----------------------+  creates   +---------------------+
| OsIndependentContext |<-----------|    FactoryContext   |
+----------------------+            +---------------------+
           ^                                 ^                Plattform independent code
          /|\                               /|\
           |                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                 |
           |                                 |                Plattform specific code
           |                                 |
+----------------------+  creates   +---------------------+
|     Tizen-Context    |<-----------| TizenFactoryContext |
+----------------------+            +---------------------+
*/
class FactoryContext
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryContext* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryContext* plattformSpecific) { FactoryContext::instance = plattformSpecific; }
  static FactoryContext* GetInstance()
  {
    if (FactoryContext::instance == nullptr)
      throw;
    return FactoryContext::instance;
  }
  // interface
  virtual OsIndependentContext* CreateNewContext() = 0;
};
