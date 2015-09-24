#pragma once
/*
  abstract class OsIndependentInputStream to replace java.io.InputStream
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/io/InputStream.java#InputStream
*/

// [ ] done
// TFS ID: 680

/*
public abstract class InputStream implements Closeable {
*/
class OsIndependentInputStream
{
private:
public:
  // public void  [More ...] close() throws IOException {}
  void Close() {}
  // public int  [More ...] read(byte b[]) throws IOException {
  int Read(char* b, int len)
  {
    return Read(b, 0, len);
  }
  // public abstract int  [More ...] read() throws IOException;
  virtual int Read() = 0;
  // public int  [More ...] read(byte b[], int off, int len) throws IOException {
  int Read(char* b, int off, int len)
  {
    if (b == nullptr)
    {
      // TODO throw new NullPointerException();
    }
    else if (off < 0 || len < 0 || len > b.length - off)
    {
      // TODO throw new IndexOutOfBoundsException();
    }
    else if (len == 0)
    {
      return 0;
    }
    int c = Read();
    if (c == -1)
    {
      return -1;
    }
    b[off] = (char)c;
    int i = 1;
    try
    {
      for (; i < len; i++)
      {
        c = Read();
        if (c == -1)
        {
          break;
        }
        b[off + i] = (char)c;
      }
    }
    catch(...)/* TODO (IOException ee)*/
    {
    }
    return i;
  }
};
