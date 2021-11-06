//
// Created by Ivan on 10/19/2021.
//

#include "WorkFlowParser.h"

#include <iostream>
#include <fstream>
#include "CantOpenFileException.h"

void WorkFlowParser::readWorkFlowFile(std::string filename) {

    std::ifstream file;
    try {
        file.open(filename, std::ios::in);
    } catch (std::exception& exception) {
        throw CantOpenFileException("cant open file " + filename);
    }

    bool blockPart = true;

    while (!file.eof()) {
        std::string line = "";
        std::getline(file,line);
        if (line == "csed") { blockPart = false;}

        if (blockPart) {
            parseBlockString(line);
        } else {
            parseScheme(line);
        }
    }
    file.close();
}


void WorkFlowParser::parseBlockString(std::string &line) {
    if (line == "desc") {return;}
    BlockArguments blockArgs;
    std::string word = "";
    int count = 0;
    int id;
    for (int i = 0; i <= line.size(); i++) {
        if (i == line.size() || !isalpha(line[i]) && !isdigit(line[i]) && !ispunct(line[i])) {
            if (word.size() > 0) {
                if (count == 0) {
                    try {
                        id = std::stoi(word);
                    } catch (std::invalid_argument& exception) {
                        throw std::invalid_argument("id must to be a number");
                    }

                } else if (count == 1) {
                    blockArgs.setName(word);
                } else {
                    std::list<std::string> params  = blockArgs.getParams();
                    params.push_back(word);
                    blockArgs.setParams(params);
                }
                count++;
                word = "";
            }
        }
        else {
            if (line[i] != '=') {word.push_back(line[i]);}
        }
    }
    bunchOfBlocksArgs.insert(std::make_pair(id, blockArgs));
}



void WorkFlowParser::parseScheme(std::string &line) {
    if (line == "csed") {return;}
    std::string num;
    int id;
    for (int i = 0; i <= line.size(); i++) {
        if (i != line.size() && isdigit(line[i])) {
            num.push_back(line[i]);
        } else {
            if (num.size() > 0) {
                try {
                    id = std::stoi(num);
                } catch (std::invalid_argument& exception) {
                    throw std::invalid_argument("id must to be a number");
                }
                scheme.push_back(id);
                num = "";
            }
        }
    }
    if (num.size() > 0) {
        try {
            id = std::stoi(num);
        } catch (std::invalid_argument& exception) {
            throw std::invalid_argument("id must to be a number");
        }
        scheme.push_back(id);
    }
}

const std::map<int, BlockArguments> &WorkFlowParser::getBunchOfBlocksArgs() const {
    return bunchOfBlocksArgs;
}


const std::list<int> &WorkFlowParser::getScheme() const {
    return scheme;
}



