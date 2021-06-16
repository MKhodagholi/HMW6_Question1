#include <iostream>
#include "Jungle.h"
#include "WildAnimal.h"
#include "DomesticAnimal.h"
#include "Pet.h"

using namespace std;

int main() {
    int num;
    cout << "-----------------------------///| 2 Type Animal |///-----------------------------\n";
    cout << "Please enter the number of animals: ";
    cin >> num;
    Jungle jangal(num);
    for (int i = 0; i < num / 2; i++) {
        jangal.AddAnimal(new WildAnimal);
    }
    for (int i = num / 2; i < num; i++) {
        jangal.AddAnimal(new DomesticAnimal);
    }
    for (int i = 0; i < 1000; i++) {
        jangal.movement();
    }
    cout << jangal.getTotalFall();

    cout << "\n-----------------------------///| 3 Type Animal |///-----------------------------\n";

    cout << "Please enter the number of animals: ";
    cin >> num;
    Jungle jangal1(num);
    for (int i = 0; i < num / 3; i++) {
        jangal1.AddAnimal(new WildAnimal);
    }
    for (int i = num / 3; i < num * 2 / 3; i++) {
        jangal1.AddAnimal(new DomesticAnimal);
    }

    for (int i = num * 2 / 3; i < num; i++) {
        jangal1.AddAnimal(new Pet);
    }

    for (int i = 0; i < 1000; i++) {
        jangal.movement();
    }

    cout << jangal.getTotalFall();
    cout << endl;
    cout << "===================================================\n";
}
