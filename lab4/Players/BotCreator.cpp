//
// Created by Ivan on 11/10/2021.
//

#include "BotCreator.h"
#include <ctime>

//static Constants con;

std::string BotCreator::create(const GameFeatures& features) {
    int len = features.lenOfSequence;
    int allowedSymbols[ASCII_CODE_OF_SMALL_Z + 1] = {0};
    std::string symbolsToGuess;
    for (int i = 0; i < len; i++) {
        char symbol = (char) findFreeSymbol(allowedSymbols, features.amountOfPossibleSymbols);
        symbolsToGuess.push_back(symbol);
    }
    createdGuess = symbolsToGuess;
    return symbolsToGuess;

}

int BotCreator::findFreeSymbol(int *allowedSymbols, int amountOfPossibleSymbols) {
    srand( time(0) );
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

BullsCows BotCreator::gradeGuess(const std::string &guess) {
    BullsCows bullsCows;
    for (int i = 0; i < guess.length(); i++) {
        if (!checkAndCountBulls(guess,bullsCows,i)) {
            countCows(guess,bullsCows,i);
        }
    }
    return bullsCows;
}

bool BotCreator::checkAndCountBulls(const std::string &guess, BullsCows &bullsCows, int idxOfSupposedBull) {
    if (guess[idxOfSupposedBull] == createdGuess[idxOfSupposedBull]) {
        bullsCows.bulls++;
        return true;
    }
    return false;
}

void BotCreator::countCows(const std::string &guess, BullsCows &bullsCows, int idxOfSupposedCow) {
    for (int j = 0; j < guess.length(); j++) {
        if (guess[idxOfSupposedCow] == createdGuess[j]
            && guess[j] != createdGuess[j]) {
            bullsCows.cows++;
        }
    }
}


