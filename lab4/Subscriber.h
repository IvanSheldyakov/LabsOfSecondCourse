//
// Created by Ivan on 11/27/2021.
//

#ifndef BULLSANDCOWS_SUBSCRIBER_H
#define BULLSANDCOWS_SUBSCRIBER_H


#include <memory>
#include "GameStateForViewer.h"

class GameModel;

class Subscriber {

public:
    virtual void update(GameModel *model) = 0;
    virtual ~Subscriber() = default;
};



#endif //BULLSANDCOWS_SUBSCRIBER_H
