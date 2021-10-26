//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <fstream>
#include "ReadFileBlock.h"
#include "UtilityClass.h"


void ReadFileBlock::takeArguments(const std::list<std::string> &params) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("readfileblock needs only one param, given "
    + std::to_string(params.size()));}
    filename = params.back();
    if (!UtilityClass::isExist(filename)) {throw FileDoesNotExistException("file " +  filename + " doesnt exist");}
}

std::list<std::string>& ReadFileBlock::execute(const std::list<std::string> &params,std::list<std::string> &text) {
    try {
        takeArguments(params);
    } catch(FileDoesNotExistException& exception) {
        throw exception;
    } catch(IncorrectAmountOfParams& exception) {
        throw exception;
    }

    std::ifstream file;
    file.open(filename, std::ios::in);


    while (!file.eof()) {
        std::string line;
        std::getline(file,line);
        text.push_back(line);
    }
    file.close();
    return text;
}