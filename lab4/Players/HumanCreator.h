//
// Created by Ivan on 11/14/2021.
//

#ifndef BULLSANDCOWS_HUMANCREATOR_H
#define BULLSANDCOWS_HUMANCREATOR_H

#include <memory>
#include "GuessCreator.h"
#include "Controller.h"
#include "GameModel.h"

class HumanCreator : public GuessCreator {
    std::shared_ptr<Controller> controller;
    GameModel* model;
public:
    HumanCreator(std::shared_ptr<Controller>& controller) {
        this->controller = controller;
    }
    std::string create() override;
    void gradeGuess(const std::string& guess) override;
    void update(GameModel* model) override;

private:
    int gradeBulls();
    int gradeCows();
};


#endif //BULLSANDCOWS_HUMANCREATOR_H
