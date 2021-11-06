//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include "SortBlock.h"

#include "BlockMaker.h"

static BlockMaker<SortBlock> maker("sort");

std::list<std::string>& SortBlock::execute(const std::list<std::string> &params, std::list<std::string>& text) {
    if (!params.empty()) {
        throw IncorrectAmountOfParams("sortblock doesnt need params, given " + std::to_string(params.size()));
    }

    text.sort();
    return text;
}

