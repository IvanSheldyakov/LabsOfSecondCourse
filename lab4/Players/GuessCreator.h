//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_GUESSCREATOR_H
#define BULLSANDCOWS_GUESSCREATOR_H

#include <string>
#include "GameFeatures.h"
#include "Subscriber.h"

struct BullsCows{
    int bulls = 0;
    int cows = 0;
};

class GuessCreator : public Subscriber{
public:
    virtual std::string create() = 0;
    virtual void gradeGuess(const std::string& guess) = 0;
    virtual ~GuessCreator() = default;
};

#endif //BULLSANDCOWS_GUESSCREATOR_H
