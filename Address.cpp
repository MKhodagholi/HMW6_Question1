#include "Address.h"

Address::Address() : country(""), city(""), street("") {}

std::string Address::get_address() {
    return country + " " + city + " " + street;
}

void Address::set_address(const std::string &country, const std::string &city, const std::string &street) {
    this->country = country;
    this->city = city;
    this->street = street;
}

std::ostream& operator << (std::ostream &print, const Address &obj) {
    print << obj.country << ", " << obj.city << ", " << obj.street;
    return print;
}

std::istream& operator >> (std::istream &input, Address &obj) {
    std::cout << "Enter the Address:[1.Country, 2.City, 3.Street]";
    input >> obj.country >> obj.city >> obj.street;
    return input;
}