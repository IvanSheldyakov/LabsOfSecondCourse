//
// Created by Ivan on 10/23/2021.
//

#ifndef WORKFLOW_INCORRECTAMOUNTOFPARAMS_H
#define WORKFLOW_INCORRECTAMOUNTOFPARAMS_H

#include <string>



class IncorrectAmountOfParams : public std::exception {
    std::string exception;
public:
    IncorrectAmountOfParams(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //WORKFLOW_INCORRECTAMOUNTOFPARAMS_H
