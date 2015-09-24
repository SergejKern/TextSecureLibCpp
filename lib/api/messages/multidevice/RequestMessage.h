#pragma once
/*
Port of class RequestMessage from TextSecure-android
*/

// [x] done
// TFS ID: 281

#include "..\..\..\internal\push\TextSecureProtos.h"

class RequestMessage
{
private:
  TextSecureProtos::SyncMessage::Request* request;

public:
  RequestMessage(TextSecureProtos::SyncMessage::Request* request)
  {
    this->request = request;
  }
  bool IsContactsRequest()
  {
    return this->request->GetType() == TextSecureProtos::SyncMessage::Request::Type::CONTACTS;
  }
  bool IsGroupsRequest()
  {
    return this->request->GetType() == TextSecureProtos::SyncMessage::Request::Type::GROUPS;
  }
};
