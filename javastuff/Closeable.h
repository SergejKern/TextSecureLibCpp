#pragma once

/* 
   java.io.Closeable
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/7u40-b43/java/io/Closeable.java#Closeable
 */

// [x] done
// TFS ID: none

// public interface[More ...] AutoCloseable{
class AutoCloseable
{
  // void  [More ...] close() throws Exception;
  virtual void Close() = 0;
};

//public public interface  [More ...] Closeable extends AutoCloseable {
//}
class Closeable : public AutoCloseable
{
  /* 
  Closes this stream and releases any system resources associated with it. If the stream is already closed then invoking this method has no effect.
  Throws:
  IOException if an I/O error occurs
  public void  [More ...] close() throws IOException; */
  virtual void Close() = 0;
};
