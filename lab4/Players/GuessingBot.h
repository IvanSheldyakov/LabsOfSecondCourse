//
// Created by Ivan on 11/14/2021.
//

#ifndef BULLSANDCOWS_GUESSINGBOT_H
#define BULLSANDCOWS_GUESSINGBOT_H

#include <string>
#include <map>
#include "GuessingPlayer.h"
#include "Constants.h"
#include "GameModel.h"


class GuessingBot : public GuessingPlayer {
    std::map<std::string, int> allGuesses;
    GameModel* model;
public:
    std::string makeGuess() override;
    void update(GameModel* model) override;

private:
    int findFreeSymbol(int *allowedSymbols, int amountOfPossibleSymbols);
};


#endif //BULLSANDCOWS_GUESSINGBOT_H
