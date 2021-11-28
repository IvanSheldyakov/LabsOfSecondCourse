//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_SHOWSTATE_H
#define BULLSANDCOWS_SHOWSTATE_H

#include "GameStateForViewer.h"

class ShowState : public GameStateForViewer {
    std::string description = "ShowState";
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

};

#endif //BULLSANDCOWS_SHOWSTATE_H
