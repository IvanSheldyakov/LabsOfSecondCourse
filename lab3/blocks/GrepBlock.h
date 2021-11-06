//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_GREPBLOCK_H
#define WORKFLOW_GREPBLOCK_H

#include "Worker.h"

class GrepBlock : public Worker {

public:
    GrepBlock() = default;
    std::list<std::string>& execute(const std::list<std::string> &params, std::list<std::string> &text) override;
    InOutTypesForBlock& getInType(InOutTypesForBlock& inType) override {
        inType = InOutTypesForBlock::TEXT;
        return inType;
    }
    InOutTypesForBlock& getOutType(InOutTypesForBlock& outType) override {
        outType = InOutTypesForBlock::TEXT;
        return outType;
    }

};

#endif //WORKFLOW_GREPBLOCK_H
