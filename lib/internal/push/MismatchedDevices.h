#pragma once
/*
Port of class MismatchedDevices from TextSecure-android
*/

// [x] done
// TFS ID: 341

//import com.fasterxml.jackson.annotation.JsonProperty;

#include "..\..\..\owntemplates\List.h"

class MismatchedDevices
{
private:
  //@JsonProperty
  List<int>* missingDevices;
  //@JsonProperty
  List<int>* extraDevices;

public:
  List<int>* GetMissingDevices() { return this->missingDevices; }
  List<int>* getExtraDevices() { return this->extraDevices; }
};
