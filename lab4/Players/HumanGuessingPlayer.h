//
// Created by Ivan on 11/13/2021.
//

#ifndef BULLSANDCOWS_HUMANGUESSINGPLAYER_H
#define BULLSANDCOWS_HUMANGUESSINGPLAYER_H

#include <string>
#include <memory>
#include "GuessingPlayer.h"
#include "Viewer.h"
#include "Controller.h"
#include "GameModel.h"


class HumanGuessingPlayer : public GuessingPlayer {
    std::shared_ptr<Controller> controller;
    GameModel* model;

public:
    HumanGuessingPlayer(std::shared_ptr<Controller>& controller) {
        this->controller = controller;
    }
    void update(GameModel *model) override;
    std::string makeGuess() override;

};


#endif //BULLSANDCOWS_HUMANGUESSINGPLAYER_H
