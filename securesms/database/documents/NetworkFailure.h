#pragma once

/*
Port of NetworkFailureList from TextSecure-android
*/

// [x] done
// TFS ID: 315

class NetworkFailure
{
public:
  virtual ~NetworkFailure();
private:
  //@JsonProperty(value = "r")
  long recipientId;

public:
  NetworkFailure(long recipientId);
  NetworkFailure();
  long GetRecipientId();
  ////@Override
  //bool equals(void* other);
  ////@Override
  //int hashCode();
};
