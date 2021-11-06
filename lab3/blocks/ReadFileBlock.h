//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_READFILEBLOCK_H
#define WORKFLOW_READFILEBLOCK_H

#include "Worker.h"

class ReadFileBlock : public Worker{

public:
    ReadFileBlock() = default;
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutTypesForBlock& getInType(InOutTypesForBlock& inType) override {
        inType = InOutTypesForBlock::NO;
        return inType;
    }
    InOutTypesForBlock& getOutType(InOutTypesForBlock& outType) override {
        outType = InOutTypesForBlock::TEXT;
        return outType;
    }

};


#endif //WORKFLOW_READFILEBLOCK_H
