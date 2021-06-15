#include "Company.h"
#include <fstream>
#include <cstring>

Company::Company() : budget(0){
    boss = new Boss();
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee();
    }
    gift();
    payForService();
    executionOfJustice();
}

Company::Company(int budget, Boss *bos, Employee **emplo) : budget(budget){
    boss = new Boss(*bos);
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee(emplo[i][0]);
    }
}

Company::Company(const Company &obj) {
    budget = obj.budget;
    boss = new Boss(*obj.boss);
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee(obj.employee[i][0]);
    }
}

Company::~Company() {
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        delete employee[i];
    }
    delete [] employee;
    delete boss;
}

std::ostream& operator << (std::ostream &print, Company &obj) {
    for (int i = 0; i < obj.boss->get_numberOfEmployee(); i++) {
        int num = i;
        std::string min_num = obj.employee[i][0].get_id().substr(0, 2);
        for (int j = i; j < obj.boss->get_numberOfEmployee(); j++) {
            if (min_num > obj.employee[j][0].get_id().substr(0, 2)) {
                min_num = obj.employee[j][0].get_id().substr(0, 2);
                num = j;
            }
            else if (min_num == obj.employee[j][0].get_id().substr(0, 2)) {
                if (obj.employee[j][0].get_name() < obj.employee[num][0].get_name())
                    num = j;
            }
        }
        Employee temp = obj.employee[i][0];
        obj.employee[i][0] = obj.employee[num][0];
        obj.employee[num][0] = temp;
        print << obj.employee[i][0];
        print << "------------------------------------------------\n";
    }
    return print;
}

std::istream& operator >> (std::istream &input, Company &obj) {
    input >> *obj.boss;
    std::cout << "Please enter the number of the employee: ";
    int num;
    input >> num;
    for (int i = 0; i < num; i++) {
        input >> obj.employee[i][0];
    }
    std::cout << "Enter the budget: ";
    input >> num;
    obj.set_budget(num);
}

void Company::set_budget(int budget) {
    this->budget = budget;
}

void Company::set_boss(Boss *boss) {
    this->boss = new Boss;
    this->boss = boss;
}

void Company::set_employee(Employee **employee) {
    this->employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        this->employee[i] = new Employee[1];
        this->employee[i][0] = employee[i][0];
    }
}

int Company::get_budget() {
    return budget;
}

Boss* Company::get_boss() {
    return boss;
}

Employee** Company::get_employee() {
    return employee;
}


Employee& Company::maxEfficiency() {
    double max_efficiency = employee[0][0].efficiency();
    int num_employee = 0;
    for (int i = 1; i < boss->get_numberOfEmployee(); i++) {
        if (employee[i][0].efficiency() >= max_efficiency) {
            max_efficiency = employee[i][0].efficiency();
            num_employee = i;
        }
    }

    return employee[num_employee][0];
}

double Company::averageEfficiency() {
    double sum = 0;
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        sum += employee[i][0].efficiency();
    }

    return sum / boss->get_numberOfEmployee();
}

// if the efficiency of the boss is less than 40 percent, that change with the employee who has the most efficiency
void Company::executionOfJustice() {
    if (boss->efficiency() < 0.4) {
        Boss *temp1 = boss;
        boss = dynamic_cast<Boss *>(&maxEfficiency());
        maxEfficiency() = *temp1;
    }
}

void Company::gift() {
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        if (employee[i][0].get_id()[0] == '8') {
            int hourWork = employee[i][0].get_hourWork() + 5;
            employee[i][0].set_hourWork(hourWork);
        }
    }
    maxEfficiency().set_hourWork((maxEfficiency().get_hourWork() + 10));
}

// if employee is uot of Tehran he get 7 hour for gift
void Company::payForService() {
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        if (employee[i][0].get_address().get_city() != "Tehran") {
            employee[i][0].set_hourWork((employee[i][0].get_hourWork() + 7));
        }
    }
}

bool Company::isEnoughBudget() {
    int sum_salary = 0;
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        sum_salary += employee[i][0].calculateSalary();
    }
    if (budget < sum_salary)
        return false;
    return true;
}

void Company::write_file() {
    std::ofstream writer("info_employee.txt");

    writer << *this;
    writer.close();
}
