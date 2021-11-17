//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_BOTCREATOR_H
#define BULLSANDCOWS_BOTCREATOR_H

#include "GuessCreator.h"
#include "Controller.h"
#include "Viewer.h"
#include "Constants.h"

class BotCreator : public GuessCreator{
    std::string createdGuess;

public:
    std::string create(const GameFeatures& features) override;
    BullsCows gradeGuess(const std::string& guess) override;

private:
    int findFreeSymbol(int* allowedSymbols, int amountOfPossibleSymbols);
    bool checkAndCountBulls(const std::string& guess, BullsCows& bullsCows, int idxOfSupposedBull);
    void countCows(const std::string& guess, BullsCows& bullsCows, int idxOfSupposedCow);
};


#endif //BULLSANDCOWS_BOTCREATOR_H
