#pragma once
/*
abstract class OsIndependentObjectInputStream to replace java.io.ObjectInputStream
http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/ObjectInputStream.java#ObjectInputStream
*/

// [ ] done
// TFS ID: 801

#include "OsIndependentInputStream.h"

/*
class  [More ...] ObjectInputStream extends InputStream {
*/
class OsIndependentObjectInputStream : public OsIndependentInputStream
{
private:
public:
  // public final Object[More ...] readObject()
  // TODO!! Can't work like this!!!
  virtual void* ReadObject() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+--------------------------------+  creates   +-------------------------------+
| OsIndependentObjectInputStream |<-----------|    FactoryObjectInputStream   |
+--------------------------------+            +-------------------------------+
               ^                                              ^                Plattform independent code
              /|\                                            /|\
               |                                              |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
               |                                              |
               |                                              |                Plattform specific code
               |                                              |
+--------------------------------+  creates   +-------------------------------+
|     Tizen-ObjectInputStream    |<-----------| TizenFactoryObjectInputStream |
+--------------------------------+            +-------------------------------+
*/
class FactoryObjectInputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryObjectInputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryObjectInputStream* plattformSpecific) { FactoryObjectInputStream::instance = plattformSpecific; }
  static FactoryObjectInputStream* GetInstance()
  {
    if (FactoryObjectInputStream::instance == nullptr)
      throw;
    return FactoryObjectInputStream::instance;
  }
  // interface
  virtual OsIndependentObjectInputStream* CreateNewObjectInputStream(OsIndependentInputStream*) = 0;
};
