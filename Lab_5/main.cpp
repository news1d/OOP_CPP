#include <iostream>
#include <string>
#include <ctime>
#include "classes.h"
#include <vector>
using namespace std;

/*
 * Generating a random name
 *
 * @return name random name
 */
string genName();

/*
 * Generating a random value from 40 to 100
 *
 * @return random value
 */
int genValue();

/*
 * Generating a random age from 1 to 10
 *
 * @return age
 */
int genAge();

/* Filling the vector
 *
 * @param object array object to fill
 * @param count number of vector elements
 */
void fillZoo(Zoo& object, int count);

int main() {
    srand(time(0));
    Zoo contactZoo;

    fillZoo(contactZoo, 10);
    contactZoo.print();
    contactZoo.check();

    Cat jojo = Cat(genName(), genAge(), genValue(), genValue());
    jojo.play();

    return 0;
}

string genName() {
    string arr_name[15] = {"Andy", "Bozo", "Chopper", "Doby", "Epy", "Foster",
                   "Groovy", "Hoshi", "Izzy", "Juno", "Kodi", "Loki",
                   "Mino", "Nix", "Otis"};
    string name = arr_name[rand() % 15];
    return name;
}

int genValue(){
    return (60 + rand() % 40);
}

int genAge(){
    return (1 + rand() % 9);
}

void fillZoo(Zoo& object, int count){
    for (int i = 0; i < count; i++){
        int animal_type = (rand() % 4);

        switch (animal_type) {
            case 0: {
                object.animals.push_back(new Cat(genName(), genAge(), genValue(), genValue()));
                break;
            }
            case 1: {
                object.animals.push_back(new Dog(genName(), genAge(), genValue(), genValue()));
                break;
            }
            case 2: {
                object.animals.push_back(new Wombat(genName(), genAge(), genValue(), genValue()));
                break;
            }
            case 3: {
                object.animals.push_back(new Rat(genName(), genAge(), genValue(), genValue()));
                break;
            }
        }
    }
}
