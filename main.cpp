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
    // find the address of employees
    Address address[10] = {{"Iran", "Tehran", "Tafresh"},
                           {"Iran", "Karaj", "Shabnam"},
                           {"Iran", "Tehran", "ShahrakeDarya"},
                           {"Iran", "Esfahan", "33Pol"},
                           {"Iran", "Shiraz", "PoleHafez"},
                           {"Afghanistan", "Kabul", "18Gharbi"},
                           {"Afghanistan", "Kabul", "27Sharghi"},
                           {"Afghanistan", "Kabul", "12Shomali"},
                           {"Afghanistan", "Kabul", "13Shomali"},
                           {"Afghanistan", "Kabul", "14Shomali"}};

    // save the employees`s information
    employees[0] = new Employee("Mohammad", "99*HM20230", address[0], 100, 2000, 70, 30);
    employees[1] = new Employee("Ali", "89*LI20231", address[1], 120, 1000, 80, 70);
    employees[2] = new Employee("Hosein", "84*ON20232", address[2], 170, 1500, 120, 120);
    employees[3] = new Employee("Hasan", "87*HM20233", address[3], 200, 4000, 200, 200);
    employees[4] = new Employee("Hamed", "99*MD20237", address[4], 50, 700, 50, 50);
    employees[5] = new Employee("Taeb", "95*EB20238" , address[5], 135, 2000, 90, 30);
    employees[6] = new Employee("Kabir", "96*BR20239", address[6], 100, 5000, 120, 100);
    employees[7] = new Employee("Ahmad", "95*HM20271", address[7], 150, 3000, 120, 100);
    employees[8] = new Employee("Teymor", "97*MR20272", address[8], 180, 7000, 180, 180);
    employees[9] = new Employee("Navid", "90*VD20273", address[9], 120, 4000, 100, 90);
    // creat a boss
    Address boss_address = {"Iran", "Tehran", "AmirAbad"};

    Boss *boss = new Boss("Mr.Khodagholi", "84MKH11111", boss_address, 200, 10000, 200, 200, 10);

    // creat Company Pedare Khob
    Company pedareKhob(1000000000, boss, employees); // 1,000,000,000

    cout << pedareKhob;

    pedareKhob.write_file();


    return 0;
}
