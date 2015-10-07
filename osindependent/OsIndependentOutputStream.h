#pragma once
/*
  abstract class OsIndependentInputStream to replace java.io.OutputStream
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/OutputStream.java#OutputStream
*/

// [x] done
// TFS ID: 681

#include "..\Factory\Factory.h"
#include "..\javastuff\Closeable.h"
#include "..\owntemplates\ArrayList.h"

/*
public abstract class OutputStream implements Closeable, Flushable {
*/
class OsIndependentOutputStream : public Closeable, public Flushable
{
private:
public:
  // public abstract void  [More ...] write(int b) throws IOException;
  virtual void Write(int b) = 0;
  // public void[More ...] write(byte b[]) throws IOException{
  virtual void Write(ArrayList<char>* b) = 0;
  // public void  [More ...] write(byte b[], int off, int len) throws IOException {
  virtual void Write(ArrayList<char>* b, int off, int len) = 0;
  // public void  [More ...] flush() throws IOException {
  virtual void Flush() = 0;
  // public void  [More ...] close() throws IOException {
  virtual void Close() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------+  creates   +--------------------------+
| OsIndependentOutputStream |<-----------|    FactoryOutputStream   |
+---------------------------+            +--------------------------+
              ^                                       ^                Plattform independent code
             /|\                                     /|\
              |                                       |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
              |                                       |
              |                                       |                Plattform specific code
              |                                       |
+---------------------------+  creates   +--------------------------+
|     Tizen-OutputStream    |<-----------| TizenFactoryOutputStream |
+---------------------------+            +--------------------------+
*/
class FactoryOutputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryOutputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryOutputStream* plattformSpecific) { FactoryOutputStream::instance = plattformSpecific; }
  static FactoryOutputStream* GetInstance()
  {
    if (FactoryOutputStream::instance == nullptr)
      throw;
    return FactoryOutputStream::instance;
  }
  // interface
  virtual OsIndependentOutputStream* CreateNewOutputStream() = 0;
};
