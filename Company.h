#ifndef JUNGLE_COMPANY_H
#define JUNGLE_COMPANY_H
#include "Boss.h"
#include <iostream>

class Company {
private:
    int budget;
    Boss *boss;
    Employee **employee;
public:
    // constructor and destructor
    Company();
    Company(int, Boss*, Employee**);
    Company(const Company&);
    ~Company();
    // print and input operator
    friend std::ostream& operator << (std::ostream&, const Company&);
    friend std::istream& operator << (std::istream&, Company&);
    void set_budget(int);
    void set_boss(Boss*);
    void set_employee(Employee**);
    int get_budget();
    Boss* get_boss();
    Employee** get_employee();
};


#endif //JUNGLE_COMPANY_H