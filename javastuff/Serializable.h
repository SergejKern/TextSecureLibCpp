#pragma once

/* 
   java.io.Serializable
   http://grepcode.com/file/repo1.maven.org/maven2/org.robolectric/android-all/5.0.0_r2-robolectric-1/java/io/Serializable.java#Serializable
 */

// [x] done
// TFS ID: none

#include "Exception.h"

//public interface[More ...] Serializable{
//}

class Serializable
{
};

/*
   java.util.concurrent.atomic.AtomicBoolean
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/concurrent/atomic/AtomicBoolean.java#AtomicBoolean
*/
// public class  [More ...] AtomicBoolean implements java.io.Serializable {

class AtomicBoolean : public Serializable
{
private:
  volatile int value;
  static const long valueOffset;
public:
  AtomicBoolean(bool initialValue)
  {
    value = initialValue ? 1 : 0;
  }
  bool CompareAndSet(bool expect, bool update)
  {
    if (this->value == expect)
    {
      this->value = update;
      return true;
    }
    return false;
  }
};
