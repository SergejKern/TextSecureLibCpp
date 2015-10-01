#pragma once

/*
Port of CountrySelectionActivity.java from TextSecure-android
*/

// [x] done
// TFS ID: 707

#include "..\osindependent\OsIndependentActivity.h"
#include "..\osindependent\OsIndependentBundle.h"
#include "..\osindependent\OsIndependentIntent.h"
#include "..\osindependent\OsIndependentString.h"
#include "BaseActivity.h"
#include "CountrySelectionFragment.h"
#include "R.h"
//import android.support.v4.app.FragmentActivity;

class CountrySelectionActivity : public BaseActivity, public CountrySelectionFragment::CountrySelectedListener
{
public:
  //@Override
  void OnCreate(OsIndependentBundle* bundle)
  {
    super::OnCreate(bundle);
    this->SetContentView(R::Layout::country_selection);
  }
  //@Override
  void CountrySelected(OsIndependentString* countryName, int countryCode)
  {
    OsIndependentIntent* result = GetIntent();
    result->PutExtra(new OsIndependentString("country_name"), countryName);
    result->PutExtra(new OsIndependentString("country_code"), countryCode);

    this->SetResult(RESULT_OK, result);
    this->Finish();
  }
};
