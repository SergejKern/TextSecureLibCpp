#pragma once

/*
Port of PushCharacterCalculator.java from TextSecure-android
*/

// [x] done
// TFS ID: 233

/**
 * Copyright (C) 2015 Whisper Systems
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "CharacterCalculator.h"

class PushCharacterCalculator : CharacterCalculator
{
private:
  static const int MAX_SIZE = 2000;
public:
  //@Override
  CharacterState* CalculateCharacters(int charactersSpent)
  {
    return new CharacterState(1, MAX_SIZE - charactersSpent, MAX_SIZE);
  }
};
