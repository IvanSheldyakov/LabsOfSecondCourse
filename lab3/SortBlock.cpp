//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include "SortBlock.h"

void SortBlock::takeArguments(const std::list<std::string> &params) {
    if (!params.empty()) {
        throw IncorrectAmountOfParams("sortblock doesnt need params, given " + std::to_string(params.size()));
    }
}

std::list<std::string>& SortBlock::execute(const std::list<std::string> &params, std::list<std::string>& text) {
    try {
        takeArguments(params);
    } catch (IncorrectAmountOfParams& exception) {
        throw exception;
    }

    text.sort();
    return text;
}

