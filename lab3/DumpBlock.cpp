//
// Created by Ivan on 10/20/2021.
//

#include <stdexcept>
#include <fstream>
#include "DumpBlock.h"
#include "UtilityClass.h"

void DumpBlock::takeArguments(const std::list<std::string> &params) {
    if (params.size() != 1) {throw IncorrectAmountOfParams("dumpblock needs only one param given "
    + std::to_string(params.size()));}
    filename = params.back();
    if (!UtilityClass::isExist(filename)) {throw FileDoesNotExistException("file " +  filename + " doesnt exist");}
}

std::list<std::string>& DumpBlock::execute(const std::list<std::string> &params, std::list<std::string> &text) {
    try {
        takeArguments(params);
    } catch(FileDoesNotExistException& exception) {
        throw exception;
    } catch(IncorrectAmountOfParams& exception) {
        throw exception;
    }

    std::ofstream file;
    file.open(filename, std::ios::out);

    for (auto it = text.begin(); it != text.end(); ++it) {
        file << *it << std::endl;
    }
    file.close();
    return text;
}