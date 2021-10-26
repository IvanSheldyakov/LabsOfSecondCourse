//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_WRITEFILEBLOCK_H
#define WORKFLOW_WRITEFILEBLOCK_H

#include "Worker.h"

class WriteFileBlock : public Worker {
    std::string blockName;
    std::string filename;
public:
    WriteFileBlock(const std::string& name) : blockName(name)  {}
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutValuesForBlock& getType(InOutValuesForBlock& values) override {
        values.setIn("text");
        values.setOut("no");
        return values;
    }

private:
    void takeArguments(const std::list<std::string>& params);
};

#endif //WORKFLOW_WRITEFILEBLOCK_H
