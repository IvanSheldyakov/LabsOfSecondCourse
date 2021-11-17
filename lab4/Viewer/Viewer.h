//
// Created by Ivan on 11/10/2021.
//

#ifndef BULLSANDCOWS_VIEWER_H
#define BULLSANDCOWS_VIEWER_H

class Viewer{
public:
    virtual void println(const std::string& output) = 0;
    virtual void print(const std::string& output) = 0;
    virtual ~Viewer() = default;
};

#endif //BULLSANDCOWS_VIEWER_H
