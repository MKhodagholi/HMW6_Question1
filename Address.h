#ifndef JUNGLE_ADDRESS_H
#define JUNGLE_ADDRESS_H
#include <iostream>
#include <string>

class Address {
private:
    std::string country;
    std::string city;
    std::string street;
public:
    Address(const std::string&, const std::string&, const std::string&);
    std::string get_country();
    std::string get_city();
    std::string get_street();
    void set_country(const std::string&);
    void set_city(const std::string&);
    void set_street(const std::string&);
    friend std::ostream& operator << (std::ostream&, const Address&);
    friend std::istream& operator >> (std::istream&, Address&);
    Address& operator = (const Address&);

};


#endif //JUNGLE_ADDRESS_H
