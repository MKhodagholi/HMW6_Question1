#include "Employee.h"


Employee::Employee() : Person(), hourWork(0), salaryPerHour(0), workToDo(0), workDone(0) {}

Employee::Employee(std::string name, std::string id, Address address, int hourWork, int salaryPerHour, int workToDo, int workDone)
: Person(name, id, address) {
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

std::ostream& operator << (std::ostream &print, Employee &obj) {
    print << static_cast<Person &>(obj);
    print << "Hour Work: " << obj.hourWork;
    print << " Salary Per Hour: " << obj.salaryPerHour;
    print << " Work To Do: " << obj.workToDo;
    print << " Work Done: " << obj.workDone;
    print << std::endl;
    return print;
}

std::istream& operator >> (std::istream &input, Employee &obj) {

    input >> static_cast<Person &>(obj);
    input >> obj.hourWork;
    input >> obj.salaryPerHour;
    input >> obj.workToDo;
    input >> obj.workDone;
}

Employee& Employee::operator = (const Employee &obj) {
    Person::operator = (obj);
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
    int length = id.length();
    if (length != 10)
        return false;
    else {
        if (id[0] - '0' == 8) {
            if (id[1] - '0' <= 3 && id[1] - '0' >= 0)
                return false;
            else {
                if (id[2] != '*')
                    return false;
                for (int i = 5; i < 10; i++) {
                    if (id[i] >= 4 && id[i] <= 6)
                        return false;
                }
                return true;
            }
        }
        else if (id[0] - '0' == 9){
            if (id[1] - '0' >= 0 && id[1] - '0' < 10) {
                if (id[2] != '*')
                    return false;
                for (int i = 5; i < 10; i++) {
                    if (id[i] >= 4 && id[i] <= 6)
                        return false;
                }
                return true;
            }
            return false;
        }
        return false;
    }
}

int Employee::calculateSalary() {
    int salary = salaryPerHour * hourWork;
    salary *= float((float)(workDone) / float(workToDo));
    return salary;
}

float Employee::efficiency() {
    float randeman = float((float)(workDone) / float(workToDo)) / (float)hourWork * 100;
    return randeman;
}
