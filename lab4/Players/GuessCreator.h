//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_GUESSCREATOR_H
#define BULLSANDCOWS_GUESSCREATOR_H

#include <string>
#include "GameFeatures.h"

struct BullsCows{
    int bulls = 0;
    int cows = 0;
};

class GuessCreator {
public:
    virtual std::string create(const GameFeatures& features) = 0;
    virtual BullsCows gradeGuess(const std::string& guess) = 0;
    virtual ~GuessCreator() = default;
};

#endif //BULLSANDCOWS_GUESSCREATOR_H
