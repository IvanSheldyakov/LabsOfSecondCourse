//
// Created by Ivan on 11/10/2021.
//

#include <iostream>
#include "ConsoleViewer.h"

void ConsoleViewer::println(const std::string &output) {
    std::cout << output << std::endl;
}

void ConsoleViewer::print(const std::string &output) {
    std::cout << output;
}