//
// Created by Ivan on 11/10/2021.
//

#include <algorithm>
#include "Game.h"
#include <ctype.h>

void Game::gameLoop() {
    showMenu();
    if (!willWePlay()) {return;}
    initialize();

    std::string code = createGuess();

    showGameFeatures();
    int turn = 1;
    while(bullsCows.bulls != gameFeatures.lenOfSequence) {
        viewer->println("Turn " + std::to_string(turn));
        std::string guess = tryToGuess();

        if (guess == "stop game") {
            viewer->println("You loose(");
            viewer->println("Guess creator wins!");
            return;
        }

        bullsCows = playerCreator->gradeGuess(guess);
        showGrade();
        turn++;
    }
    viewer->println("Congratulations! You guessed the secret code");

}

void Game::showMenu() {
    viewer->println("\t\t\t\t\tBulls and Cows");
    viewer->println("\n\n");
    viewer->println("Press Y to play");
    viewer->println("Press N to exit");
    viewer->println("\nYour choice:");
}


bool Game::willWePlay() {
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
            viewer->println("Your input is wrong, try again:");
        }
    }
}

void Game::initialize() {
    chooseGuessCreator();
    chooseGuessingPlayer();
    setFeatures();
}


void Game::setFeatures() {
    setLength();
    setAmountOfPossibleSymbols();
}

bool isNumber(const std::string& input) {
    for (int i = 0; i < input.size(); i++) {
        if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

void Game::setLength() {
    viewer->println("Please, enter the secret code's length:");
    while(true) {
        std::string sLen = controller->getInput();

        if (!isNumber(sLen)) {
            viewer->println("Is not number, try again:");
            continue;
        }

        int len = std::stoi(sLen);

        if (len <= 0 || len > 36) {
            viewer->println("Length should be between 1 and 36, try again:");
        } else {
            gameFeatures.lenOfSequence = len;
            return;
        }
    }
}

void Game::setAmountOfPossibleSymbols() {
    viewer->println("Input the number of possible symbols in the code:");
    while(true) {
        std::string sAmount = controller->getInput();

        if (!isNumber(sAmount)) {
            viewer->println("Is not number, try again:");
            continue;
        }

        int amount = std::stoi(sAmount);

        if (amount <= 0 || amount > 36) {
            viewer->println("Length should be between 1 and 36, try again:");
        } else if (amount < gameFeatures.lenOfSequence) {
            viewer->println("Amount of possible symbols should be >= code's length, try again:");
        } else {
            gameFeatures.amountOfPossibleSymbols = amount;
            return;
        }
    }
}

void Game::showGameFeatures() {
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
    viewer->println("The secret is prepared: " + asterisks + " " + amountOfSymbols);
    viewer->println("Enter \"stop game\" to stop game");
}

void Game::showGrade() {
    int countCows = bullsCows.cows;
    int countBulls  = bullsCows.bulls;
    viewer->println("Grade: ");
    std::string cowOrCows = (countCows == 1) ? "cow" : "cows";
    std::string bullOrBulls = (countBulls == 1) ? "bull" : "bulls";
    if (countCows == 0 && countBulls == 0) {
        viewer->println("None");
    } else if (countBulls == 0) {
        viewer->println(std::to_string(countCows) + " " + cowOrCows);
    } else if (countCows == 0) {
        viewer->println(std::to_string(countBulls) + " " + bullOrBulls);
    } else {
        viewer->println(std::to_string(countBulls) + " " + bullOrBulls
                        + " and " + std::to_string(countCows) + " " + cowOrCows);

    }
}

std::string Game::tryToGuess() {
    std::string guess;
    while(true) {
        guess = guessingPlayer->makeGuess(gameFeatures);
        if (guess == "stop game") {return guess;}

        try {
            validateGuess(guess);
            viewer->println(guess);
            return guess;
        } catch (std::exception& exception) {
            viewer->println(exception.what());
            viewer->println("Try again:");
        }
    }
}


void Game::chooseGuessCreator()  {
    viewer->println("Choose who will create guess, bot or human:");
    while(true) {
        std::string creatorName = controller->getInput();
        try {
            playerCreator = createGuessCreator(creatorName);
            return;
        } catch (std::exception& exception) {
            viewer->println("bot or human, try again:");
        }
    }
}

std::shared_ptr<GuessCreator> Game::createGuessCreator(const std::string &name) {
    if (name == "bot") {
        std::shared_ptr<GuessCreator> creator(new BotCreator);
        return creator;
    } if (name == "human") {
        std::shared_ptr<GuessCreator> creator(new HumanCreator(controller, viewer));
        return creator;
    } else {
        throw InvalidPlayerException("there is not such player");
    }

}

void Game::chooseGuessingPlayer() {
    viewer->println("Choose who will try to guess, bot or human:");
    while(true) {
        std::string creatorName = controller->getInput();
        try {
            guessingPlayer = createGuessingPlayer(creatorName);
            return;
        } catch (std::exception& exception){
            viewer->println("bot or human, try again:");
        }
    }
}

std::shared_ptr<GuessingPlayer> Game::createGuessingPlayer(const std::string &name) {
    if (name == "bot") {
        std::shared_ptr<GuessingPlayer> creator(new GuessingBot);
        return creator;
    } if (name == "human") {
        std::shared_ptr<GuessingPlayer> creator(new HumanGuessingPlayer(controller));
        return creator;
    } else {
        throw std::exception();
    }
}

std::string Game::createGuess() {
    std::string guess;
    while(true) {
        viewer->println("Create code:");
        guess = playerCreator->create(gameFeatures);
        try {
            validateGuess(guess);
            viewer->print("\n\n\n\n\n");
            return guess;
        } catch (std::exception& exception) {
            viewer->println(exception.what());
            viewer->println("Try again:");
        }
    }
}



void Game::validateGuess(const std::string &guess) {
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

bool Game::validateLimitOfSymbols(int maxIdxOfSymbols) {
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

bool Game::validateLenOfSequence(const std::string &guess) {
    return (guess.size() == gameFeatures.lenOfSequence);
}

bool Game::validateRepetitionsOfSymbols(int *maskOfSymbols, int idxOfSymbol) {
    if (maskOfSymbols[idxOfSymbol] == 1) {
        return false;
    }
    maskOfSymbols[idxOfSymbol]++;
    return true;
}










