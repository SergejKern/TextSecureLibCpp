#include "DeviceGroupsOutputStream.h"

DeviceGroupsOutputStream::DeviceGroupsOutputStream(OsIndependentOutputStream* out)
  : ChunkedOutputStream(out)
{
}
void DeviceGroupsOutputStream::Write(DeviceGroup* group) /*throws IOException*/
{
  WriteGroupDetails(group);
  WriteAvatarImage(group);
}
void DeviceGroupsOutputStream::Close() /*throws IOException*/
{
  out->Close();
}
void DeviceGroupsOutputStream::WriteAvatarImage(DeviceGroup* contact) /*throws IOException*/
{
  if (contact->GetAvatar() != nullptr)
  {
    WriteStream(contact->GetAvatar()->GetInputStream());
  }
}
void DeviceGroupsOutputStream::WriteGroupDetails(DeviceGroup* group) /*throws IOException*/
{
  TextSecureProtos::GroupDetails::Builder* groupDetails = 
    TextSecureProtos::GroupDetails::NewBuilder();
  groupDetails->SetId(group->GetId());

  if (group->GetName() != nullptr)
  {
    groupDetails->SetName(group->GetName());
  }

  if (group->GetAvatar() != nullptr)
  {
    TextSecureProtos::GroupDetails::Avatar::Builder* avatarBuilder = 
      TextSecureProtos::GroupDetails::Avatar::NewBuilder();
    avatarBuilder->SetContentType(group->GetAvatar()->GetContentType());
    avatarBuilder->SetLength((int)group->GetAvatar()->GetLength());
    groupDetails->SetAvatar(avatarBuilder);
  }

  groupDetails->AddAllMembers(group->GetMembers());

  std::vector<unsigned char>* serializedContactDetails = groupDetails->Build()->ToByteArray();

  WriteVarint32(serializedContactDetails->size());
  out->Write(serializedContactDetails);
}
