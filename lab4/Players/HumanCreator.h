//
// Created by Ivan on 11/14/2021.
//

#ifndef BULLSANDCOWS_HUMANCREATOR_H
#define BULLSANDCOWS_HUMANCREATOR_H

#include <memory>
#include "GuessCreator.h"
#include "Controller.h"
#include "Viewer.h"

class HumanCreator : public GuessCreator{
    std::shared_ptr<Controller> controller;
    std::shared_ptr<Viewer> viewer;
public:
    HumanCreator(std::shared_ptr<Controller>& controller, std::shared_ptr<Viewer>& viewer) {
        this->controller = controller;
        this->viewer = viewer;
    }
    std::string create(const GameFeatures& features) override;
    BullsCows gradeGuess(const std::string& guess) override;

private:
    void gradeBulls(BullsCows& bullsCows);
    void gradeCows(BullsCows& bullsCows);
};


#endif //BULLSANDCOWS_HUMANCREATOR_H
