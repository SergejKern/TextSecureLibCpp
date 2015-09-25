#pragma once
/*
Port of class PreKeyStatus from TextSecure-android
*/

// [x] done
// TFS ID: 355

//import com.fasterxml.jackson.annotation.JsonProperty;

#include "..\..\..\owntemplates\List.h"

class StaleDevices
{
private:
  //@JsonProperty
  List<int>* staleDevices;
public:
  List<int>* GetStaleDevices() { return this->staleDevices; }
};
