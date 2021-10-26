//
// Created by Ivan on 10/21/2021.
//

#ifndef WORKFLOW_WORKFLOW_H
#define WORKFLOW_WORKFLOW_H

#endif //WORKFLOW_WORKFLOW_H

#include "WorkFlowParser.h"

class WorkFlow{
    WorkFlowParser parser;
public:
    void executeWorkFlow(const std::string& filename);
};