#pragma once
/*
abstract class OsIndependentByteArrayInputStream to replace java.io.ByteArrayOutputStream
http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/ByteArrayOutputStream.java#ByteArrayOutputStream
*/

// [x] done
// TFS ID: 800

#include "..\Factory\Factory.h"

/*
class  [More ...] ByteArrayOutputStream extends InputStream {
*/
class OsIndependentByteArrayOutputStream : public OsIndependentOutputStream
{
private:
public:
  // public void  [More ...] close() throws IOException {
  virtual void Close() = 0;
  // public synchronized void  [More ...] reset() {
  virtual void Reset() = 0;
  // public synchronized int  [More ...] size() {
  virtual void Size() = 0;
  // public synchronized byte  [More ...] toByteArray()[] {
  virtual std::vector<unsigned char>* ToByteArray() = 0;
  // public synchronized String  [More ...] toString() {
  virtual void ToString() = 0;
  // public synchronized String  [More ...] toString(String charsetName)
  virtual void ToString(unsigned char* charsetName) = 0;
  // public synchronized void  [More ...] write(int b) {
  virtual void Write(int b) = 0;
  // public synchronized void  [More ...] write(byte b[], int off, int len) {
  virtual void Write(std::vector<unsigned char>* b, int off, int len) = 0;
  // public synchronized void  [More ...] writeTo(OutputStream out) throws IOException {
  virtual void WriteTo(OsIndependentOutputStream*) = 0;
};
/*
Plattform independend Factory abstract class.
This class must be implemented for specific plattforms, to create plattform specific String-classes

+------------------------------------+  creates   +-----------------------------------+
| OsIndependentByteArrayOutputStream |<-----------|    FactoryByteArrayOutputStream   |
+------------------------------------+            +-----------------------------------+
                  ^                                                 ^                Plattform independent code
                 /|\                                               /|\
                  |                                                 |
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  |                                                 |
                  |                                                 |                Plattform specific code
                  |                                                 |
+------------------------------------+  creates   +-----------------------------------+
|     Tizen-ByteArrayOutputStream    |<-----------| TizenFactoryByteArrayOutputStream |
+------------------------------------+            +-----------------------------------+
*/
class FactoryByteArrayOutputStream
{
private:
  // a Instance of implemented plattform specific factory
  // which has to be set in plattform specific code
  static FactoryByteArrayOutputStream* instance;
public:
  // has to be called in plattform specific code
  static void SetInstance(FactoryByteArrayOutputStream* plattformSpecific) { FactoryByteArrayOutputStream::instance = plattformSpecific; }
  static FactoryByteArrayOutputStream* GetInstance()
  {
    if (FactoryByteArrayOutputStream::instance == nullptr)
      throw;
    return FactoryByteArrayOutputStream::instance;
  }
  // interface
  virtual OsIndependentByteArrayOutputStream* CreateNewByteArrayOutputStream() = 0;
  virtual OsIndependentByteArrayOutputStream* CreateNewByteArrayOutputStream(int) = 0;
};
