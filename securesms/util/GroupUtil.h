#pragma once
/*
Port of class GroupUtil from TextSecure-java
*/

// [x] done
// TFS ID: 222

#include "..\..\osindependent\OsIndependentContext.h"

class GroupUtil
{
private:
  static const OsIndependentString* ENCODED_GROUP_PREFIX;
public:
  GroupUtil();
  virtual ~GroupUtil();
  static OsIndependentString* GetEncodedId(OsIndependentString* groupId);
  static char* GetDecodedId(OsIndependentString* groupId);
  static bool IsEncodedGroup(OsIndependentString* groupId);
  static OsIndependentString* GetDescription(OsIndependentContext* context, OsIndependentString* encodedGroup);
};

const OsIndependentString* GroupUtil::ENCODED_GROUP_PREFIX = new OsIndependentString("__textsecure_group__!");
