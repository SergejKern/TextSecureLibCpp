/*
Port of TextSecureGroup.java from libtextsecure-java
*/

#include "./lib/api/messages/TextSecureGroup.h"

TextSecureGroup::TextSecureGroup(char* groupId)
{
  // TODO: rewrite!
  //this(Type::DELIVER, groupId, nullptr, nullptr, nullptr);
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
TextSecureGroup::Type TextSecureGroup::GetType() {
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
