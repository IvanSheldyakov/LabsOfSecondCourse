//
// Created by Ivan on 10/19/2021.
//

#ifndef WORKFLOW_WORKFLOWPARSER_H
#define WORKFLOW_WORKFLOWPARSER_H

#include "BlockArguments.h"
#include <map>


class WorkFlowParser {

    std::map<int, BlockArguments> BunchOfBlocksArgs;
    std::list<int> scheme;
public:
    void readWorkFlowFile(std::string file);

    const std::map<int, BlockArguments> &getBunchOfBlocksArgs() const;

    void setBunchOfBlocksArgs(const std::map<int, BlockArguments> &blocks);

    const std::list<int> &getScheme() const;

    void setScheme(const std::list<int> &scheme);

private:
    void parseBlockString(std::string& line);
    void parseScheme(std::string& line);
};

#endif //WORKFLOW_WORKFLOWPARSER_H
