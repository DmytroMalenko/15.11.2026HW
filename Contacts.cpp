#include <iostream>
#include <fstream> 
#include "Contacts.h"
using namespace std;

bool isEqual(const char* s1, const char* s2) {
    if (s1 == nullptr || s2 == nullptr) return false;
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) return false;
        i++;
    }
    return s1[i] == s2[i];
}

PhoneBook::PhoneBook() : abonents(nullptr), count(0), capacity(0) {}

PhoneBook::~PhoneBook() {
    delete[] abonents;
}

void PhoneBook::resize() {
    capacity = (capacity == 0) ? 2 : capacity * 2;
    Abonent* newArr = new Abonent[capacity];
    for (int i = 0; i < count; ++i) {
        newArr[i] = abonents[i];
    }
    delete[] abonents;
    abonents = newArr;
}

void PhoneBook::addAbonent(const Abonent& a) {
    if (count >= capacity) {
        resize();
    }
    abonents[count] = a;
    count++;
}

void PhoneBook::removeAbonent(const char* name) {
    for (int i = 0; i < count; ++i) {
        if (isEqual(abonents[i].getName(), name)) {
            for (int j = i; j < count - 1; ++j) {
                abonents[j] = abonents[j + 1];
            }
            count--;
            cout << "Abonent removed.\n";
            return;
        }
    }
    cout << "Abonent not found.\n";
}

void PhoneBook::findAbonent(const char* name) const {
    for (int i = 0; i < count; ++i) {
        if (isEqual(abonents[i].getName(), name)) {
            abonents[i].print();
            return;
        }
    }
    cout << "Abonent not found.\n";
}

void PhoneBook::showAll() const {
    if (count == 0) {
        cout << "Phonebook is empty.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        abonents[i].print();
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file for writing.\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        file << abonents[i].getName() << "\n";
        file << abonents[i].getHome() << "\n";
        file << abonents[i].getWork() << "\n";
        file << abonents[i].getMobile() << "\n";
        file << abonents[i].getInfo() << "\n";
    }
    file.close();
    cout << "Saved to file.\n";
}

void PhoneBook::loadFromFile(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file for reading.\n";
        return;
    }

    char n[256], h[256], w[256], m[256], inf[256];

    while (file.getline(n, 256)) {
        file.getline(h, 256);
        file.getline(w, 256);
        file.getline(m, 256);
        file.getline(inf, 256);

        Abonent temp(n, h, w, m, inf);
        addAbonent(temp);
    }
    file.close();
    cout << "Loaded from file.\n";
}