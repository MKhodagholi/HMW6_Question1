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
    Address();
    std::string get_address();
    void set_address(const std::string&, const std::string&, const std::string&);
    friend std::ostream& operator << (std::ostream&, const Address&);
    friend std::istream& operator >> (std::istream&, Address&);

};


#endif //JUNGLE_ADDRESS_H
