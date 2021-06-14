#ifndef JUNGLE_BOSS_H
#define JUNGLE_BOSS_H
#include "Employee.h"
#include <iostream>

class Boss : public Employee {
private:
    int numberOfEmployee;
public:
    // constructors
    Boss();
    Boss(std::string, std::string, Address, int, int, int, int, int);
    Boss(const Boss&);
    // print and input
    friend std::ostream& operator << (std::ostream&, Boss&);
    friend std::istream& operator >> (std::istream&, Boss&);
    // getter and setter
    void set_numberOfEmployee(int);
    int get_numberOfEmployee();
    // calcutateSalary = Hour Works * Salary Per Hour / (WorkDone / Work To Do)
    virtual int calculateSalary();
    Boss& operator = (const Boss&);
};


#endif //JUNGLE_BOSS_H
