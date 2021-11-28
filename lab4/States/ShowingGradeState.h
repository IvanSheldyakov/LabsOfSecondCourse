//
// Created by Ivan on 11/28/2021.
//

#ifndef BULLSANDCOWS_SHOWINGGRADESTATE_H
#define BULLSANDCOWS_SHOWINGGRADESTATE_H

#include "GameState.h"
#include <list>
#include <string>
#include "GameFeatures.h"

class ShowingGradeState : public GameState {
    std::string description = "ShowingGradeState";
    GameFeatures gameFeatures;
    BullsCows bullsCows;
public:
    int getLenOfSequence() {
        return gameFeatures.lenOfSequence;
    }
    void setLen(int len) {
        gameFeatures.lenOfSequence = len;
    }
    int getAmountOfPossibleSymbols() {
        return gameFeatures.amountOfPossibleSymbols;
    }
    void setAmountOfPossibleSymbols(int amount) {
        gameFeatures.amountOfPossibleSymbols = amount;
    }
    int getCows() {
        return bullsCows.cows;
    }
    void setCows(int cows) {
        bullsCows.cows = cows;
    }
    int getBulls() {
        return bullsCows.bulls;
    }
    void setBulls(int bulls) {
        bullsCows.bulls = bulls;
    }

    std::string& getDescription() {
        return description;
    }

};

#endif //BULLSANDCOWS_SHOWINGGRADESTATE_H
