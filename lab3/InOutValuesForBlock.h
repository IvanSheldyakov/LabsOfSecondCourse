//
// Created by Ivan on 10/25/2021.
//

#ifndef WORKFLOW_INOUTVALUESFORBLOCK_H
#define WORKFLOW_INOUTVALUESFORBLOCK_H

#include <string>

class InOutValuesForBlock {
    std::string in;
    std::string out;


public:
    InOutValuesForBlock() = default;
    InOutValuesForBlock(const std::string& in, const std::string& out) {
        this->in = in;
        this->out = out;
    }

    const std::string &getIn() const {
        return in;
    }

    void setIn(const std::string &in) {
        InOutValuesForBlock::in = in;
    }

    const std::string &getOut() const {
        return out;
    }

    void setOut(const std::string &out) {
        InOutValuesForBlock::out = out;
    }
};
#endif //WORKFLOW_INOUTVALUESFORBLOCK_H
