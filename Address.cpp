#include "Address.h"

Address::Address(const std::string &country, const std::string &city, const std::string &street) :
country(country), city(city), street(street) {}

std::string Address::get_country() {
    return country;
}

std::string Address::get_city() {
    return city;
}

std::string Address::get_street() {
    return street;
}

void Address::set_country(const std::string &country) {
    this->country = country;
}

void Address::set_city(const std::string &city) {
    this->city = city;
}

void Address::set_street(const std::string &street) {
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

Address& Address::operator = (const Address &obj) {
    country = obj.country;
    city = obj.city;
    street = obj.street;
    return *this;
}
