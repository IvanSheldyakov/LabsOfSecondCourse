//
// Created by Ivan on 11/13/2021.
//

#include "HumanGuessingPlayer.h"


std::string HumanGuessingPlayer::makeGuess() {
    return controller->getInput();
}

void HumanGuessingPlayer::update(GameModel *model) {
    this->model = model;
}



