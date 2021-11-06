//
// Created by Ivan on 11/6/2021.
//

#ifndef WORKFLOW_IBLOCKMAKER_H
#define WORKFLOW_IBLOCKMAKER_H

class IBlockMaker {

public:
    virtual Worker* create() = 0;
    virtual ~IBlockMaker() {}
};

#endif //WORKFLOW_IBLOCKMAKER_H
