//
// Created by Ivan on 12/8/2021.
//

#ifndef CSVPARSER_EMPTYSTRINGEXCEPTION_H
#define CSVPARSER_EMPTYSTRINGEXCEPTION_H

class EmptyStringException : public std::exception {
    std::string exception;
public:
    EmptyStringException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //CSVPARSER_EMPTYSTRINGEXCEPTION_H
