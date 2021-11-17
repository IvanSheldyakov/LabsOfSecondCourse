//
// Created by Ivan on 11/17/2021.
//

#ifndef BULLSANDCOWS_INVALIDAMOUNTOFPOSSIBLESYMBOLS_H
#define BULLSANDCOWS_INVALIDAMOUNTOFPOSSIBLESYMBOLS_H

class InvalidAmountOfPossibleSymbols : public std::exception {
    std::string exception;
public:
    InvalidAmountOfPossibleSymbols(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //BULLSANDCOWS_INVALIDAMOUNTOFPOSSIBLESYMBOLS_H
