//
// Created by Ivan on 12/4/2021.
//

#ifndef CSVPARSER_CSVPARSER_H
#define CSVPARSER_CSVPARSER_H



#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include "EmptyStringException.h"
#include "UnknownTypeException.h"
#include "TupleOutOfRangeException.h"



template<typename... Types>
class CSVparser{
    std::vector<std::tuple<Types...>> data;
    std::ifstream& in;
    std::string line;
    int lastLineIdx;
    int column = 0;
    int row = 0;
    char columnSeparator;
    char rowSeparator;
    char shieldingSymbol;
    bool meetShieldingSymbol;
public:

    CSVparser(std::ifstream& _in, int countOfSkips, char _columnSeparator, char _rowSeparator, char _shieldingSymbol)
    : in(_in), columnSeparator(_columnSeparator), rowSeparator(_rowSeparator), shieldingSymbol(_shieldingSymbol) {

        skipLines(countOfSkips);
        while(!in.eof()) {
            std::tuple<Types...> cells;
            try {
                parseCell<0>(cells);
            } catch(TupleOutOfRangeException& exp) {
                data.push_back(cells);
                row++;
                column = 0;
            }
        }
    }


private:
    template<size_t N>
    typename std::enable_if<(N < sizeof...(Types))>::type parseCell(std::tuple<Types...>& cells) {
        std::string cell;
        try{
            cell = readCell();
        } catch (std::exception& ex) {
            return;
        }
        pushValue<N>(cells,cell);
        column++;
        parseCell<N+1>(cells);

    }

    template<size_t n>
    [[noreturn]] typename std::enable_if<(n >= sizeof...(Types))>::type parseCell(std::tuple<Types...>& cells){
        throw TupleOutOfRangeException("tuple out of range");
    }

    template<size_t N>
    void pushValue(std::tuple<Types...>& cells, const std::string& str) {
        try {
            std::istringstream stream(str);
            stream.exceptions(std::istringstream::failbit);
            stream >> std::get<N>(cells);
        }catch (std::istringstream::failure &ex){
            throw UnknownTypeException("column: " + std::to_string(column)
            + ", row: " + std::to_string(row) + " - UnknownType");
        }
    }

    std::string readCell() {
        if (line.empty()) {
            std::getline(in, line, rowSeparator);
            lastLineIdx = 0;
            if (line.empty()) {throw EmptyStringException("line is empty");}
        }
        std::string cell;
        meetShieldingSymbol = false;
        for (int i = lastLineIdx; i <= line.size(); i++) {
            if (i == line.size()) {
                line = "";
                return cell;
            } else if (line[i] == columnSeparator) {
                if (meetShieldingSymbol) {
                    cell.push_back(line[i]);
                } else {
                    lastLineIdx = i + 1;
                    return cell;
                }
            } else if (line[i] == shieldingSymbol && meetShieldingSymbol) {
                meetShieldingSymbol = false;

            } else if (line[i] == shieldingSymbol && !meetShieldingSymbol) {
                meetShieldingSymbol = true;

            } else {
                cell.push_back(line[i]);
            }
        }
    }

    void skipLines(int amountOfLines) {
        for (int i = 0; i < amountOfLines; i++) {
            std::string _line;
            std::getline(in,_line);
        }
    }

private:

    class Iterator {
        typedef typename std::tuple<Types...> value;

    public:
        Iterator(typename std::vector<std::tuple<Types...>>::iterator it) : it(it){};

        bool operator!=(Iterator const& other) const {
            return it != other.it;
        }
        bool operator==(Iterator const& other) const {
            return it == other.it;
        }
        value& operator*() const {
            return *it;
        }

        Iterator& operator++() {
            ++it;
            return *this;
        }

    private:
        typename std::vector<std::tuple<Types...>>::iterator it;
    };

public:
    Iterator begin() {
        return Iterator(data.begin());
    }

    Iterator end() {
        return Iterator(data.end());
    }
};

template<class charT, class trT, class T>
typename std::enable_if<(std::is_same_v<T, std::string>), typename std::basic_istringstream<charT, trT>&>::type
operator>>(std::basic_istringstream<charT, trT>& st, T& t){
    t = st.str();
    return st;
}




#endif //CSVPARSER_CSVPARSER_H
