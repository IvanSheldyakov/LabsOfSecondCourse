//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_GAME_H
#define BULLSANDCOWS_GAME_H

#include "GameController.h"

class Game {
    std::shared_ptr<GameController> gameController;
public:
    Game(Viewer* viewer, Controller* controller) {
        std::shared_ptr<GameController> _gameController(new GameController(viewer,controller));
        this->gameController = _gameController;
    }
    void gameloop();

};


#endif //BULLSANDCOWS_GAME_H
