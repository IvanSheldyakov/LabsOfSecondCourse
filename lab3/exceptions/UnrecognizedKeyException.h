//
// Created by Ivan on 11/6/2021.
//

#ifndef WORKFLOW_UNRECOGNIZEDKEYEXCEPTION_H
#define WORKFLOW_UNRECOGNIZEDKEYEXCEPTION_H

class UnrecognizedKeyException : public std::exception {
    std::string exception;
public:
    UnrecognizedKeyException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //WORKFLOW_UNRECOGNIZEDKEYEXCEPTION_H
