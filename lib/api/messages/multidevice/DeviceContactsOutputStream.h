#pragma once
/*
Port of class DeviceContactsOutputStream from TextSecure-android
*/

// [x] done
// TFS ID: 276

#include "ChunkedOutputStream.h"
#include "DeviceContact.h"
#include "..\..\..\internal\push\TextSecureProtos.h"

#include "..\..\..\..\osindependent\OsIndependentOutputStream.h"

class DeviceContactsOutputStream : ChunkedOutputStream
{
public:
  DeviceContactsOutputStream(OsIndependentOutputStream* out) : ChunkedOutputStream(out)
  { }
  void Write(DeviceContact* contact) /*throws IOException*/
  {
    WriteContactDetails(contact);
    WriteAvatarImage(contact);
  }
  void Close() /*throws IOException*/
  {
    out->Close();
  }
private:
  void WriteAvatarImage(DeviceContact* contact) /*throws IOException*/
  {
    if (contact->GetAvatar() != nullptr)
    {
      WriteStream(contact->GetAvatar()->GetInputStream());
    }
  }
  void WriteContactDetails(DeviceContact* contact) /*throws IOException*/
  {
    TextSecureProtos::ContactDetails::Builder* contactDetails 
      = TextSecureProtos::ContactDetails::NewBuilder();
    contactDetails->SetNumber(contact->GetNumber());
    if (contact->GetName() != nullptr)
    {
      contactDetails->SetName(contact->GetName());
    }
    if (contact->GetAvatar() != nullptr)
    {
      TextSecureProtos::ContactDetails::Avatar::Builder* avatarBuilder 
        = TextSecureProtos::ContactDetails::Avatar::NewBuilder();
      avatarBuilder->SetContentType(contact->GetAvatar()->GetContentType());
      avatarBuilder->SetLength((int)contact->GetAvatar()->GetLength());
      contactDetails->SetAvatar(avatarBuilder);
    }

    char* serializedContactDetails = contactDetails->Build()->ToByteArray();
    /* TODO */ int len = sizeof(serializedContactDetails);

    WriteVarint32(len);
    this->out->Write(serializedContactDetails, len);
  }
};
