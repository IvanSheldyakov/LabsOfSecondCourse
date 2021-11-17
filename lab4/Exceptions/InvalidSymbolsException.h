//
// Created by Ivan on 11/17/2021.
//

#ifndef BULLSANDCOWS_INVALIDSYMBOLSEXCEPTION_H
#define BULLSANDCOWS_INVALIDSYMBOLSEXCEPTION_H

class InvalidSymbolsException : public std::exception {
    std::string exception;
public:
    InvalidSymbolsException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override {
        return exception.c_str();
    }
};

#endif //BULLSANDCOWS_INVALIDSYMBOLSEXCEPTION_H
