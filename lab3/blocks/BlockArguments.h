//
// Created by Ivan on 10/19/2021.
//

#ifndef WORKFLOW_BLOCKARGUMENTS_H
#define WORKFLOW_BLOCKARGUMENTS_H

#include <string>
#include <list>

struct BlockArguments {
private:
    std::string name;
    std::list<std::string> params;
public:
    BlockArguments() {
        this->name = "";
    }
    BlockArguments(const std::string& name) {
        this->name = name;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        BlockArguments::name = name;
    }

    const std::list<std::string> &getParams() const {
        return params;
    }

    void setParams(const std::list<std::string> &params) {
        BlockArguments::params = params;
    }

};

#endif //WORKFLOW_BLOCKARGUMENTS_H
