//
// Created by Ivan on 11/27/2021.
//

#include "GameModel.h"
#include "ShowState.h"
#include "InvalidSymbolsException.h"
#include "InvalidAmountOfPossibleSymbols.h"
#include "InvalidLengthOfGuess.h"

bool GameModel::subscribe(Subscriber *sub) {
    try {
        subscribers.push_back(sub);
    } catch (std::exception& exp) {
        return false;
    }
    return true;
}

bool GameModel::unsubscribe(Subscriber *sub) {
    for (int i = 0; i < subscribers.size(); i++) {
        if (subscribers[i] == sub) {
            subscribers.erase(subscribers.begin() + i);
            return true;
        }
    }
    return false;
}

void GameModel::notifyAllSubscribers() {
    for (int i = 0; i < subscribers.size(); i++) {
        subscribers[i]->update(this);
    }
}

void GameModel::updateGameState(std::shared_ptr<GameStateForViewer> &state) {
    this->gameStateForViewer = state;
    notifyAllSubscribers();
}

void GameModel::updateGameState(std::shared_ptr<GameState> &state) {
    if (state->getDescription() == "ChangingFeaturesState") {
        gameFeatures.amountOfPossibleSymbols = state->getAmountOfPossibleSymbols();
        gameFeatures.lenOfSequence = state->getLenOfSequence();
    } else if (state->getDescription() == "ShowingGameFeaturesState") {
        showGameFeatures();
    } else if (state->getDescription() == "ShowingGradeState") {
        showGrade();
    } else if (state->getDescription() == "ChangingBullsAndCowsState") {
        bullsCows.cows = state->getCows();
        bullsCows.bulls = state->getBulls();
    }
    this->gameState = state;
    std::shared_ptr<GameStateForViewer> _gameStateForViewer(new ShowState);
    this->gameStateForViewer = _gameStateForViewer;
    notifyAllSubscribers();
}

const GameFeatures &GameModel::getGameFeatures() const {
    return gameFeatures;
}


const std::shared_ptr<GameStateForViewer> &GameModel::getGameStateForViewer() const {
    return gameStateForViewer;
}

const BullsCows &GameModel::getBullsCows() const {
    return bullsCows;
}

const std::shared_ptr<GameState> &GameModel::getGameStateForPlayer() const {
    return gameState;
}

void GameModel::showGameFeatures() {
    std::string asterisks;
    std::string amountOfSymbols;
    for (int i = 0; i < gameFeatures.lenOfSequence; i++) {
        asterisks.push_back('*');
    }
    if (gameFeatures.amountOfPossibleSymbols > 10) {
        char letter = (char)(97 + 25 - (36 - gameFeatures.amountOfPossibleSymbols));
        amountOfSymbols = "(0-9, a-";
        amountOfSymbols.push_back(letter);
        amountOfSymbols.push_back(')');
    } else {
        amountOfSymbols = "(0 - " + std::to_string(gameFeatures.amountOfPossibleSymbols-1) + ")";

    }
    sendDataToShow("The secret is prepared: " + asterisks + " " + amountOfSymbols + "\n");
}

void GameModel::sendDataToShow(const std::string &str) {
    std::shared_ptr<GameStateForViewer> state(new ShowState);
    state->addDataToShow(str);
    this->updateGameState(state);
}

void GameModel::showGrade() {
    int countCows = bullsCows.cows;
    int countBulls  = bullsCows.bulls;
    sendDataToShow("Grade: \n");
    std::string cowOrCows = (countCows == 1) ? "cow" : "cows";
    std::string bullOrBulls = (countBulls == 1) ? "bull" : "bulls";
    if (countCows == 0 && countBulls == 0) {
        sendDataToShow("None\n");
    } else if (countBulls == 0) {
        sendDataToShow(std::to_string(countCows) + " " + cowOrCows + "\n");
    } else if (countCows == 0) {
        sendDataToShow(std::to_string(countBulls) + " " + bullOrBulls + "\n");
    } else {
        sendDataToShow(std::to_string(countBulls) + " " + bullOrBulls
                        + " and " + std::to_string(countCows) + " " + cowOrCows + "\n");

    }
}

bool GameModel::isEndOfGame() {
    return (bullsCows.bulls == gameFeatures.lenOfSequence);
}

void GameModel::validateGuess(const std::string &guess) {
    if (!validateLenOfSequence(guess)) {
        throw InvalidLengthOfGuess("Incorrect length of guess, must be "
                                   +  std::to_string(gameFeatures.lenOfSequence));
    }

    int mask[123] = {0};
    int maxIdx = 0;
    for (int i = 0; i < guess.size(); i++) {
        if (!std::isalnum(guess[i])) {
            throw InvalidSymbolsException("in guess should be letters and digits");
        }
        int idxOfSymbol = (int) guess[i];
        maxIdx = (maxIdx < idxOfSymbol) ? idxOfSymbol : maxIdx;

        if (!validateRepetitionsOfSymbols(mask, idxOfSymbol)) {
            throw InvalidSymbolsException("there are repetitions of symbols");
        }
    }

    if (!validateLimitOfSymbols(maxIdx)) {
        throw InvalidAmountOfPossibleSymbols("there are symbols higher then edge");
    }
}

bool GameModel::validateLimitOfSymbols(int maxIdxOfSymbols) {
    if (gameFeatures.amountOfPossibleSymbols > 10) {
        int upperEdge = 97 + 25 - (36 - gameFeatures.amountOfPossibleSymbols);
        if (upperEdge < maxIdxOfSymbols) {
            return false;
        }
    } else {
        if (maxIdxOfSymbols > 48 + (gameFeatures.amountOfPossibleSymbols - 1)) {
            return false;
        }
    }
    return true;
}

bool GameModel::validateLenOfSequence(const std::string &guess) {
    return (guess.size() == gameFeatures.lenOfSequence);
}

bool GameModel::validateRepetitionsOfSymbols(int *maskOfSymbols, int idxOfSymbol) {
    if (maskOfSymbols[idxOfSymbol] == 1) {
        return false;
    }
    maskOfSymbols[idxOfSymbol]++;
    return true;
}


