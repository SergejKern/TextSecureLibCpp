#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.Uri
  http://developer.android.com/reference/android/net/Uri.html
*/

// [ ] done
// TFS ID: 329

class OsIndependentParcel
{
private:
public:
  OsIndependentParcel() {};
  /*
  Move the cursor to the next row.
  This method will return false if the cursor is already past the last entry in the result set.
  http://developer.android.com/reference/android/net/Uri.html
  */
  static OsIndependentParcel* Obtain() { return nullptr; }
  // returns byte[]
  char* Marshall() {}
  char* Unmarshall(char* buffer, int offset, int len) {}
  void Recycle() {}
  void SetDataPosition(int pos) {}
};