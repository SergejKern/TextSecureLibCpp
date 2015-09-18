/*
Port of TextSecureGroup.java from libtextsecure-java
*/

#include "TextSecureGroup.h"
TextSecureGroup::~TextSecureGroup()
{
}
TextSecureGroup::TextSecureGroup(char* groupId)
{
  // TODO: rewrite!
  //this(Type::DELIVER, groupId, NULL, NULL, NULL);
}
TextSecureGroup::TextSecureGroup(Type type, char* groupId, char* name, char** members, TextSecureAttachment* avatar)
{
  this->type = type;
  this->groupId = groupId;
  // TODO
  this->name = name;
  // TODO
  this->members = members;
  // TODO
  this->avatar = avatar;
}
char* TextSecureGroup::GetGroupId()
{
  return this->groupId;
}
Type TextSecureGroup::GetType() {
  return this->type;
}
char* TextSecureGroup::GetName() {
  return this->name;
}
char** TextSecureGroup::GetMembers() {
  return this->members;
}
TextSecureAttachment* TextSecureGroup::GetAvatar()
{
  return this->avatar;
}
TextSecureGroup::~TextSecureGroup()
{
}
TextSecureGroup::Builder* TextSecureGroup::NewUpdateBuilder()
{
  return new TextSecureGroup::Builder(Type::UPDATE);
}
TextSecureGroup::Builder* TextSecureGroup::NewBuilder(Type type)
{
  return new TextSecureGroup::Builder(type);
}
TextSecureGroup* TextSecureGroup::Builder::Build()
{
  if (id == NULL)
  {
    // do not throw exceptions in TIZEN
    // throw new IllegalArgumentException("No group ID specified!");
  }

  if (type == Type::UPDATE && name == NULL && members == NULL && avatar == NULL)
  {
    // do not throw exceptions in TIZEN
    //throw new IllegalArgumentException("Group update with no updates!");
  }

  return new TextSecureGroup(type, id, name, members, avatar);
}
