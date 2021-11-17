//
// Created by Ivan on 11/13/2021.
//

#include "HumanGuessingPlayer.h"

std::string HumanGuessingPlayer::makeGuess(const GameFeatures &features) {
    return controller->getInput();
}



