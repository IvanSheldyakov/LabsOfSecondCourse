//
// Created by Ivan on 11/6/2021.
//

#ifndef WORKFLOW_TOOMANYMAKERSFORONEKEY_H
#define WORKFLOW_TOOMANYMAKERSFORONEKEY_H

class TooManyMakerForOneKey : public std::exception {
    std::string exception;
public:
    TooManyMakerForOneKey(const std::string& error) : exception(error) {}
    const char* what() const noexcept override{
        return exception.c_str();
    }
};


#endif //WORKFLOW_TOOMANYMAKERSFORONEKEY_H
