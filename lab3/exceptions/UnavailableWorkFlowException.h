//
// Created by Ivan on 11/6/2021.
//

#ifndef WORKFLOW_UNAVAILABLEWORKFLOWEXCEPTION_H
#define WORKFLOW_UNAVAILABLEWORKFLOWEXCEPTION_H


class UnavailableWorkFlowException : public std::exception {
    std::string exception;
public:
    UnavailableWorkFlowException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};


#endif //WORKFLOW_UNAVAILABLEWORKFLOWEXCEPTION_H
