//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_CONSOLEVIEWER_H
#define BULLSANDCOWS_CONSOLEVIEWER_H

#include <string>
#include "Viewer.h"

class ConsoleViewer : public Viewer {
public:
    void println(const std::string& output) override;
    void print(const std::string& output) override;
};


#endif //BULLSANDCOWS_CONSOLEVIEWER_H
