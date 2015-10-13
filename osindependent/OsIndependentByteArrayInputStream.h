#pragma once
/*
abstract class OsIndependentByteArrayInputStream to replace java.io.ByteArrayInputStream
http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/ByteArrayInputStream.java#ByteArrayInputStream
*/

// [x] done
// TFS ID: 799

#include "..\Factory\Factory.h"

/*
class  [More ...] ByteArrayInputStream extends InputStream {
*/
class OsIndependentByteArrayInputStream : public OsIndependentInputStream
{
private:
public:
  //public synchronized int[More ...] available() {
  virtual int Available() = 0;
  //public void  [More ...] close() throws IOException {
  virtual void Close() = 0;
  //public void  [More ...] mark(int readAheadLimit) {
  virtual void Mark() = 0;
  //public boolean  [More ...] markSupported() {
  virtual bool MarkSupported() = 0;
  //public synchronized int  [More ...] read() {
  virtual int Read() = 0;
  //public synchronized int  [More ...] read(byte b[], int off, int len) {
  virtual int Read(std::vector<unsigned char>* b, int off, int len) = 0;
  //public synchronized void  [More ...] reset() {
  virtual void Reset() = 0;
  //public synchronized long  [More ...] skip(long n) {
  virtual void Skip() = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+-----------------------------------+  creates   +----------------------------------+
| OsIndependentByteArrayInputStream |<-----------|    FactoryByteArrayInputStream   |
+-----------------------------------+            +----------------------------------+
^                                              ^                Plattform independent code
/|\                                            /|\
|                                              |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
|                                              |
|                                              |                Plattform specific code
|                                              |
+-----------------------------------+  creates   +----------------------------------+
|     Tizen-ByteArrayInputStream    |<-----------| TizenFactoryByteArrayInputStream |
+-----------------------------------+            +----------------------------------+
*/
class FactoryByteArrayInputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryByteArrayInputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryByteArrayInputStream* plattformSpecific) { FactoryByteArrayInputStream::instance = plattformSpecific; }
  static FactoryByteArrayInputStream* GetInstance()
  {
    if (FactoryByteArrayInputStream::instance == nullptr)
      throw;
    return FactoryByteArrayInputStream::instance;
  }
  // interface
  virtual OsIndependentByteArrayInputStream* CreateNewByteArrayInputStream(std::vector<unsigned char>* buf) = 0;
  virtual OsIndependentByteArrayInputStream* CreateNewByteArrayInputStream(std::vector<unsigned char>* buf, int offset, int length) = 0;
};
