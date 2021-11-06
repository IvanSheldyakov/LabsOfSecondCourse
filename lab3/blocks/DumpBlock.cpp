//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <fstream>
#include "DumpBlock.h"

#include "BlockMaker.h"

static BlockMaker<DumpBlock> maker("dump");


std::list<std::string>& DumpBlock::execute(const std::list<std::string> &params, std::list<std::string> &text) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("dumpblock needs only one param given "
    + std::to_string(params.size()));}

    std::string filename = params.back();

    std::ofstream file;
    file.open(filename, std::ios::out);

    for (auto it = text.begin(); it != text.end(); ++it) {
        file << *it << std::endl;
    }
    file.close();
    return text;
}