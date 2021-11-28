//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_MENUSTATE_H
#define BULLSANDCOWS_MENUSTATE_H

#include "GameStateForViewer.h"
#include <list>
#include <string>

class MenuState : public GameStateForViewer {
    std::string description = "MenuState";
    std::list<std::string> data;
public:
    std::list<std::string>& getWhatToShow() {
        return data;
    }
    std::string& getDescription() {
        return description;
    }
    void addDataToShow(const std::string &str) {
        this->data.push_back(str);
    }
    void setDataToShow(std::list<std::string>& list) {
        this->data = list;
    }
    void clearData() {
        this->data.clear();
    }
    GameFeatures& getFeatures() = delete;
    void setFeatures(GameFeatures& features) = delete;
};

#endif //BULLSANDCOWS_MENUSTATE_H
