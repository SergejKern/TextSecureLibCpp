#pragma once

/*
Port of MmsCharacterCalculator.java from TextSecure-android
*/

// [x] done
// TFS ID: 229

#include "CharacterCalculator.h"

class MmsCharacterCalculator : CharacterCalculator
{
private:
  static const int MAX_SIZE = 5000;

  //@Override
public:
  virtual CharacterState* CalculateCharacters(int charactersSpent)
  {
    return new CharacterState(1, MAX_SIZE - charactersSpent, MAX_SIZE);
  }
};
