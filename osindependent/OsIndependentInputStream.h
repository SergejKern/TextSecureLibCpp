#pragma once
/*
  abstract class OsIndependentInputStream to replace java.io.InputStream
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/InputStream.java#InputStream
*/

// [x] done
// TFS ID: 680

#include <vector>
#include "..\Factory\Factory.h"

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
  virtual int Read(std::vector<unsigned char>* b) = 0;
  // public abstract int  [More ...] read() throws IOException;
  virtual int Read() = 0;
  // public int  [More ...] read(byte b[], int off, int len) throws IOException {
  virtual int Read(std::vector<unsigned char>* b, int off, int len) = 0;
  // public synchronized void  [More ...] reset() throws IOException {
  virtual void Reset() = 0;
  //long[More ...] skip(long n) throws IOException
  virtual long Skip(long n) = 0;
};
/*
needs no Factory, because is abstract
*/
