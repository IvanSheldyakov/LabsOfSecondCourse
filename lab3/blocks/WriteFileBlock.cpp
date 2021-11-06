//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <fstream>
#include "WriteFileBlock.h"
#include "BlockMaker.h"

static BlockMaker<WriteFileBlock> maker("writefile");

std::list<std::string>& WriteFileBlock::execute(const std::list<std::string> &params, std::list<std::string>& text) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("writeblock needs only one param given "
                                                           + std::to_string(params.size()));}
    std::string filename = params.back();
    std::ofstream file;
    try {
        file.open(filename, std::ios::out);
    } catch (std::exception& exception) {
        throw FileDoesNotExistException("file " + filename + "doesnt exist");
    }

    for (auto it = text.begin(); it != text.end(); ++it) {
        file << *it << std::endl;
    }
    file.close();
    return text;
}