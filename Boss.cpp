#include "Boss.h"

Boss::Boss()  : Employee(), numberOfEmployee(0) {}

Boss::Boss(std::string name, std::string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone, int n)
: Employee(name, id, address, hourWork, salaryPerHour, workToDo, workDone), numberOfEmployee(n) {}

Boss::Boss(const Boss &obj) : Employee(obj){
    numberOfEmployee = obj.numberOfEmployee;
}


std::ostream& operator << (std::ostream &print, Boss &obj) {
    print << static_cast<Employee&>(obj);
    print << "Have " << obj.numberOfEmployee;
    print << std::endl;
    return print;
}

std::istream& operator >> (std::istream &input, Boss &obj){
    input >> static_cast<Employee&>(obj);
    input >> obj.numberOfEmployee;
    return input;
}

void Boss::set_numberOfEmployee(int numberOfEmployee) {
    this->numberOfEmployee = numberOfEmployee;
}

int Boss::get_numberOfEmployee() {
    return numberOfEmployee;
}

int Boss::calculateSalary() {
    int salary = salaryPerHour * hourWork;
    salary *= float((float)(workDone) / float(workToDo)) * 1.15;
    return salary;
}

Boss& Boss::operator = (const Boss &obj) {
    Employee::operator = (obj);
    numberOfEmployee = obj.numberOfEmployee;
    return *this;
}



