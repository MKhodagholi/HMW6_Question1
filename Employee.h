#ifndef JUNGLE_EMPLOYEE_H
#define JUNGLE_EMPLOYEE_H
#include <iostream>
#include "Person.h"

class Employee : public Person {
    // class Boss will inherite from Employee
protected:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    // constructor
    Employee();
    // hourWork, SalaryPerHour ...
    Employee(std::string, std::string, Address, int, int, int, int);
    Employee(const Employee&);
    // print and input
    friend std::ostream& operator << (std::ostream&, Employee&);
    friend std::istream& operator >> (std::istream&, Employee&);
    Employee& operator = (const Employee&);
    // getter and setter
    void set_hourWork(int);
    void set_salaryPerHour(int);
    void set_workToDo(int);
    void set_workDone(int);
    int get_hourWork();
    int get_salaryPerHour();
    int get_workToDo();
    int get_workDone();
    // this function check if the id is valid or isn`t
    virtual bool validate();
    virtual int calculateSalary();
    // this function
    float efficiency();
};


#endif //JUNGLE_EMPLOYEE_H
