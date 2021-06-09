#include "Person.h"

Person::Person() : name(""), id(""), address() {}

Person::Person(const std::string &name, const std::string &id, const Address &address) : name(name), id(id), address(address) {
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
    print << "name is: " << obj.name;
    print << " id is: " << obj.id;
    print << " address is: " << obj.address;
    return print;
}

std::istream& operator >> (std::istream &input, Person &obj) {

    std::cout << "name is: "; input >> obj.name;
    std::cout <<  "id is: "; input >> obj.id;
    std::cout <<  "address is: "; input >> obj.address;
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
        if (id[0] - '0' >= 8 && id[0] - '0' <= 9)
            return false;
        else {
            if (id[1] - '0' <= 3 && id[1] - '0' >= 0)
                return false;
            else {
                int count = 3;
                for (int i = 2; i < 5; i++) {
                    if (count == 0)
                        return false;
                    if (id[i] - '0' >= 0 && id[i] - '0' < 10)
                        count++;
                }
                for (int i = 5; i < 10; i++) {
                    if (id[i] >= 4 && id[i] <= 6)
                        return false;
                }
                return true;
            }
        }
    }

}