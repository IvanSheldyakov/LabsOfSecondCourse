//
// Created by Ivan on 11/14/2021.
//

#ifndef BULLSANDCOWS_GUESSINGBOT_H
#define BULLSANDCOWS_GUESSINGBOT_H

#include <string>
#include <map>
#include "GuessingPlayer.h"
#include "Constants.h"


class GuessingBot : public GuessingPlayer {
    std::map<std::string, int> allGuesses;
public:
    std::string makeGuess(const GameFeatures& features) override;

private:
    int findFreeSymbol(int *allowedSymbols, int amountOfPossibleSymbols);
};


#endif //BULLSANDCOWS_GUESSINGBOT_H
