#pragma once

/*
Port of TextSecureGroup.java from libtextsecure-java
*/

// [x] done
// TFS ID: 271


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

#if (_MSC_VER > 1500)
#define NULL nullptr
#elif (__GNUC__ > 3)
#define NULL __null
#endif


#include "TextSecureAttachment.h"
#include "..\..\..\owntemplates\List.h"

enum Type {
  UNKNOWN,
  UPDATE,
  DELIVER,
  QUIT
};

class TextSecureGroup
{
public:
  class Builder
  {
  private:
    Type type;
    char* id;
    unsigned char* name;
    List<unsigned char*>* members;
    TextSecureAttachment* avatar;
  public:
    // constructor
    Builder(Type type) { this->type = type; }
    Builder* WithId(char* id)
    {
      this->id = id;
      return this;
    }
    Builder* WithName(unsigned char* name)
    {
      this->name = name;
      return this;
    }
    Builder* WithMembers(List<unsigned char*>* members)
    {
      this->members = members;
      return this;
    }
    Builder* WithAvatar(TextSecureAttachment* avatar) {
      this->avatar = avatar;
      return this;
    }
    TextSecureGroup* Build();
  };
  // constructors
  TextSecureGroup(char* groupId);
  TextSecureGroup(Type type, char* groupId, unsigned char* name, List<unsigned char*>* members, TextSecureAttachment* avatar);
  // destructor
  virtual ~TextSecureGroup();
  // methods
  char* GetGroupId();
  Type GetType();
  unsigned char* GetName();
  List<unsigned char*>* GetMembers();
  TextSecureAttachment* GetAvatar();
  static Builder* NewUpdateBuilder();
  static Builder* NewBuilder(Type type);

private:
  char* groupId;
  Type type;
  //Optional<String> name;
  unsigned char* name;
  //Optional<List<String>> members;
  List<unsigned char*>* members;
  //Optional<TextSecureAttachment> avatar;
  TextSecureAttachment* avatar;
};
