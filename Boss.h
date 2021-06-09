#ifndef JUNGLE_BOSS_H
#define JUNGLE_BOSS_H
#include "Employee.h"
#include <iostream>

class Boss : Employee {
private:
    int numberOfEmployee;
public:
    Boss();
    Boss(int);
    Boss(const Boss&);
    friend std::ostream& operator << (std::ostream&, const Boss&);
    friend std::istream& operator >> (std::istream&, Boss&);
    void set_numberOfEmplyee(int);
    int get_numberOfEmplyee(int);
    virtual int calculateSalary();
};


#endif //JUNGLE_BOSS_H
