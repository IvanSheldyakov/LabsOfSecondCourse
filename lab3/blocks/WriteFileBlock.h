//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_WRITEFILEBLOCK_H
#define WORKFLOW_WRITEFILEBLOCK_H

#include "Worker.h"

class WriteFileBlock : public Worker {

public:
    WriteFileBlock() = default;
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutTypesForBlock& getInType(InOutTypesForBlock& inType) override {
        inType = InOutTypesForBlock::TEXT;
        return inType;
    }
    InOutTypesForBlock& getOutType(InOutTypesForBlock& outType) override {
        outType = InOutTypesForBlock::NO;
        return outType;
    }

};

#endif //WORKFLOW_WRITEFILEBLOCK_H
