#pragma once
/*
  abstract class OsIndependentCursor to replace java.util.concurrent.Executors
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/concurrent/Executors.java#Executors
*/

// [ ] done
// TFS ID: 806

#include "OsIndependentExecutorService.h"

/*
public class  [More ...] Executors {
  Class java.util.concurrent.Executors contains only static methods,
  all of them can be implemented inside of factory
*/

/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------+  creates   +-----------------------+
| OsIndependentExecutors |<-----------|    FactoryExecutors   |
+------------------------+            +-----------------------+
           ^                                      ^                Plattform independent code
          /|\                                    /|\
           |                                      |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
           |                                      |
           |                                      |                Plattform specific code
           |                                      |
+------------------------+  creates   +-----------------------+
|     Tizen-Executors    |<-----------| TizenFactoryExecutors |
+------------------------+            +-----------------------+
*/
class FactoryExecutors
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryExecutors* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryExecutors* plattformSpecific) { FactoryExecutors::instance = plattformSpecific; }
  static FactoryExecutors* GetInstance()
  {
    if (FactoryExecutors::instance == nullptr)
      throw;
    return FactoryExecutors::instance;
  }
  // interface
  // public static ExecutorService  [More ...] newSingleThreadExecutor() {
  virtual OsIndependentExecutorService* NewSingleThreadExecutor() = 0;
};
