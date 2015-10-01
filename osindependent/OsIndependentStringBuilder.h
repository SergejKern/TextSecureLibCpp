#pragma once
/*
  abstract class OsIndependentIntent to replace  java.lang.StringBuilder
  http://grepcode.com/file/repository.grepcode.com/java/root/jdk/openjdk/8u40-b25/java/lang/StringBuilder.java#StringBuilder
*/

// [ ] done
// TFS ID: 688

#include "OsIndependentString.h"

/*
a abstract class to be overvritten for every platform.
Tizen uses i18n
https://developer.tizen.org/development/tutorials/native-application/base/i18n#characters
Sailfish/Ubuntu -> Qstring
http://doc.qt.io/qt-4.8/qstring.html
*/
class OsIndependentStringBuilder
{
private:
  int count;
public:
  OsIndependentStringBuilder* Append(OsIndependentString* str);
  /* java.lang.AbstractStringBuilder.length()*/ int Length() { return count; }
  OsIndependentString* ToString();
};
