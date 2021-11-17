//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_CONTROLLER_H
#define BULLSANDCOWS_CONTROLLER_H

#include <string>

class Controller {
public:
    virtual std::string getInput() = 0;
    virtual ~Controller() = default;
};

#endif //BULLSANDCOWS_CONTROLLER_H
