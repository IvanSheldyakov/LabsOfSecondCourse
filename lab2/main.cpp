#include <iostream>
#include "HashTable.h"

int main() {
    HashTable* table1 = new HashTable();

    HashTable* table2 = new HashTable();

    HashTable t;
    HashTable g;

    Value *v2 = new Value(23,78,"a");
    Value *v1 = new Value(23,78,"b");
    Value *v3 = new Value(23,78,"c");
    Value *v4 = new Value(23,78,"d");
    Value *v5 = new Value(23,78,"v");

    table1->insert("b",*v1);
    table1->insert("c",*v3);
    t.insert("d",*v4);
    g.insert("v",*v5);
    table2->insert("a",*v2);
    if (*table1 == *table2) {
        std::cout << "yes";
    } else {
        std::cout <<"no";
    }



    //table1->erase("a");
    //std::cout << table1->at("d").age << table1->at("v").weight << std::endl;
    //table1->erase("c");
    //std::cout << table1->size();



    delete table1;
    delete table2;
   // delete f;

    return 0;
}
