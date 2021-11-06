//
// Created by Ivan on 10/21/2021.
//

#ifndef WORKFLOW_BLOCKFACTORY_H
#define WORKFLOW_BLOCKFACTORY_H

#include "Worker.h"
#include "IBlockMaker.h"
#include <map>

class BlockFactory{
public:
    static BlockFactory& Instance();
    Worker* create(const std::string &key);
    void RegisterMaker(const std::string& key, IBlockMaker* maker);
    BlockFactory(const BlockFactory& old) = delete;
    BlockFactory& operator=(const BlockFactory& old) = delete;

private:
    BlockFactory() = default;
    std::map<std::string, IBlockMaker*> makers;

};

#endif //WORKFLOW_BLOCKFACTORY_H
