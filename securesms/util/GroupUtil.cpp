#include "GroupUtil.h"
#include "Hex.h"
#include "..\R.h"
#include "Base64.h"
#include "..\..\owntemplates\List.h"
#include "..\..\lib\internal\push\TextSecureProtos.h"
#include "Util.h"
#include "..\..\javastuff\InvalidProtocolBufferException.h"
#include "..\..\osindependent\OsIndependentStringBuilder.h"

GroupUtil::~GroupUtil()
{
}
GroupUtil::GroupUtil()
{
}
OsIndependentString* GroupUtil::GetEncodedId(OsIndependentString* groupId)
{
  return ENCODED_GROUP_PREFIX + Hex::ToStringCondensed(groupId);
}
/*byte[]*/ char* GroupUtil::GetDecodedId(OsIndependentString* groupId)
{
  if (!IsEncodedGroup(groupId))
  {
    throw new IOException(new OsIndependentString("Invalid encoding"));
  }
  return Hex::FromStringCondensed(groupId->Split("!", 2)[1]);
}
bool GroupUtil::IsEncodedGroup(OsIndependentString* groupId)
{
  return groupId->StartsWith(ENCODED_GROUP_PREFIX);
}
OsIndependentString* GroupUtil::GetDescription(OsIndependentContext* context, OsIndependentString* encodedGroup)
{
  if (encodedGroup == nullptr)
  {
    return context->GetString(R::String::GroupUtil_group_updated);
  }
  try {
    OsIndependentStringBuilder* description = new OsIndependentStringBuilder();
    TextSecureProtos::GroupContext* groupContext = TextSecureProtos::GroupContext::ParseFrom(Base64::Decode(encodedGroup));
    List<OsIndependentString*>* members = groupContext->GetMembersList();
    OsIndependentString* title = groupContext->GetName();

    if (!members->IsEmpty())
    {
      description->Append(context->GetString(R::String::GroupUtil_joined_the_group, Util::Join(members, ", ")));
    }

    if (title != nullptr && !title->Trim()->IsEmpty())
    {
      if (description->Length() > 0)
        description->Append(new OsIndependentString(" "));
      description->Append(context->GetString(R::String::GroupUtil_title_is_now, title));
    }

    if (description->Length() > 0) {
      return description->ToString();
    }
    else {
      return context->GetString(R::String::GroupUtil_group_updated);
    }
  }
  catch (InvalidProtocolBufferException e)
  {
    //Log.w("GroupUtil", e);
    return context->GetString(R::String::GroupUtil_group_updated);
  }
  catch (IOException e)
  {
    //Log.w("GroupUtil", e);
    return context->GetString(R::String::GroupUtil_group_updated);
  }
};
