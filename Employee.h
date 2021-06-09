#ifndef JUNGLE_EMPLOYEE_H
#define JUNGLE_EMPLOYEE_H
#include <iostream>
#include "Person.h"

class Employee : public Person {
private:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee();
    Employee(const Employee&);
    friend std::ostream& operator << (std::ostream&, const Employee&);
    friend std::istream& operator >> (std::istream&, const Employee&);
    Employee& operator = (const Employee&);
    void set_hourWork();
    void set_salaryPerHour();
    void set_workToDo();
    void set_workDone();
    int get_hourWork();
    int get_salaryPerHour();
    int get_workToDo();
    int get_workDone();
    virtual bool validate(const std::string&);
    int calculateSalary();
    int efficiency();
};


#endif //JUNGLE_EMPLOYEE_H
