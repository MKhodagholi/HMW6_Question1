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
    Employee(int, int, int, int);
    Employee(const Employee&);
    friend std::ostream& operator << (std::ostream&, const Employee&);
    friend std::istream& operator >> (std::istream&, Employee&);
    Employee& operator = (const Employee&);
    void set_hourWork(int);
    void set_salaryPerHour(int);
    void set_workToDo(int);
    void set_workDone(int);
    int get_hourWork();
    int get_salaryPerHour();
    int get_workToDo();
    int get_workDone();
    virtual bool validate();
    int calculateSalary();
    float efficiency();
};


#endif //JUNGLE_EMPLOYEE_H
