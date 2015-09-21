#pragma once
/*
  abstract class OsIndependentCursor to replace android.database.sqlite.SQLiteOpenHelper
  http://developer.android.com/reference/android/database/sqlite/SQLiteOpenHelper.html
*/

// [ ] done
// TFS ID: 659

class OsIndependentContext
{
private:
public:
  OsIndependentContext() {};
  /*
  Return the context of the single, global Application object of the current process. This generally should only be used if you need a Context whose lifecycle is separate from the current context, that is tied to the lifetime of the process rather than the current component.
  Consider for example how this interacts with registerReceiver(BroadcastReceiver, IntentFilter):
  - If used from an Activity context, the receiver is being registered within that activity. This means that you are expected to unregister before the activity is done being destroyed; in fact if you do not do so, the framework will clean up your leaked registration as it removes the activity and log an error. Thus, if you use the Activity context to register a receiver that is static (global to the process, not associated with an Activity instance) then that registration will be removed on you at whatever point the activity you used is destroyed.
  - If used from the Context returned here, the receiver is being registered with the global state associated with your application. Thus it will never be unregistered for you. This is necessary if the receiver is associated with static data, not a particular component. However using the ApplicationContext elsewhere can easily lead to serious leaks if you forget to unregister, unbind, etc. 
  http://developer.android.com/reference/android/content/Context.html#getApplicationContext%28%29
  */
  OsIndependentContext* GetApplicationContext();
};