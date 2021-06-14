#include "Company.h"
#include <fstream>

Company::Company() : budget(0){
    boss = new Boss();
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee();
    }
}

Company::Company(int budget, Boss *boss, Employee **employee) {
    this->budget = budget;
    this->boss = new Boss(*boss);
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee(employee[i][0]);
    }
}

Company::Company(const Company &obj) {
    budget = obj.budget;
    boss = new Boss;
    this->boss = obj.boss;
    employee = new Employee*[boss->get_numberOfEmployee()];
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        employee[i] = new Employee(employee[i][0]);
    }
}

Company::~Company() {
    delete boss;
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        delete employee[i];
    }
    delete [] employee;
}

std::ostream& operator << (std::ostream &print, const Company &obj) {
    print << "This Company has " << obj.boss->get_numberOfEmployee();
    print << " and " << obj.budget << " budget";
    return print;
}

std::istream& operator >> (std::istream &input, Company &obj) {
    std::cout << "Enter the Boss: ";
    Boss temp;
    input >> temp;
    obj.set_boss(&temp);
    std::cout << "Please enter the number of the employee: ";
    int num;
    input >> num;
    Employee employee;
    for (int i = 0; i < num; i++) {
        input >> employee;
    }
//    obj.boss->set_numberOfEmplyee(num);
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
        Employee temp = maxEfficiency();
        Employee *pTemp = &temp;
        Boss *result = dynamic_cast<Boss *>(pTemp);
        boss = result;
        double max_efficiency = employee[0][0].efficiency();
        int num_employee = 0;
        for (int i = 1; i < boss->get_numberOfEmployee(); i++) {
            if (employee[i][0].efficiency() >= max_efficiency) {
                max_efficiency = employee[i][0].efficiency();
                num_employee = i;
            }
        }
/*        employee[num_employee][0] = dynamic_cast<Employee *>(temp1);*/
    }
}

void Company::gift() {
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        if (employee[i][0].get_id()[0] == '8') {
            int hourWork = employee[i][0].get_hourWork() + 5;
            employee[i][0].set_hourWork(hourWork);
        }
    }
    int hourWork_maxEff = maxEfficiency().get_hourWork() + 10;
//    maxEfficiency().se;
}


void Company::payForService() {
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        if (employee[i][0].get_address().get_city() != "Tehran") {
            int hourWork = employee[i][0].get_hourWork() + 7;
            employee[i][0].set_hourWork(hourWork);
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
    for (int i = 0; i < boss->get_numberOfEmployee(); i++) {
        writer << employee[i][0].get_name() << "\t";
        writer << employee[i][0].get_id() << "\t";
        writer << employee[i][0].efficiency() << "\t";
        writer << employee[i][0].calculateSalary() << std::endl;
    }
}

/*
void sort_list_of_name(Company obj) {
    for (int i < 0; i < )
}*/
