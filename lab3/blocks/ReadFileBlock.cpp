//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <fstream>
#include "ReadFileBlock.h"
#include "BlockMaker.h"

static BlockMaker<ReadFileBlock> maker("readfile");

std::list<std::string>& ReadFileBlock::execute(const std::list<std::string> &params,std::list<std::string> &text) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("readfileblock needs only one param, given "
    + std::to_string(params.size()));}
    std::string filename = params.back();

    std::ifstream file;
    try{
        file.open(filename, std::ios::in);
    } catch (std::exception& exception) {
        throw CantOpenFileException("cant open file, named " + filename);
    }

    while (!file.eof()) {
        std::string line;
        std::getline(file,line);
        text.push_back(line);
    }
    file.close();
    return text;
}