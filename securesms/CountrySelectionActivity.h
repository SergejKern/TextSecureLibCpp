#pragma once

/*
Port of CountrySelectionActivity.java from TextSecure-android
*/

// [ ] done
// TFS ID: 707

#include "..\osindependent\OsIndependentActivity.h"
#include "..\osindependent\OsIndependentBundle.h"
#include "..\osindependent\OsIndependentIntent.h"
#include "..\osindependent\OsIndependentString.h"
//import android.support.v4.app.FragmentActivity;

class CountrySelectionActivity : BaseActivity,
    CountrySelectionFragment.CountrySelectedListener
{
public:
  //@Override
  void OnCreate(OsIndependentBundle* bundle)
  {
    super::OnCreate(bundle);
    this->SetContentView(R.layout.country_selection);
  }
  //@Override
  void CountrySelected(OsIndependentString* countryName, int countryCode)
  {
    OsIndependentIntent* result = GetIntent();
    result->PutExtra("country_name", countryName);
    result->PutExtra("country_code", countryCode);

    this->setResult(RESULT_OK, result);
    this->Finish();
  }
};
