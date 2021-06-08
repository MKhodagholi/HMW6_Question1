#include "Person.h"


Person::Person(const std::string &name, const std::string &id, const Address &address)
                                    :   name(name), id(id), address(address) {}

Person::Person(const Person &obj) {
    name = obj.name;
    id = obj.id;
    address = obj.address;
}

std::string Person::get_name() {
    return name;
}

void Person::set_name(const std::string &name) {
    this->name = name;
}

std::string Person::get_id() {
    return id;
}

void Person::set_id(const std::string &id) {
    this->id = id;
}

Address Person::get_address() {
    return address;
}

void Person::set_address(const Address &address) {
    this->address = address;
}

Person& operator = (const Person&);