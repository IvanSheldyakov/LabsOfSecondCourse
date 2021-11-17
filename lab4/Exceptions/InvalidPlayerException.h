//
// Created by Ivan on 11/17/2021.
//

#ifndef BULLSANDCOWS_INVALIDPLAYEREXCEPTION_H
#define BULLSANDCOWS_INVALIDPLAYEREXCEPTION_H


class InvalidPlayerException : public std::exception {
    std::string exception;
public:
    InvalidPlayerException(const std::string& error) : exception(error) {}
    const char* what() const noexcept override {
        return exception.c_str();
    }
};

#endif //BULLSANDCOWS_INVALIDPLAYEREXCEPTION_H
