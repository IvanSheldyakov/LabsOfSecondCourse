
#include "CSVParser.h"
#include "TuplePrinter.h"
#include <iostream>



int main() {

    std::ifstream file;
    file.open("a.txt",std::ios::in);
    if (!file.is_open()) {return 0;}

    try {
        CSVparser<std::string,std::string,int> parse(file,0,',','\n','\"');
        for(auto & it : parse) {
            std::cout << it;
        }
    }catch (std::exception& exp) {
        std::cout << exp.what();
    }
    file.close();

    return 0;
}
