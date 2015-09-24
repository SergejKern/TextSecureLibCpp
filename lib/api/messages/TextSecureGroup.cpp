/*
Port of TextSecureGroup.java from libtextsecure-java
*/

#include "TextSecureGroup.h"
TextSecureGroup::~TextSecureGroup()
{
}
TextSecureGroup::TextSecureGroup(char* groupId)
{
  this->type = Type::DELIVER;
  this->groupId = groupId;
  this->name = nullptr;
  this->members = nullptr;
  this->avatar = nullptr;
}
TextSecureGroup::TextSecureGroup(Type type, char* groupId, unsigned char* name, List<unsigned char*>* members, TextSecureAttachment* avatar)
{
  this->type = type;
  this->groupId = groupId;
  this->name = name;
  this->members = members;
  this->avatar = avatar;
}
char* TextSecureGroup::GetGroupId()
{
  return this->groupId;
}
Type TextSecureGroup::GetType()
{
  return this->type;
}
unsigned char* TextSecureGroup::GetName()
{
  return this->name;
}
List<unsigned char*>* TextSecureGroup::GetMembers()
{
  return this->members;
}
TextSecureAttachment* TextSecureGroup::GetAvatar()
{
  return this->avatar;
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
    // TODO do not throw exceptions in TIZEN
    // throw new IllegalArgumentException("No group ID specified!");
  }

  if (type == Type::UPDATE && name == NULL && members == NULL && avatar == NULL)
  {
    // TODO do not throw exceptions in TIZEN
    //throw new IllegalArgumentException("Group update with no updates!");
  }

  return new TextSecureGroup(type, id, name, members, avatar);
}
