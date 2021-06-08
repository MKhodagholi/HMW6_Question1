#ifndef JUNGLE_PERSON_H
#define JUNGLE_PERSON_H
#include <string>
#include "Address.h"
#include <iostream>

class Person {
private:
    std::string name;
    std::string id;
    Address address;

public:
    Person(const std::string&, const std::string&, const Address&);
    Person(const Person&);
    void set_name(const std::string&);
    void set_id(const std::string&);
    void set_address(const std::string&);
    std::string get_name();
    std::string get_id();
    Address get_address();
    void set_address(const Address&);
    friend std::ostream& operator << (std::ostream &print, Person &obj);
    friend std::istream& operator >> (std::istream &input, Person &obj);
    Person& operator = (const Person&);
    bool validate(const std::string&);
};


#endif //JUNGLE_PERSON_H
