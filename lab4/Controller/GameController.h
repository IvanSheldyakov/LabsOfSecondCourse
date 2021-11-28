//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_GAMECONTROLLER_H
#define BULLSANDCOWS_GAMECONTROLLER_H


#include <memory>
#include "Viewer.h"
#include "GuessingPlayer.h"
#include "GuessCreator.h"
#include "GameModel.h"
#include "Controller.h"

class GameController {
    std::shared_ptr<Controller> controller;
    std::shared_ptr<GuessCreator> playerCreator;
    std::shared_ptr<GuessingPlayer> guessingPlayer;
    GameModel model;
    GameState* gameStateForPlayer;

public:
    GameController(Viewer* _viewer, Controller* _controller) : controller(_controller){
        model.subscribe(_viewer);
    }
    void updateGameState(GameStateForViewer* state);
    void showMenu();
    bool willWePlay();
    void initialize();
    void showGameFeatures();
    void showGrade();
    std::string tryToGuess();
    std::string createGuess();
    bool isEndOfGame();
    void showTurn(const std::string& str);
    void showEndLine();
    void gradeGuess(const std::string& guess);


private:
    void sendDataToShow(const std::string& str);
    void chooseGuessCreator();
    GuessCreator* createGuessCreator(const std::string &name);
    void chooseGuessingPlayer();
    GuessingPlayer* createGuessingPlayer(const std::string& name);
    void setFeatures();
    void setLength();
    void setAmountOfPossibleSymbols();


};


#endif //BULLSANDCOWS_GAMECONTROLLER_H
