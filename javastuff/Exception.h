#pragma once

// java.util.concurrent.ExecutionException
// http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/6-b27/java/lang/Exception.java#Exception

// [ ] done
// TFS ID: none

class Exception /* extends Throwable */
{
public:
  Exception() {}
  Exception(unsigned char* message) {}
  Exception(unsigned char* message, /*Throwable*/Exception* cause) {}
  Exception(/*Throwable*/Exception* cause) {}
};
