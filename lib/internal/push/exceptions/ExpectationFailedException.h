#pragma once
/*
Port of class ExpectationFailedException from TextSecure-android
*/

// [x] done
// TFS ID: 290

#include "NonSuccessfulResponseCodeException.h"

class ExpectationFailedException : public NonSuccessfulResponseCodeException
{
};
