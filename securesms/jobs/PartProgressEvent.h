#pragma once
/*
Port of class PartProgressEvent from TextSecure-android
*/

// [x] done
// TFS ID: 535

#include "..\database\PartDatabase.h"

class PartProgressEvent
{
private:
  PartDatabase::PartId* partId;
  long total;
  long progress;
public:
  PartProgressEvent(PartDatabase::PartId* partId, long total, long progress)
  {
    this->partId = partId;
    this->total = total;
    this->progress = progress;
  }
  PartDatabase::PartId* GetPartId() { return this->partId; }
  long GetTotal() { return this->total; }
  long GetProgress() { return this->progress; }
};
