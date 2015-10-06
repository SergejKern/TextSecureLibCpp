#pragma once
/*
  abstract class OsIndependentIntent to replace java.lang.String
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/lang/String.java#String
*/

// [ ] done
// TFS ID: 687

#include "..\owntemplates\ArrayList.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class OsIndependentString
{
private:
public:
  virtual bool StartsWith(OsIndependentString*) = 0;
  virtual ArrayList<OsIndependentString*>* Split(OsIndependentString*, int) = 0;
  virtual ArrayList<OsIndependentString*>* Split(const char*, int) = 0;
  virtual OsIndependentString* Trim() = 0;
  virtual bool IsEmpty() = 0;
  virtual ArrayList<char>* GetBytes() = 0;
};
