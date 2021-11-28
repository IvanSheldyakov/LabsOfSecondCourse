//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_GAMEMODEL_H
#define BULLSANDCOWS_GAMEMODEL_H


#include "GameFeatures.h"
#include "GuessCreator.h"
#include <vector>
#include <memory>
#include "GameStateForViewer.h"
#include "Subscriber.h"
#include "GameState.h"


class GameModel {
    std::shared_ptr<GameStateForViewer> gameStateForViewer;
    std::shared_ptr<GameState> gameState;
    GameFeatures gameFeatures;
    BullsCows bullsCows;
    std::vector <Subscriber*> subscribers;

public:
    bool subscribe(Subscriber *sub);
    bool unsubscribe(Subscriber *sub);
    void updateGameState(std::shared_ptr<GameStateForViewer>& state);
    void updateGameState(std::shared_ptr<GameState>& state);

    bool isEndOfGame();

    const std::shared_ptr<GameStateForViewer> &getGameStateForViewer() const;
    const std::shared_ptr<GameState> &getGameStateForPlayer() const;

    const GameFeatures &getGameFeatures() const;
    const BullsCows &getBullsCows() const;
    void validateGuess(const std::string& guess);


private:
    void notifyAllSubscribers();
    void showGameFeatures();
    void showGrade();
    void sendDataToShow(const std::string& str);
    bool validateLimitOfSymbols(int maxIdxOfSymbols);
    bool validateLenOfSequence(const std::string& guess);
    bool validateRepetitionsOfSymbols(int* maskOfSymbols, int idxOfSymbol);


};


#endif //BULLSANDCOWS_GAMEMODEL_H
