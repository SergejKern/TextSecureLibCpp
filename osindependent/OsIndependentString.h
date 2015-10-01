#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.Intent
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/Intent.java#Intent
*/

// [ ] done
// TFS ID: 687


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
  OsIndependentString(unsigned char*);
  OsIndependentString(char*);
  // operator char*();
  // operator const char*();
  static bool IsNullOrEmpty(OsIndependentString*);
  bool StartsWith(OsIndependentString*);
  /*array*/ char* Split(OsIndependentString*, int);
  /*array*/ char* Split(const char*, int);
  OsIndependentString* Trim();
  bool IsEmpty();
};
