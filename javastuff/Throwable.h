#pragma once

// java.lang.Throwable
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b27/java/lang/Throwable.java#Throwable

// [ ] done
// TFS ID: none

// public class Throwable implements Serializable {
class Throwable
{
private:
  unsigned char* detailMessage;
public:
  Throwable() {}
  Throwable(unsigned char* message) {}
  Throwable(unsigned char* message, Throwable* cause) {}
  Throwable(Throwable* cause) {}
  unsigned char* GetMessage()
  {
    return this->detailMessage;
  }
};
