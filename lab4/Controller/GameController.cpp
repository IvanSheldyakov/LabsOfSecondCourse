//
// Created by Ivan on 11/27/2021.
//

#include <algorithm>
#include "GameController.h"
#include "MenuState.h"
#include "ShowState.h"
#include "BotCreator.h"
#include "HumanCreator.h"
#include "InvalidPlayerException.h"
#include "GuessingBot.h"
#include "HumanGuessingPlayer.h"
#include "ChangingFeaturesState.h"
#include "ShowingGameFeaturesState.h"
#include "ShowingGradeState.h"

void GameController::updateGameState(GameStateForViewer *state) {
    std::shared_ptr<GameStateForViewer> gameState(state);
    model.updateGameState(gameState);
}

bool GameController::willWePlay() {
    std::string choice;
    while (true) {
        choice = controller->getInput();
        std::transform(choice.begin(), choice.end(), choice.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        if (choice == "y") {
            return true;
        } else if (choice == "n") {
            return false;
        } else {
            sendDataToShow("Your input is wrong, try again:\n");
        }
    }
}

void GameController::showMenu() {
    std::shared_ptr<GameStateForViewer> state(new MenuState);
    state->addDataToShow("\t\t\t\t\tBulls and Cows");
    state->addDataToShow("\n\n");
    state->addDataToShow("Press Y to play");
    state->addDataToShow("Press N to exit");
    state->addDataToShow("\nYour choice:\n");
    model.updateGameState(state);
}

void GameController::initialize() {
    chooseGuessCreator();
    chooseGuessingPlayer();
    setFeatures();
}

void GameController::chooseGuessCreator() {
    sendDataToShow("Choose who will create guess, bot or human:\n");
    while(true) {
        std::string creatorName = controller->getInput();
        try {
            GuessCreator* player = createGuessCreator(creatorName);
            std::shared_ptr<GuessCreator> _player(player);
            playerCreator = _player;
            model.subscribe(player);
            return;
        } catch (std::exception& exception) {
            sendDataToShow("bot or human, try again:\n");
        }
    }
}

GuessCreator* GameController::createGuessCreator(const std::string &name) {
    if (name == "bot") {
        return new BotCreator;
    } if (name == "human") {
        return new HumanCreator(controller);
    } else {
        throw InvalidPlayerException("there is not such player");
    }

}

void GameController::sendDataToShow(const std::string &str) {
    std::shared_ptr<GameStateForViewer> state(new ShowState);
    state->addDataToShow(str);
    model.updateGameState(state);
}

void GameController::chooseGuessingPlayer() {
    sendDataToShow("Choose who will try to guess, bot or human:\n");
    while(true) {
        std::string creatorName = controller->getInput();
        try {
            GuessingPlayer* player = createGuessingPlayer(creatorName);
            std::shared_ptr<GuessingPlayer> _player(player);
            guessingPlayer = _player;
            model.subscribe(player);
            return;
        } catch (std::exception& exception){
            sendDataToShow("bot or human, try again:\n");
        }
    }

}

GuessingPlayer* GameController::createGuessingPlayer(const std::string &name) {
    if (name == "bot") {
        return new GuessingBot;
    } if (name == "human") {
        return new HumanGuessingPlayer(controller);
    } else {
        throw std::exception();
    }
}

void GameController::setFeatures() {
    gameStateForPlayer = new ChangingFeaturesState;
    setLength();
    setAmountOfPossibleSymbols();
    std::shared_ptr<GameState> state(gameStateForPlayer);
    model.updateGameState(state);
}

namespace {
    bool isNumber(const std::string& input) {
        for (int i = 0; i < input.size(); i++) {
            if (!std::isdigit(input[i])) {
                return false;
            }
        }
        return true;
    }
}

void GameController::setLength() {
    sendDataToShow("Please, enter the secret code's length:\n");
    while(true) {
        std::string sLen = controller->getInput();

        if (!isNumber(sLen)) {
            sendDataToShow("Is not number, try again:\n");
            continue;
        }

        int len = std::stoi(sLen);

        if (len <= 0 || len > 36) {
            sendDataToShow("Length should be between 1 and 36, try again:\n");
        } else {
            gameStateForPlayer->setLen(len);
            return;
        }
    }
}

void GameController::setAmountOfPossibleSymbols() {
    sendDataToShow("Input the number of possible symbols in the code:\n");
    while(true) {
        std::string sAmount = controller->getInput();

        if (!isNumber(sAmount)) {
            sendDataToShow("Is not number, try again:\n");
            continue;
        }

        int amount = std::stoi(sAmount);

        if (amount <= 0 || amount > 36) {
            sendDataToShow("Length should be between 1 and 36, try again:\n");
        } else if (amount < gameStateForPlayer->getLenOfSequence()) {
            sendDataToShow("Amount of possible symbols should be >= code's length, try again:\n");
        } else {
            gameStateForPlayer->setAmountOfPossibleSymbols(amount);
            return;
        }
    }
}

void GameController::showGameFeatures() {
    std::shared_ptr<GameState> state(new ShowingGameFeaturesState);
    model.updateGameState(state);
}

void GameController::showGrade() {
    std::shared_ptr<GameState> state(new ShowingGradeState);
    model.updateGameState(state);
}

std::string GameController::tryToGuess() {
    std::string guess;
    while(true) {
        guess = guessingPlayer->makeGuess();

        try {
            model.validateGuess(guess);
            sendDataToShow(guess + "\n");
            return guess;
        } catch (std::exception &exception) {
            sendDataToShow(exception.what());
            sendDataToShow("\nTry again:\n");
        }
    }
}

std::string GameController::createGuess() {
    std::string guess;
    while(true) {
        sendDataToShow("Create code:\n");
        guess = playerCreator->create();
        try {
            model.validateGuess(guess);
            sendDataToShow("\n\n\n\n\n");
            return guess;
        } catch (std::exception& exception) {
            sendDataToShow(exception.what());
            sendDataToShow("\nTry again:\n");
        }
    }
}

bool GameController::isEndOfGame() {
    return model.isEndOfGame();
}

void GameController::showTurn(const std::string &str) {
    sendDataToShow("Turn " + str + "\n");
}

void GameController::showEndLine() {
    sendDataToShow("Congratulations! You guessed the secret code\n");
}

void GameController::gradeGuess(const std::string& guess) {
    playerCreator->gradeGuess(guess);
}





