#pragma once

/*
Port of NetworkFailureList from TextSecure-android
*/

// [x] done
// TFS ID: 316

//import com.fasterxml.jackson.annotation.JsonIgnore;
//import com.fasterxml.jackson.annotation.JsonProperty;
//
//import java.util.LinkedList;
//import java.util.List;

#include "Document.h"
#include "NetworkFailure.h"
#include "..\..\..\owntemplates\List.h"

class NetworkFailureList : Document<NetworkFailure>
{
private:
  // @JsonProperty(value = "l")
  List<NetworkFailure>* failures;

public:
  NetworkFailureList()
  {
    this->failures = new LinkedList<NetworkFailure>();
  }
  NetworkFailureList(List<NetworkFailure>* failures)
  {
    this->failures = failures;
  }
  //@Override
  int Size()
  {
    if (this->failures == nullptr)
      return 0;
    else
      return failures->Size();
  }
  //@Override
  //@JsonIgnore
  List<NetworkFailure>* GetList()
  {
    return this->failures;
  }
};
