//
// Created by Ivan on 12/8/2021.
//

#ifndef CSVPARSER_LINEOUTOFRANGEEXCEPTION_H
#define CSVPARSER_LINEOUTOFRANGEEXCEPTION_H

class LineOutOfRangeException : public std::exception {
    std::string exception;
public:
    LineOutOfRangeException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //CSVPARSER_LINEOUTOFRANGEEXCEPTION_H
