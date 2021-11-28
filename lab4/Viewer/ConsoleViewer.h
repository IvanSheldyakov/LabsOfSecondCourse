//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_CONSOLEVIEWER_H
#define BULLSANDCOWS_CONSOLEVIEWER_H

#include <string>
#include "Viewer.h"
#include "Subscriber.h"

class ConsoleViewer : public Viewer {
public:
    void show(const std::string& output) override;
    void update(GameModel *model) override;
};


#endif //BULLSANDCOWS_CONSOLEVIEWER_H
