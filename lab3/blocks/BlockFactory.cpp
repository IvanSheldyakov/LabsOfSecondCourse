//
// Created by Ivan on 10/21/2021.
//

#include <stdexcept>
#include "BlockFactory.h"
#include "TooManyMakersForOneKey.h"
#include "UnrecognizedKeyException.h"


BlockFactory& BlockFactory::Instance() {
    static BlockFactory factory;
    return factory;
}

void BlockFactory::RegisterMaker(const std::string &key, IBlockMaker *maker) {
    if (makers.find(key) != makers.end())
    {
        throw TooManyMakerForOneKey("too many makers");
    }
    makers[key] = maker;
}

Worker* BlockFactory::create(const std::string &key) {
    auto i = makers.find(key);
    if (i == makers.end())
    {
        throw UnrecognizedKeyException(key + " is unrecognized");
    }
    IBlockMaker* maker = i->second;
    return maker->create();
}



