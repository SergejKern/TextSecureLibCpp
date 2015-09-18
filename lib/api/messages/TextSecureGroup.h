#pragma once

/*
Port of TextSecureGroup.java from libtextsecure-java
*/

/**
* Copyright (C) 2014 Open Whisper Systems
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//import org.whispersystems.libaxolotl.util.guava.Optional;

/**
* Group information to include in TextSecureMessages destined to groups.
*
* This class represents a "context" that is included with textsecure messages
* to make them group messages.  There are three types of context:
*
* 1) Update -- Sent when either creating a group, or updating the properties
*    of a group (such as the avatar icon, membership list, or title).
* 2) Deliver -- Sent when a message is to be delivered to an existing group.
* 3) Quit -- Sent when the sender wishes to leave an existing group.
*
* @author Moxie Marlinspike
*/

#include "TextSecureAttachment.h"

class TextSecureGroup
{
public:
  enum Type {
    UNKNOWN,
    UPDATE,
    DELIVER,
    QUIT
  };
  static class Builder
  {
  private:
    Type type;
    char* id;
    char* name;
    char** members;
    TextSecureAttachment* avatar;
  public:
    // constructor
    Builder(Type type) {
      this->type = type;
    }
    Builder* WithId(char* id)
    {
      this->id = id;
      return this;
    }
    Builder* WithName(char* name)
    {
      this->name = name;
      return this;
    }
    Builder* WithMembers(char** members)
    {
      this->members = members;
      return this;
    }
    Builder* WithAvatar(TextSecureAttachment* avatar) {
      this->avatar = avatar;
      return this;
    }
    TextSecureGroup* Build()
    {
      if (id == nullptr)
      {
        // do not throw exceptions in TIZEN
        // throw new IllegalArgumentException("No group ID specified!");
      }

      if (type == Type::UPDATE && name == nullptr && members == nullptr && avatar == nullptr)
      {
        // do not throw exceptions in TIZEN
        //throw new IllegalArgumentException("Group update with no updates!");
      }

      return new TextSecureGroup(type, id, name, members, avatar);
    }
  };
  // constructors
  TextSecureGroup(char* groupId);
  TextSecureGroup(Type type, char* groupId, char* name, char** members, TextSecureAttachment* avatar);
  // destructor
  virtual ~TextSecureGroup();
  // methods
  char* GetGroupId();
  Type GetType();
  char* GetName();
  char** GetMembers();
  TextSecureAttachment* GetAvatar();
  static Builder* NewUpdateBuilder();
  static Builder* NewBuilder(Type type);

private:
  char* groupId;
  Type type;
  //Optional<String> name;
  char* name;
  //Optional<List<String>> members;
  char** members;
  //Optional<TextSecureAttachment> avatar;
  TextSecureAttachment* avatar;
};