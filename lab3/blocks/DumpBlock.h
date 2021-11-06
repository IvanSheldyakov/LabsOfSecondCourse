//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_DUMPBLOCK_H
#define WORKFLOW_DUMPBLOCK_H

#include "Worker.h"

class DumpBlock : public Worker {


public:
    DumpBlock() = default;
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutTypesForBlock& getInType(InOutTypesForBlock& inType) override {
        inType = InOutTypesForBlock::TEXT;
        return inType;
    }
    InOutTypesForBlock& getOutType(InOutTypesForBlock& outType) override {
        outType = InOutTypesForBlock::TEXT;
        return outType;
    }
};

#endif //WORKFLOW_DUMPBLOCK_H
