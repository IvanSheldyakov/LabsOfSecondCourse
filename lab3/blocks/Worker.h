//
// Created by Ivan on 10/20/2021.
//

#ifndef WORKFLOW_WORKER_H
#define WORKFLOW_WORKER_H

#include <string>
#include <list>
#include "IncorrectAmountOfParams.h"
#include "FileDoesNotExistException.h"
#include "InOutValuesForBlock.h"


class Worker{
public:
    virtual std::list<std::string>& execute(const std::list<std::string>& params, std::list<std::string>& text) = 0;
    virtual InOutValuesForBlock& getType(InOutValuesForBlock& values) = 0;
    virtual ~Worker() = default;
};


#endif //WORKFLOW_WORKER_H
