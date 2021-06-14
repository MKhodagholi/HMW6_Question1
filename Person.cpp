#include "Person.h"

Person::Person() : name(""), id(""), address() {}

Person::Person(std::string name, std::string id, Address address) : name(name), id(id), address(address) {
    if (!validate()) {
        std::cout << "Invalid id";
        exit(0);
    }
}

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

std::ostream& operator << (std::ostream &print, Person &obj) {
    print << "Name is: " << obj.name;
    print << " ID is: " << obj.id << std::endl;
    print << obj.address;
    print << std::endl;
    return print;
}

std::istream& operator >> (std::istream &input, Person &obj) {
    input >> obj.name;
    input >> obj.id;
    input >> obj.address;
    return input;
}


Person& Person::operator = (const Person &obj) {
    name = obj.name;
    id = obj.id;
    address = obj.address;
    return *this;
}

bool Person::validate() {
    int length = id.length();
    if (length != 10)
        return false;
    else {
        if (id[0] - '0' == 8) {
            if (id[1] - '0' <= 3 && id[1] - '0' >= 0)
                return false;
            else {
                int count = 3;
                for (int i = 2; i < 5; i++) {
                    if (id[i] - '0' >= 0 && id[i] - '0' < 10)
                        count--;
                    if (count == 0)
                        return false;
                }
                for (int i = 5; i < 10; i++) {
                    if (id[i] >= 4 && id[i] <= 6)
                        return false;
                }
                return true;
            }
        }
        else if (id[0] - '0' == 9){
            if (id[1] - '0' >= 0 && id[1] - '0' < 10) {
                int count = 3;
                for (int i = 2; i < 5; i++) {
                    if (id[i] - '0' >= 0 && id[i] - '0' < 10)
                        count--;
                    if (count == 0)
                        return false;
                }
                for (int i = 5; i < 10; i++) {
                    if (id[i] >= 4 && id[i] <= 6)
                        return false;
                }
                return true;
            }
            return false;
        }
        return false;
    }
}

