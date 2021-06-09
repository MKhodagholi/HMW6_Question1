#include "Employee.h"


Employee::Employee() : Person(*this), hourWork(0), salaryPerHour(0), workToDo(0), workDone(0) {}

Employee::Employee(int hourWork, int salaryPerHour, int workToDo, int workDone) : Person(*this) {
    this->hourWork = hourWork;
    this->salaryPerHour = salaryPerHour;
    this->workToDo = workToDo;
    this->workDone = workDone;
}

Employee::Employee(const Employee &obj) : Person(obj) {
    hourWork = obj.hourWork;
    salaryPerHour = obj.salaryPerHour;
    workToDo = obj.workToDo;
    workDone = obj.workDone;
}

std::ostream& operator << (std::ostream &print, const Employee &obj) {
    print << "Hour Work: " << obj.hourWork;
    print << " Salary Per Hour: " << obj.salaryPerHour;
    print << " Work To Do: " << obj.workToDo;
    print << " Work Done: " << obj.workDone;
    return print;
}

std::istream& operator >> (std::istream &input, Employee &obj) {
    std::cout << "Enter the Hour Work: "; input >> obj.hourWork;
    std::cout << " Enter the Salary Per Hour: "; input >> obj.salaryPerHour;
    std::cout << " Enter the Work To Do: "; input >> obj.workToDo;
    std::cout << " Enter the Work Done: "; input >> obj.workDone;
}

Employee& Employee::operator = (const Employee &obj) {
    hourWork = obj.hourWork;
    salaryPerHour = obj.salaryPerHour;
    workToDo = obj.workToDo;
    workDone = obj.workDone;
    return *this;
}

void Employee::set_hourWork(int hourWork) {
    this->hourWork = hourWork;
}

void Employee::set_salaryPerHour(int salaryPerHour) {
    this->salaryPerHour = salaryPerHour;
}

void Employee::set_workToDo(int workToDo) {
    this->workToDo = workToDo;
}

void Employee::set_workDone(int workDone) {
    this->workDone = workDone;
}

int Employee::get_hourWork() {
    return hourWork;
}

int Employee::get_salaryPerHour() {
    return salaryPerHour;
}

int Employee::get_workToDo() {
    return workToDo;
}

int Employee::get_workDone() {
    return workDone;
}

bool Employee::validate() {

}

int Employee::calculateSalary() {
    int salary = salaryPerHour * hourWork;
    salary *= float((float)(workDone) / float(workToDo));
    return salary;
}

float Employee::efficiency() {
    float randeman = float((float)(workDone) / float(workToDo)) / (float)hourWork;
    return randeman;
}
