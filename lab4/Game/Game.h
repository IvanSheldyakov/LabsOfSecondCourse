//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_GAME_H
#define BULLSANDCOWS_GAME_H

#include <memory>
#include "Controller.h"
#include "Viewer.h"
#include "GuessCreator.h"
#include "GuessingPlayer.h"
#include "GameFeatures.h"
#include "BotCreator.h"
#include "HumanGuessingPlayer.h"
#include "HumanCreator.h"
#include "GuessingBot.h"
#include "InvalidLengthOfGuess.h"
#include "InvalidAmountOfPossibleSymbols.h"
#include "InvalidSymbolsException.h"
#include "InvalidPlayerException.h"



class Game {
    std::shared_ptr<Controller> controller;
    std::shared_ptr<Viewer> viewer;
    std::shared_ptr<GuessCreator> playerCreator;
    std::shared_ptr<GuessingPlayer> guessingPlayer;
    GameFeatures gameFeatures;
    BullsCows bullsCows;

public:
    Game(Controller* controller, Viewer* viewer) {
        std::shared_ptr<Controller> con(controller);
        this->controller = con;
        std::shared_ptr<Viewer> vie(viewer);
        this->viewer = vie;
    }

    void gameLoop();


private:
    void showMenu();
    bool willWePlay();
    void initialize();
    void chooseGuessCreator();
    std::shared_ptr<GuessCreator> createGuessCreator(const std::string& name);
    void chooseGuessingPlayer();
    std::shared_ptr<GuessingPlayer> createGuessingPlayer(const std::string& name);
    void setFeatures();
    void setLength();
    void setAmountOfPossibleSymbols();
    void showGameFeatures();
    void showGrade();
    std::string tryToGuess();
    std::string createGuess();
    void validateGuess(const std::string& guess);
    bool validateLimitOfSymbols(int maxIdxOfSymbols);
    bool validateLenOfSequence(const std::string& guess);
    bool validateRepetitionsOfSymbols(int* maskOfSymbols, int idxOfSymbol);
};


#endif //BULLSANDCOWS_GAME_H
