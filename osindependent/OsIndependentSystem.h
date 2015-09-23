#pragma once
/*
  abstract class OsIndependentIntent to replace android.content.Intent
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/content/Intent.java#Intent
*/

// [ ] done
// TFS ID: 676

class OsIndependentSystem
{
private:
public:
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/net/Uri.html
  */
  static int GetColorTransparent();
};
