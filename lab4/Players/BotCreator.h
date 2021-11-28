//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_BOTCREATOR_H
#define BULLSANDCOWS_BOTCREATOR_H

#include "GuessCreator.h"
#include "Controller.h"
#include "Viewer.h"
#include "Constants.h"
#include "GameModel.h"

class BotCreator : public GuessCreator {
    std::string createdGuess;
    GameModel* model;

public:
    std::string create() override;
    void gradeGuess(const std::string& guess) override;
    void update(GameModel* model) override;

private:
    int findFreeSymbol(int* allowedSymbols, int amountOfPossibleSymbols);
    bool checkAndCountBulls(const std::string& guess, int* bulls, int idxOfSupposedBull);
    void countCows(const std::string& guess, int* cows, int idxOfSupposedCow);
};


#endif //BULLSANDCOWS_BOTCREATOR_H
