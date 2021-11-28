//
// Created by Ivan on 11/28/2021.
//

#ifndef BULLSANDCOWS_SHOWINGGAMEFEATURESSTATE_H
#define BULLSANDCOWS_SHOWINGGAMEFEATURESSTATE_H

#include "GameState.h"
#include <list>
#include <string>
#include "GameFeatures.h"

class ShowingGameFeaturesState : public GameState {
    std::string description = "ShowingGameFeaturesState";
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
    std::string& getDescription() {
        return description;
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

};

#endif //BULLSANDCOWS_SHOWINGGAMEFEATURESSTATE_H
