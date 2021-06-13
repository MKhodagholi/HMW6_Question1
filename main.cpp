#include <iostream>
#include "Animal.h"
#include "Company.h"
using namespace std;

int main() {
/*    int num;
    cout << "Please enter the number of animals: ";
    cin >> num;
    Animal array_animal[num];
    cout << array_animal[0].getX();*/

    // hire employees
    Employee **employees = new Employee*[10];
/*    for (int i = 0; i < 10; i++) {
        employees[i] = new Employee[1];
    }*/
    // find the address of employees
    Address address[11] = {{"Iran", "Tehran", "Tafresh"},
                           {"Iran", "Karaj", "Shabnam"},
                           {"Iran", "Tehran", "ShahrakeDarya"},
                           {"Iran", "Esfahan", "33Pol"},
                           {"Iran", "Shiraz", "PoleHafez"},
                           {"Afghanistan", "Kabul", "18Gharbi"},
                           {"Afghanistan", "Kabul", "27Sharghi"},
                           {"Afghanistan", "Kabul", "12Shomali"},
                           {"Afghanistan", "Kabul", "13Shomali"},
                           {"Afghanistan", "Kabul", "14Shomali"},
                           {"Iran", "Tehran", "MehrAbad"}};

    // save the employees`s information
    employees[0] = new Employee("Mohammad", "99MHM20230", address[10], 100, 2000, 70, 30);


    // check the setter Functions
    employees[1][0].set_hourWork(120);
    employees[1][0].set_salaryPerHour(1000);
    employees[1][0].set_workToDo(80);
    employees[1][0].set_workDone(70);
    employees[1][0].set_name("Ali");
    employees[1][0].set_id("89ALI20231");

    employees[2][0]("Hosein", "84HON20232", address[1], )
    employees[2][0] = {170, 1500, 120, 120};
    employees[2][0].set_name();
    employees[2][0].set_id();

    employees[3][0] = {200, 4000, 200, 200};
    employees[3][0].set_name("Hasan");
    employees[3][0].set_id("87MHM20233");

    employees[4][0] = {50, 700, 50, 50};
    employees[4][0].set_name("Hamed");
    employees[4][0].set_id("99HMD20237");

    employees[5][0] = {135, 2000, 90, 30};
    employees[5][0].set_name("Taeb");
    employees[5][0].set_id("95TEB20238");

    employees[6][0] = {100, 5000, 120, 100};
    employees[6][0].set_name("Kabir");
    employees[6][0].set_id("96KBR20239");

    employees[7][0] = {150, 3000, 120, 100};
    employees[7][0].set_name("Ahmad");
    employees[7][0].set_id("95AHM20241");

    employees[8][0] = {180, 7000, 180, 180};
    employees[8][0].set_name("Teymor");
    employees[8][0].set_id("97TMR202342");

    employees[9][0] = {120, 4000, 100, 90};
    employees[9][0].set_name("Navid");
    employees[9][0].set_id("90NVD20243");

    // creat a boss
    Boss *boss = new Boss;
    boss->set_numberOfEmplyee(10);
    Address boss_address = {"Iran", "Tehran", "AmirAbad"};
    boss->set_address(boss_address);
    boss->set_name("Mr.Khodagholi");
    boss->set_id("84MKH00000");
    boss->set_hourWork(200);
    boss->set_salaryPerHour(10000);
    boss->set_workDone(200);
    boss->set_workToDo(200);
    // creat Company Pedare Khob
    Company pedareKhob;

    pedareKhob.set_boss(boss);
    pedareKhob.set_employee(employees);
    pedareKhob.set_budget(1000000000); // 1,000,000,000
    
    // let`s check the functions...
    Boss *pBoss = new Boss;
    pBoss = pedareKhob.get_boss();
    // lets check the function of pBoss
    cout << "name of boss is:(check the get_name func) " << pBoss->get_name() << endl;
    cout << "Id of boss is:(check the get_id func) " << pBoss->get_id() << endl;
    cout << "The address of boss is:(check the get_address func) " << pBoss->get_address() << endl;
    cout << "Number of Employee is:(check get_numberOfEmployee func) " << pBoss->get_numberOfEmplyee() << endl;
    cout << "Salary is: " << pBoss->calculateSalary() << endl;
    cout << "Efficiency is: " << pBoss->efficiency() << endl;
    cout << "Check the Validate id: " << pBoss->validate();

    // lets check the function of company...
    cout << pedareKhob.maxEfficiency().get_name() << " Has the Max Efficiency!";


    return 0;

}
