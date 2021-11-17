//
// Created by Ivan on 11/13/2021.
//

#ifndef BULLSANDCOWS_GUESSINGPLAYER_H
#define BULLSANDCOWS_GUESSINGPLAYER_H

#include "GameFeatures.h"

class GuessingPlayer {
public:
    virtual std::string makeGuess(const GameFeatures& features) = 0;
    virtual ~GuessingPlayer() = default;
};

#endif //BULLSANDCOWS_GUESSINGPLAYER_H
