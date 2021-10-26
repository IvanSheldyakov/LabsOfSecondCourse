//
// Created by Ivan on 10/25/2021.
//

#ifndef WORKFLOW_BLOCKDOESNTEXISTEXCEPTION_H
#define WORKFLOW_BLOCKDOESNTEXISTEXCEPTION_H

class BlockDoesntExistException : public std::exception {
    std::string exception;
public:
    BlockDoesntExistException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //WORKFLOW_BLOCKDOESNTEXISTEXCEPTION_H
