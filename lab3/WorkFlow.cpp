//
// Created by Ivan on 10/21/2021.
//

#include "WorkFlow.h"
#include "BlockFactory.h"
#include "iostream"



void WorkFlow::executeWorkFlow(const std::string &filename) {
    try {
        parser.readWorkFlowFile(filename);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return;
    }
    BlockFactory factory = BlockFactory::Instance();
    std::list<std::string> text;
    auto scheme = parser.getScheme();
    auto blockArgsMap = parser.getBunchOfBlocksArgs();
    InOutValuesForBlock prevValues("no","no");
    InOutValuesForBlock currentValues;
    for (auto it = scheme.begin(); it != scheme.end(); ++it) {
        BlockArguments blockArgs = blockArgsMap.at(*it);
        Worker* block;
        try {
            block = factory.create(blockArgs.getName());
            currentValues = block->getType(currentValues);
            if (currentValues.getIn() != prevValues.getOut()) {
                std::cout << "workflow is incorrect" << std::endl;
                delete block;
                break;
            }
            prevValues = currentValues;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            break;
        }

        auto params = blockArgs.getParams();
        try {
            text = block->execute(params, text);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            delete block;
            break;
        }

        delete block;
    }
}

