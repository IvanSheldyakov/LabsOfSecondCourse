//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include "GrepBlock.h"

#include "BlockMaker.h"

static BlockMaker<GrepBlock> maker("grep");

std::list<std::string>& GrepBlock::execute(const std::list<std::string> &params, std::list<std::string>& text) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("grepblock needs only one param, given "
                                                           + std::to_string(params.size()));}
    std::string word = params.front();

    std::list<std::string> newText;
    for (auto it = text.begin(); it != text.end(); ++it) {
        std::string str = *it;
        size_t pos = str.find(word);
        if (pos != std::string::npos) {
            newText.push_back(str);
        }
    }
    text = newText;
    return text;
}