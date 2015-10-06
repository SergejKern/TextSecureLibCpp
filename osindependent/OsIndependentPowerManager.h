#pragma once
/*
  abstract class OsIndependentCursor to replace android.os.PowerManager
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/PowerManager.java#PowerManager
*/

// [ ] done
// TFS ID: 765

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
