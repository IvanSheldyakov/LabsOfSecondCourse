//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_GAMESTATEFORVIEWER_H
#define BULLSANDCOWS_GAMESTATEFORVIEWER_H


#include <list>
#include "GameFeatures.h"

class GameStateForViewer{
public:
    virtual std::list<std::string>& getWhatToShow() = 0;
    virtual void addDataToShow(const std::string &str) = 0;
    virtual void setDataToShow(std::list<std::string>& list) = 0;
    virtual void clearData() = 0;
    virtual std::string& getDescription() = 0;
    virtual ~GameStateForViewer() = default;
};

#endif //BULLSANDCOWS_GAMESTATEFORVIEWER_H
