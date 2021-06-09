#include "Company.h"

Company::Company() : budget(0){
    boss = new Boss;
    employee = new Employee*[boss->get_numberOfEmplyee()];
    for (int i = 0; i < boss->get_numberOfEmplyee(); i++) {
        employee[i] = new Employee[1];
    }
}

Company::Company(int budget, Boss *boss, Employee **employee) {
    this->budget = budget;
    boss = new Boss;
    this->boss = boss;
    employee = new Employee*[boss->get_numberOfEmplyee()];
    this->employee = employee;
}

Company::Company(const Company &obj) {
    budget = obj.budget;
    boss = new Boss;
    this->boss = obj.boss;
    employee = new Employee*[boss->get_numberOfEmplyee()];
    this->employee = obj.employee;
}

Company::~Company() {
    delete boss;
    for (int i = 0; i < boss->get_numberOfEmplyee(); i++) {
        delete [] employee[i];
    }
    delete [] employee;
}
