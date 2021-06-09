#include "Boss.h"

Boss::Boss() : numberOfEmployee(0) {}

Boss::Boss(int n) : numberOfEmployee(n) {}

Boss::Boss(const Boss &obj) {
    numberOfEmployee = obj.numberOfEmployee;
}

std::ostream& operator << (std::ostream &print, const Boss &obj) {
    print << "Have " << obj.numberOfEmployee << " Employee";
    return print;
}

std::istream& operator >> (std::istream &input, Boss &obj){
    std::cout << "Enter the number of Employee: ";
    input >> obj.numberOfEmployee;
    return input;
}

void Boss::set_numberOfEmplyee(int numberOfEmployee) {
    this->numberOfEmployee = numberOfEmployee;
}

int Boss::get_numberOfEmplyee() {
    return numberOfEmployee;
}

int Boss::calculateSalary() {
    int salary = salaryPerHour * hourWork;
    salary *= float((float)(workDone) / float(workToDo)) * 1.15;
    return salary;
}




