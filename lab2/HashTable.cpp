//
// Created by Ivan on 9/25/2021.
//


#include "HashTable.h"
#include <cmath>
#include <iostream>

HashTable::HashTable() {
    table = new ListOfTable[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        table[i] = new std::list<const Value*>;
    }
}

HashTable::~HashTable() {
    freeMemory();
}

HashTable::HashTable(const HashTable &old) {
    bufferSize = old.bufferSize;
    amountOfElements = old.amountOfElements;
    table = new ListOfTable[bufferSize];
    for (int i = 0; i < bufferSize; i++) {
        table[i] = new std::list<const Value*>;
        for (auto & it : *old.table[i]) {
            table[i]->push_back(new Value(it->age,it->weight,it->key));
        }
    }
}


HashTable::HashTable(HashTable &&old) {
    bufferSize = old.bufferSize;
    amountOfElements = old.amountOfElements;
    table = old.table;
    old.table = nullptr;
    old.bufferSize = 0;

}

Value& HashTable::operator[](const Key &k) {
    try {
        return this->at(k);

    } catch (const std::invalid_argument& e) {
        Value* value = new Value(0,0,k);
        this->insert(k, *value);
        return *value;
    }


}

HashTable& HashTable::operator=(const HashTable &old) {
    HashTable hashTable(old);
    swap(hashTable);

    return *this;
}

HashTable& HashTable::operator=(HashTable &&old) {
    HashTable hashTable(old);
    swap(hashTable);
    old.table = nullptr;
    old.bufferSize = 0;

    return *this;
}


bool operator==(const HashTable& a, const HashTable& b) {
    if (a.bufferSize != b.bufferSize && a.amountOfElements != b.amountOfElements) {
        return false;
    }

    for (int i = 0; i < a.bufferSize; i++) {
        ListOfTable listA = a.table[i];
        ListOfTable listB = b.table[i];
        if (listA->size() == listB->size()) {
            for (auto itA = listA->begin(); itA != listA->end(); itA++) {
                for (auto itB = listB->begin(); itB != listB->end(); itB++) {
                    Value valueA = (**itA);
                    Value valueB = (**itB);
                    if (valueA.age != valueB.age || valueA.weight != valueB.weight || valueA.key != valueB.key) {
                        return false;
                    }
                }
            }
        } else {
            return false;
        }
    }
    return true;
}

bool operator!=(const HashTable& a, const HashTable& b) {
    return !(a == b);
}

bool HashTable::insert(const Key &key, const Value &value) {
    if (contains(key)) {return false;}
    double newFactor = amountOfElements / (double)bufferSize;
    if (newFactor > loadFactor) {
        resize();
    }
    int hash = calculate_hash(key,bufferSize);
    table[hash]->push_back(&value);
    amountOfElements++;
    return true;
}

void HashTable::swap(HashTable &other) {
    std::swap(bufferSize,other.bufferSize);
    std::swap(amountOfElements,other.amountOfElements);
    std::swap(table,other.table);
}

bool HashTable::contains(const Key &k) const {
    try {
        this->at(k);
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }
}

Value& HashTable::at(const Key &key) {
    int hash = calculate_hash(key,bufferSize);
    ListOfTable list = table[hash];
    for (auto it = list->begin(); it != list->end(); it++) {

        if (key == (*it)->key) {
            return (Value&)(**it);
        }
    }
    throw std::invalid_argument("No such key");
}

const Value& HashTable::at(const Key &key) const {
    int hash = calculate_hash(key,bufferSize);
    ListOfTable list = table[hash];
    for (auto & it : *list) {
        if (key == it->key) {
            return *it;
        }
    }
    throw std::invalid_argument("No such key");
}

bool HashTable::erase(const Key &key) {
    try {
        Value& a = this->at(key);
        delete &a;
        int hash = calculate_hash(key,bufferSize);
        ListOfTable list = table[hash];
        list->remove(&a);
        amountOfElements--;
        return true;
    } catch (const std::invalid_argument& e) {
        return false;
    }

}

void HashTable::clear() {
    for (int i = 0; i < bufferSize; i++) {
        for (auto &it: *table[i]) {
            delete it;
        }
        table[i]->clear();

    }
    amountOfElements = 0;
}

bool HashTable::empty() const {
    return (amountOfElements == 0);
}

size_t HashTable::size() const {
    return amountOfElements;
}


void HashTable::resize() {
    size_t newBufferSize = bufferSize*2;
    Table newTable = new ListOfTable[newBufferSize];
    for (int i = 0; i < newBufferSize; i++) {
        newTable[i] = new std::list<const Value*>;
    }
    for (int i = 0; i < bufferSize; i++) {
        ListOfTable list = table[i];
        for (auto it = list->begin(); it != list->end(); it++) {
            Value value = (**it);
            int hash = calculate_hash(value.key,newBufferSize);
            newTable[hash]->push_back(new Value(value.age,value.weight,value.key));
            delete (*it);
        }
        delete table[i];
    }

    delete []table;
    table = newTable;
    bufferSize = newBufferSize;

}

void HashTable::freeMemory() {
    if (table == nullptr) {return;}
    for (int i = 0; i < bufferSize; i++) {
        for (auto it = table[i]->begin(); it != table[i]->end(); it++) {
            delete (*it);
        }
        delete table[i];
    }
    delete []table;
}

int HashTable::calculate_hash(const Key &key, int size) const {
    size_t len = key.length();
    size_t hash = 0;
    for (int i = 0; i < len; i++) {
        int symbol = (int)key[i];
        hash += (symbol % 3) * (int)pow(3, i);
    }
    return (int)(hash % size);
}


