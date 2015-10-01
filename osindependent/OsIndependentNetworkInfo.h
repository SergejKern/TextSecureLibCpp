#pragma once
/*
  abstract class OsIndependentCursor to replace android.net.NetworkInfo
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/net/NetworkInfo.java#NetworkInfo
*/

// [ ] done
// TFS ID: 768

#include "OsIndependentParcelable.h"

/*
public class  [More ...] NetworkInfo implements Parcelable {
*/
class OsIndependentNetworkInfo : public OsIndependentParcelable
{
private:
public:
  virtual bool IsConnected() = 0;
};
