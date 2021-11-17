//
// Created by Ivan on 11/14/2021.
//

#include "HumanCreator.h"

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

std::string HumanCreator::create(const GameFeatures &features) {
    return controller->getInput();
}

BullsCows HumanCreator::gradeGuess(const std::string &guess) {
    BullsCows bullsCows;
    gradeBulls(bullsCows);
    gradeCows(bullsCows);
    return bullsCows;
}

void HumanCreator::gradeBulls(BullsCows &bullsCows) {
    viewer->println("Enter how many bulls in guess:");
    while(true) {
        std::string countBulls = controller->getInput();
        if (isNumber(countBulls)) {
            bullsCows.bulls = std::stoi(countBulls);
            break;
        } else {
            viewer->println("It should be number, try again:");
        }
    }
}

void HumanCreator::gradeCows(BullsCows &bullsCows) {
    viewer->println("Enter how many cows in guess:");
    while(true) {
        std::string countCows = controller->getInput();
        if (isNumber(countCows)) {
            bullsCows.cows= std::stoi(countCows);
            break;
        } else {
            viewer->println("It should be number, try again:");
        }
    }
}
