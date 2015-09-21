#pragma once

/*
Port of template interface Document<T> from TextSecure-android
*/

// [x] done
// TFS ID: 312

#include "..\..\..\owntemplates\List.h"

template <typename T> class Document
{
public:
  int Size();
  List<T> GetList();
};

