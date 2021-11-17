//
// Created by Ivan on 11/10/2021.
//

#include <iostream>
#include "ConsoleController.h"


std::string ConsoleController::getInput() {
    std::string input;
    std::getline(std::cin,input);
    return input;
}