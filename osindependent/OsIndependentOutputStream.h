#pragma once
/*
  abstract class OsIndependentInputStream to replace java.io.OutputStream
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/InputStream.java#InputStream
*/

// [x] done
// TFS ID: 681

/*
public abstract class OutputStream implements Closeable, Flushable {
*/
class OsIndependentOutputStream
{
private:
public:
  // public abstract void  [More ...] write(int b) throws IOException;
  virtual void Write(int b) = 0;
  // public void[More ...] write(byte b[]) throws IOException{
  void Write(char* b, int len)
  {
    Write(b, 0, len);
  }
  // public void  [More ...] write(byte b[], int off, int len) throws IOException {
  void Write(char* b, int off, int len)
  {
    if (b == nullptr)
    {
      // TODO throw new NullPointerException();
    }
    else if ((off < 0) || (off > len) || (len < 0) || ((off + len) > len) || ((off + len) < 0))
    {
      // TODO throw new IndexOutOfBoundsException();
    }
    else if (len == 0)
    {
      return;
    }
    for (int i = 0; i < len; i++)
    {
      Write(b[off + i]); // TODO
    }
  }
  // public void  [More ...] flush() throws IOException {
  void Flush() {}
  // public void  [More ...] close() throws IOException {
  void Close() {}
};
