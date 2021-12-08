//
// Created by Ivan on 12/8/2021.
//

#ifndef CSVPARSER_UNKNOWNTYPEEXCEPTION_H
#define CSVPARSER_UNKNOWNTYPEEXCEPTION_H


class UnknownTypeException : public std::exception {
    std::string exception;
public:
    UnknownTypeException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};


#endif //CSVPARSER_UNKNOWNTYPEEXCEPTION_H
