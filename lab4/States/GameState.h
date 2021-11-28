//
// Created by Ivan on 11/28/2021.
//

#ifndef BULLSANDCOWS_GAMESTATE_H
#define BULLSANDCOWS_GAMESTATE_H

class GameState {
public:
    virtual int getLenOfSequence() = 0;
    virtual void setLen(int len) = 0;
    virtual int getAmountOfPossibleSymbols() = 0;
    virtual void setAmountOfPossibleSymbols(int amount) = 0;
    virtual int getCows() = 0;
    virtual void setCows(int cows) = 0;
    virtual int getBulls() = 0;
    virtual void setBulls(int bulls) = 0;
    virtual std::string& getDescription() = 0;
    virtual ~GameState() = default;
};

#endif //BULLSANDCOWS_GAMESTATE_H
