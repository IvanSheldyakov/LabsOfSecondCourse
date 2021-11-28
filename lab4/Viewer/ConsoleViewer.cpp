//
// Created by Ivan on 11/10/2021.
//

#include <iostream>
#include "ConsoleViewer.h"
#include "GameModel.h"


void ConsoleViewer::show(const std::string &output) {
    std::cout << output;
}

void ConsoleViewer::update(GameModel *model) {
    std::shared_ptr<GameStateForViewer> state = model->getGameStateForViewer();
    std::list<std::string> data = state->getWhatToShow();
    if (data.empty()) {return;}
    for(auto it = data.begin(); it != data.end(); ++it) {
        show(*it);
    }
}
