//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_CONSOLECONTROLLER_H
#define BULLSANDCOWS_CONSOLECONTROLLER_H

#include <string>
#include "Controller.h"

class ConsoleController : public Controller {
    std::string getInput() override;
};


#endif //BULLSANDCOWS_CONSOLECONTROLLER_H
