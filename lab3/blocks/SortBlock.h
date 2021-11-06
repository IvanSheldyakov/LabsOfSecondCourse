//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_SORTBLOCK_H
#define WORKFLOW_SORTBLOCK_H

#include "Worker.h"

class SortBlock : public Worker{

public:
    SortBlock() = default;
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

#endif //WORKFLOW_SORTBLOCK_H
