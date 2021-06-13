#ifndef JUNGLE_PERSON_H
#define JUNGLE_PERSON_H
#include <string>
#include "Address.h"
#include <iostream>

class Person {
private:
    std::string name;
    Address address;
    std::string id;




public:
    Person();
    Person(const std::string&, const std::string&, const Address&);
    Person(const Person&);
    void set_name(const std::string&);
    void set_id(const std::string&);
    void set_address(const Address&);
    std::string get_name();
    std::string get_id();
    Address get_address();
    friend std::ostream& operator << (std::ostream&, Person&);
    friend std::istream& operator >> (std::istream&, Person&);
    Person& operator = (const Person&);
    virtual bool validate();


};


#endif //JUNGLE_PERSON_H
