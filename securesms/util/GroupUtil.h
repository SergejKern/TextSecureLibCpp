#pragma once
/*
Port of class GroupUtil from TextSecure-java
*/

// [ ] done
// TFS ID: 222

class GroupUtil
{
private:
  const char* ENCODED_GROUP_PREFIX = "__textsecure_group__!";

public:
  GroupUtil();
  virtual ~GroupUtil();
  static char* GetEncodedId(char* groupId);
  char* GetDecodedId(char* groupId);
  static bool IsEncodedGroup(unsigned char* groupId);
  // TODO OS SPECIFIC static char* GetDescription(Context context, String encodedGroup);
  static char* GetDescription(void* context, char* encodedGroup);
};
