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
needs no Factory, because is abstract
*/
