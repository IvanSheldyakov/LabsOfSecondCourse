//
// Created by Ivan on 12/8/2021.
//

#ifndef CSVPARSER_TUPLEOUTOFRANGEEXCEPTION_H
#define CSVPARSER_TUPLEOUTOFRANGEEXCEPTION_H

class TupleOutOfRangeException : public std::exception {
    std::string exception;
public:
    TupleOutOfRangeException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //CSVPARSER_TUPLEOUTOFRANGEEXCEPTION_H
