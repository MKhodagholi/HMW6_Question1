#ifndef JUNGLE_BOSS_H
#define JUNGLE_BOSS_H
#include "Employee.h"
#include <iostream>

class Boss : Employee {
private:
    int numberOfEmployee;
public:
    // constructors
    Boss();
    Boss(int);
    Boss(const Boss&);
    // print and input
    friend std::ostream& operator << (std::ostream&, const Boss&);
    friend std::istream& operator >> (std::istream&, Boss&);
    // getter and setter
    void set_numberOfEmplyee(int);
    int get_numberOfEmplyee(int);
    // calcutateSalary = Hour Works * Salary Per Hour / (WorkDone / Work To Do)
    virtual int calculateSalary();
};


#endif //JUNGLE_BOSS_H
