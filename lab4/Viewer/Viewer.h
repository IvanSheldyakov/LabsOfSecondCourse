//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_VIEWER_H
#define BULLSANDCOWS_VIEWER_H

#include "Subscriber.h"

class Viewer : public Subscriber{
public:
    virtual void show(const std::string& output) = 0;
    virtual ~Viewer() = default;
};

#endif //BULLSANDCOWS_VIEWER_H
