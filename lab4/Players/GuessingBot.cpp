//
// Created by Ivan on 11/14/2021.
//

#include <ctime>
#include "GuessingBot.h"

std::string GuessingBot::makeGuess() {
    GameFeatures features = model->getGameFeatures();
    int len = features.lenOfSequence;
    while(true) {
        int allowedSymbols[ASCII_CODE_OF_SMALL_Z+1] = {0};
        std::string symbolsToGuess;
        for (int i = 0; i < len; i++) {
            char symbol = (char) findFreeSymbol(allowedSymbols, features.amountOfPossibleSymbols);
            symbolsToGuess.push_back(symbol);
        }
        if (allGuesses[symbolsToGuess] == 0) {
            allGuesses[symbolsToGuess]++;
            return symbolsToGuess;
        }
    }
}

int GuessingBot::findFreeSymbol(int *allowedSymbols, int amountOfPossibleSymbols) {
    srand( time(0) + 1005000);
    int upperEdge;
    if (amountOfPossibleSymbols > 10) {
        upperEdge = ASCII_CODE_OF_SMALL_A +
                    (NUMBER_TO_APPEAR_BETWEEN_A_AND_Z - (MAX_AMOUNT_OF_POSSIBLE_SYMBOLS - amountOfPossibleSymbols));
    } else {
        upperEdge = ASCII_CODE_OF_ZERO +
                    (NUMBER_TO_APPEAR_BETWEEN_ZERO_AND_NINE - (MAX_AMOUNT_OF_POSSIBLE_SYMBOLS - amountOfPossibleSymbols));
    }
    while (true) {
        int randomNumber = (rand() % (upperEdge - ASCII_CODE_OF_ZERO + 1)) + ASCII_CODE_OF_ZERO;
        if (((randomNumber <= ASCII_CODE_OF_NINE) ||
             (randomNumber >= ASCII_CODE_OF_SMALL_A && randomNumber <= upperEdge))
            && allowedSymbols[randomNumber] == 0) {
            allowedSymbols[randomNumber] = 1;
            return randomNumber;
        }
    }
}

void GuessingBot::update(GameModel *model) {
    this->model = model;
}
