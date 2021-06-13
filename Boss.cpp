#include "Boss.h"

Boss::Boss() : numberOfEmployee(0) {}

Boss::Boss(std::string name, std::string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone, int n)
: Employee(name, id, address, hourWork, salaryPerHour, workToDo, workDone), numberOfEmployee(n) {}

Boss::Boss(const Boss &obj) : Employee(obj){
    numberOfEmployee = obj.numberOfEmployee;
}


std::ostream& operator << (std::ostream &print, const Boss &obj) {
    print << static_cast<Employee&>((Employee &) obj);
    print << "Hour-Work: " << obj.hourWork << " Hour-Work-To-Do: " << obj.workToDo;
    print << "Hour-Work-Done: " << obj.workDone << " Salary-Per-Hour: " << obj.salaryPerHour;
    print << " And Have " << obj.numberOfEmployee << " Employee";
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



