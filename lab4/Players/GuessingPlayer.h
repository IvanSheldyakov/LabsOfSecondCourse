//
// Created by Ivan on 11/13/2021.
//

#ifndef BULLSANDCOWS_GUESSINGPLAYER_H
#define BULLSANDCOWS_GUESSINGPLAYER_H

#include "GameFeatures.h"
#include "Subscriber.h"

class GuessingPlayer : public Subscriber {
public:
    virtual std::string makeGuess() = 0;
    virtual ~GuessingPlayer() = default;
};

#endif //BULLSANDCOWS_GUESSINGPLAYER_H
