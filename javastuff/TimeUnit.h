#pragma once

/* 
   java.util.concurrent.TimeUnit
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/concurrent/TimeUnit.java#TimeUnit
 */

// [ ] done
// TFS ID: none


//public enum  [More ...] TimeUnit {
class TimeUnit
{
private:
  static const long MAX_VALUE = 0x7fffffffffffffffL;
  static const long MIN_VALUE = 0x8000000000000000L;
public:
  class MILLISECONDS
  {
  public:
    long ToNanos(long d) { return x(d, C2 / C0, MAX / (C2 / C0)); }
    long ToMicros(long d) { return x(d, C2 / C1, MAX / (C2 / C1)); }
    long ToMillis(long d) { return d; }
    long ToSeconds(long d) { return d / (C3 / C2); }
    long ToMinutes(long d) { return d / (C4 / C2); }
    long ToHours(long d) { return d / (C5 / C2); }
    long ToDays(long d) { return d / (C6 / C2); }
    long Convert(long d, TimeUnit* u) { return u->ToMillis(d); }
    int ExcessNanos(long d, long m) { return 0; }
  };

  // Handy constants for conversion methods
  static const long C0 = 1L;
  static const long C1 = C0 * 1000L;
  static const long C2 = C1 * 1000L;
  static const long C3 = C2 * 1000L;
  static const long C4 = C3 * 60L;
  static const long C5 = C4 * 60L;
  static const long C6 = C5 * 24L;
  
  static const long MAX = MAX_VALUE;

  static long x(long d, long m, long over)
  {
    if (d >  over) return MAX_VALUE;
    if (d < -over) return MIN_VALUE;
    return d * m;
  }
  long ToMillis(long duration)
  {
    throw; /*new AbstractMethodError();*/
  }
};
