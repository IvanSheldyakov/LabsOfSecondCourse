//
// Created by Ivan on 11/17/2021.
//

#ifndef BULLSANDCOWS_INVALIDLENGTHOFGUESS_H
#define BULLSANDCOWS_INVALIDLENGTHOFGUESS_H

class InvalidLengthOfGuess : public std::exception {
    std::string exception;
public:
    InvalidLengthOfGuess(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};

#endif //BULLSANDCOWS_INVALIDLENGTHOFGUESS_H
