#include <iostream>
#include "Animal.h"

using namespace std;

int main() {
    int num;
    cout << "Please enter the number of animals: ";
    cin >> num;
    Animal array_animal[num];
    cout << array_animal[0].getX();

    return 0;
}
