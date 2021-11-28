//
// Created by Ivan on 11/27/2021.
//

#include "Game.h"

void Game::gameloop() {
    gameController->showMenu();
    if (!gameController->willWePlay()) {return;}
    gameController->initialize();

    std::string code = gameController->createGuess();
    gameController->showGameFeatures();

    int turn = 1;
    while(!gameController->isEndOfGame()) {
        gameController->showTurn(std::to_string(turn));
        std::string guess = gameController->tryToGuess();
        gameController->gradeGuess(guess);
        gameController->showGrade();
        turn++;
    }
    gameController->showEndLine();

}
