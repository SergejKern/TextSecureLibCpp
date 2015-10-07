#pragma once
/*
  abstract class OsIndependentInputStream to replace java.io.InputStream
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/InputStream.java#InputStream
*/

// [x] done
// TFS ID: 680

#include "..\Factory\Factory.h"
#include "..\owntemplates\ArrayList.h"

/*
public abstract class InputStream implements Closeable {
*/
class OsIndependentInputStream : public Closeable
{
private:
public:
  virtual int Available() = 0;
  // public void  [More ...] close() throws IOException {}
  virtual void Close() = 0;
  //synchronized void[More ...] mark(int readlimit) {}
  virtual void Mark(int readlimit) = 0;
  virtual bool MarkSupported() = 0;
  // public int  [More ...] read(byte b[]) throws IOException {
  virtual int Read(ArrayList<char>* b) = 0;
  // public abstract int  [More ...] read() throws IOException;
  virtual int Read() = 0;
  // public int  [More ...] read(byte b[], int off, int len) throws IOException {
  virtual int Read(ArrayList<char>* b, int off, int len) = 0;
  // public synchronized void  [More ...] reset() throws IOException {
  virtual void Reset() = 0;
  //long[More ...] skip(long n) throws IOException
  virtual long Skip(long n) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+---------------------------+  creates   +--------------------------+
| OsIndependentInputStream  |<-----------|    FactoryInputStream    |
+---------------------------+            +--------------------------+
             ^                                         ^                Plattform independent code
            /|\                                       /|\
             |                                         |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
             |                                         |
             |                                         |                Plattform specific code
             |                                         |
+---------------------------+  creates   +--------------------------+
|     Tizen-InputStream     |<-----------| TizenFactoryInputStream  |
+---------------------------+            +--------------------------+
*/
class FactoryInputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryInputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryInputStream* plattformSpecific) { FactoryInputStream::instance = plattformSpecific; }
  static FactoryInputStream* GetInstance()
  {
    if (FactoryInputStream::instance == nullptr)
      throw;
    return FactoryInputStream::instance;
  }
  // interface
  virtual OsIndependentInputStream* CreateNewInputStream() = 0;
};
