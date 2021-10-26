//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_SORTBLOCK_H
#define WORKFLOW_SORTBLOCK_H

#include "Worker.h"

class SortBlock : public Worker{
    std::string blockName;
public:
    SortBlock(const std::string& name) : blockName(name){}
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutValuesForBlock& getType(InOutValuesForBlock& values) override {
        values.setIn("text");
        values.setOut("text");
        return values;
    }

private:
    void takeArguments(const std::list<std::string>& params);
};

#endif //WORKFLOW_SORTBLOCK_H
