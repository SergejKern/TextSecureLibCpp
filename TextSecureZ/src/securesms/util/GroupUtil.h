#pragma once
/*
Port of class GroupUtil from TextSecure-java
*/
#define ENCODED_GROUP_PREFIX = "__textsecure_group__!"
class GroupUtil
{
private:
public:
  GroupUtil();
  virtual ~GroupUtil();

  static char* GetEncodedId(char* groupId);
};

// TODO
