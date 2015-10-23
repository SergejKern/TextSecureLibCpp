#pragma once

/* 
   java.io.Closeable
   http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/7u40-b43/java/io/Closeable.java#Closeable
 */

// [x] done
// TFS ID: none

//public interface  [More ...] Runnable {
//}
class Runnable
{
public:
  /* 
  When an object implementing interface Runnable is used to create a thread, starting the thread causes the object's run method to be called in that separately executing thread.
  The general contract of the method run is that it may take any action whatsoever.
  */
  virtual void Run() = 0;
};

//public interface[More ...] Executor{
class Executor
{
public:
  /*
  */
  virtual void Execute(Runnable* command);
};
