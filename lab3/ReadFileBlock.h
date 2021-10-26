//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_READFILEBLOCK_H
#define WORKFLOW_READFILEBLOCK_H

#include "Worker.h"

class ReadFileBlock : public Worker{
    std::string blockName;
    std::string filename;
public:
    ReadFileBlock(const std::string& _blockName) : blockName(_blockName) {}
    std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) override;
    InOutValuesForBlock& getType(InOutValuesForBlock& values) override {
        values.setIn("no");
        values.setOut("text");
        return values;
    }

private:
    void takeArguments(const std::list<std::string>& params);
};


#endif //WORKFLOW_READFILEBLOCK_H
