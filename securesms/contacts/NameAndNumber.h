#pragma once
/*
Port of class NameAndNumber from TextSecure-android
*/

// [x] done
// TFS ID: 429

#include "..\..\osindependent\OsIndependentString.h"

/**
 * Name and number tuple.
 * 
 * @author Moxie Marlinspike
 *
 */
class NameAndNumber
{
private:
  OsIndependentString* name;
  OsIndependentString* number;
public:
  NameAndNumber(OsIndependentString* name, OsIndependentString* number)
  {
    this->name = name;
    this->number = number;
  }
  NameAndNumber()
  {
    this->name = nullptr;
    this->number = nullptr;
  }
  OsIndependentString* GetName() { return this->name; }
  OsIndependentString* GetNumber() { return this->number; }
};
