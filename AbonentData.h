#pragma once
#include <iostream>

class Abonent {
private:
    char* fullName;      
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* extraInfo;

public:
    Abonent();
    Abonent(const char* name, const char* home, const char* work, const char* mobile, const char* info);
    Abonent(const Abonent& other); 

    ~Abonent();

    Abonent& operator=(const Abonent& other);

    const char* getName() const { 
        return fullName;
    }
    const char* getHome() const { 
        return homePhone;
    }
    const char* getWork() const { 
        return workPhone;
    }
    const char* getMobile() const { 
        return mobilePhone;
    }
    const char* getInfo() const { 
        return extraInfo;
    }

    void print() const;
};