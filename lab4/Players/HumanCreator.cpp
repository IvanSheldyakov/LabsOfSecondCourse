//
// Created by Ivan on 11/14/2021.
//

#include "HumanCreator.h"
#include "ChangingBullsAndCowsState.h"
#include "ShowState.h"

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

std::string HumanCreator::create() {
    return controller->getInput();
}

void HumanCreator::gradeGuess(const std::string &guess) {
    std::shared_ptr<GameState> state(new ChangingBullsAndCowsState);
    state->setBulls(gradeBulls());
    state->setCows(gradeCows());
    model->updateGameState(state);

}

int HumanCreator::gradeBulls() {
    std::shared_ptr<GameStateForViewer> state(new ShowState);
    state->addDataToShow("Enter how many bulls in guess:");
    model->updateGameState(state);
    while(true) {
        std::string countBulls = controller->getInput();
        if (isNumber(countBulls)) {
            return std::stoi(countBulls);
        } else {
            state->clearData();
            state->addDataToShow("It should be number, try again:");
            model->updateGameState(state);
        }
    }
}

int HumanCreator::gradeCows() {
    std::shared_ptr<GameStateForViewer> state(new ShowState);
    state->addDataToShow("Enter how many cows in guess:");
    model->updateGameState(state);
    while(true) {
        std::string countCows = controller->getInput();
        if (isNumber(countCows)) {
            return std::stoi(countCows);
        } else {
            state->clearData();
            state->addDataToShow("It should be number, try again:");
            model->updateGameState(state);
        }
    }
}

void HumanCreator::update(GameModel *model) {
    this->model = model;
}
