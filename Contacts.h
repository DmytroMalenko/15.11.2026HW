#pragma once
#include "AbonentData.h"

class PhoneBook {
private:
    Abonent* abonents;
    int count;
    int capacity;

    void resize();

public:
    PhoneBook();
    ~PhoneBook();

    void addAbonent(const Abonent& a);
    void removeAbonent(const char* name);
    void findAbonent(const char* name) const;
    void showAll() const;

    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);
};