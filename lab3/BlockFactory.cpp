//
// Created by Ivan on 10/21/2021.
//

#include <stdexcept>
#include "BlockFactory.h"
#include "ReadFileBlock.h"
#include "WriteFileBlock.h"
#include "GrepBlock.h"
#include "SortBlock.h"
#include "ReplaceBlock.h"
#include "DumpBlock.h"
#include "BlockDoesntExistException.h"


BlockFactory& BlockFactory::Instance() {
    static BlockFactory factory;
    return factory;
}

Worker* BlockFactory::create(const std::string &blockName) {
    if (blockName == "readfile") {
        return new ReadFileBlock(blockName);
    } else if (blockName == "writefile") {
        return new WriteFileBlock(blockName);
    } else if (blockName == "grep") {
        return new GrepBlock(blockName);
    } else if (blockName == "sort") {
        return new SortBlock(blockName);
    } else if (blockName == "replace") {
        return new ReplaceBlock(blockName);
    } else if (blockName == "dump") {
        return new DumpBlock(blockName);
    } else {
        throw BlockDoesntExistException(blockName + " doesnt exist");
    }
}



