//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <regex>
#include "ReplaceBlock.h"

void ReplaceBlock::takeArguments(const std::list<std::string> &params) {
    if (params.size() != 2) {throw IncorrectAmountOfParams("replaceblock needs only two params, given "
    + std::to_string(params.size()));}
    target = params.front();
    replacement = params.back();
}

std::list<std::string>& ReplaceBlock::execute(const std::list<std::string> &params,std::list<std::string>& text) {
    try {
        takeArguments(params);
    } catch (IncorrectAmountOfParams& exception) {
        throw exception;
    }
    std::list<std::string> newText;
    for (auto it = text.begin(); it != text.end(); ++it) {
        newText.push_back(std::regex_replace(*it, std::regex(target), replacement));
    }
    text = newText;
    return text;
}