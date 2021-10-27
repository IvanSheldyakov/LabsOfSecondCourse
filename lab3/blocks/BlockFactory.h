//
// Created by Ivan on 10/21/2021.
//

#ifndef WORKFLOW_BLOCKFACTORY_H
#define WORKFLOW_BLOCKFACTORY_H

#include "Worker.h"

class BlockFactory{
public:
    static BlockFactory& Instance();
    Worker* create(const std::string& blockName);
};

#endif //WORKFLOW_BLOCKFACTORY_H
