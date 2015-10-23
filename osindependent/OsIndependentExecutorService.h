#pragma once
/*
  abstract class OsIndependentCursor to  java.util.concurrent.ExecutorService
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/util/concurrent/ExecutorService.java#ExecutorService
*/

// [ ] done
// TFS ID: 805

#include "..\javastuff\Runnable.h"

/*
public interface  [More ...] ExecutorService extends Executor {
*/
class OsIndependentExecutorService : public Executor
{
private:
  OsIndependentExecutorService();
public:
};
/*
needs no Factory, because is abstract
*/
