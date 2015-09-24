#pragma once
/*
Port of class ChunkedOutputStream from TextSecure-android
*/

// [x] done
// TFS ID: 273

//import java.io.IOException;
#include "..\..\..\..\osindependent\OsIndependentInputStream.h"
#include "..\..\..\..\osindependent\OsIndependentOutputStream.h"

class ChunkedOutputStream
{
protected:
  OsIndependentOutputStream* out;

public:
  ChunkedOutputStream(OsIndependentOutputStream* out)
  {
    this->out = out;
  }
protected:
  void WriteVarint32(unsigned int value) /*throws IOException */
  {
    while (true)
    {
      if ((value & ~0x7F) == 0)
      {
        out->Write(value);
        return;
      }
      else
      {
        out->Write((value & 0x7F) | 0x80);
        // unsigned right shift value >>>= 7;
        value >>= 7; // Just do right shift on unsigned int // TODO need debug
      }
    }
  }
protected:
  void WriteStream(OsIndependentInputStream* in) /*throws IOException*/
  {
    char* buffer = new char[4096];
    int read;
    while ((read = in->Read(buffer, 4096)) != -1)
    {
      out->Write(buffer, 0, read);
    }
    in->Close();
  }
};
