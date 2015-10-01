#pragma once
/*
  abstract class OsIndependentCursor to replace  android.os.Bundle
  http://grepcode.com/file/repository.grepcode.com/java/ext/com.google.android/android/5.1.1_r1/android/os/Bundle.java#Bundle
*/

// [ ] done
// TFS ID: 684

#include "OsIndependentParcelable.h"

// public final class Bundle extends BaseBundle implements Cloneable, Parcelable{
class OsIndependentBundle : public OsIndependentParcelable
{
private:
public:
};
