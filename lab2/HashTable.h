//
// Created by Ivan on 9/25/2021.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include <cstddef>
#include <string>
#include <list>
#include <array>

typedef std::string Key;

struct Student {
    unsigned age;
    unsigned weight;
    Key key;
    Student(unsigned age, unsigned  weight, const Key& key) {
        this->age = age;
        this->weight = weight;
        this->key = key;
    }
};


typedef Student Value;
typedef std::list<Value>** Table;
typedef std::list<Value>* ListOfTable;

class HashTable {

    size_t bufferSize = 4;
    size_t amountOfElements = 0;
    const double loadFactor = 0.75;
    Table table;

public:
    HashTable();
    ~HashTable();

    HashTable(const HashTable& old);
    HashTable(HashTable&& old);


    HashTable& operator=(const HashTable& old);
    HashTable& operator=(HashTable&& old);


    // Обменивает значения двух хэш-таблиц.
    void swap(HashTable& other);

    // Очищает контейнер.
    void clear();
    // Удаляет элемент по заданному ключу.
    bool erase(const Key& key);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool insert(const Key& key, const Value& value);

    // Проверка наличия значения по заданному ключу.
    bool contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& at(const Key& key);
    const Value& at(const Key& key) const;

    size_t size() const;
    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);
private:
    int calculate_hash(const Key& key, int size) const;
    void resize();
    void freeMemory();

};

bool operator==(const HashTable& a, const HashTable& b);

bool operator!=(const HashTable& a, const HashTable& b);


#endif //HASHTABLE_HASHTABLE_H
