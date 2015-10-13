#pragma once
/*
abstract class OsIndependentObjectOutputStream to replace java.io.ObjectOutputStream
http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/ObjectOutputStream.java#ObjectOutputStream
*/

// [ ] done
// TFS ID: 802

#include "..\Factory\Factory.h"

/*
public class  [More ...] ObjectOutputStream
extends OutputStream implements ObjectOutput, ObjectStreamConstants
*/
class OsIndependentObjectOutputStream : public OsIndependentOutputStream
{
private:
public:
  // public final void  [More ...] writeObject(Object obj) throws IOException {
  virtual void WriteObject(void* obj) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------------+  creates   +--------------------------------+
| OsIndependentObjectOutputStream |<-----------|    FactoryObjectOutputStream   |
+---------------------------------+            +--------------------------------+
                  ^                                              ^                Plattform independent code
                 /|\                                            /|\
                  |                                              |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  |                                              |
                  |                                              |                Plattform specific code
                  |                                              |
+---------------------------------+  creates   +--------------------------------+
|     Tizen-ObjectOutputStream    |<-----------| TizenFactoryObjectOutputStream |
+---------------------------------+            +--------------------------------+
*/
class FactoryObjectOutputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryObjectOutputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryObjectOutputStream* plattformSpecific) { FactoryObjectOutputStream::instance = plattformSpecific; }
  static FactoryObjectOutputStream* GetInstance()
  {
    if (FactoryObjectOutputStream::instance == nullptr)
      throw;
    return FactoryObjectOutputStream::instance;
  }
  // interface
  virtual OsIndependentObjectOutputStream* CreateNewObjectOutputStream(OsIndependentOutputStream*) = 0;
};
