#include <iostream>
#include <cstring>
#include "AbonentData.h"
using namespace std;

static char* copyStr(const char* src) {
    if (src == nullptr) return nullptr;
    char* dest = new char[strlen(src) + 1];
    strcpy_s(dest, strlen(src) + 1, src);
    return dest;
}

Abonent::Abonent()
    : fullName(nullptr), homePhone(nullptr), workPhone(nullptr), mobilePhone(nullptr), extraInfo(nullptr) {
}

Abonent::Abonent(const char* name, const char* home, const char* work, const char* mobile, const char* info) {
    fullName = copyStr(name);
    homePhone = copyStr(home);
    workPhone = copyStr(work);
    mobilePhone = copyStr(mobile);
    extraInfo = copyStr(info);
}

Abonent::Abonent(const Abonent& other) {
    fullName = copyStr(other.fullName);
    homePhone = copyStr(other.homePhone);
    workPhone = copyStr(other.workPhone);
    mobilePhone = copyStr(other.mobilePhone);
    extraInfo = copyStr(other.extraInfo);
}

Abonent& Abonent::operator=(const Abonent& other) {
    if (this != &other) {
        delete[] fullName;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] extraInfo;

        fullName = copyStr(other.fullName);
        homePhone = copyStr(other.homePhone);
        workPhone = copyStr(other.workPhone);
        mobilePhone = copyStr(other.mobilePhone);
        extraInfo = copyStr(other.extraInfo);
    }
    return *this;
}

Abonent::~Abonent() {
    delete[] fullName;
    delete[] homePhone;
    delete[] workPhone;
    delete[] mobilePhone;
    delete[] extraInfo;
}

void Abonent::print() const {
    cout << "Fullname: " << (fullName ? fullName : "-")
        << " | Home: " << (homePhone ? homePhone : "-")
        << " | Work: " << (workPhone ? workPhone : "-")
        << " | Mobile: " << (mobilePhone ? mobilePhone : "-")
        << " | Info: " << (extraInfo ? extraInfo : "-") << endl;
}