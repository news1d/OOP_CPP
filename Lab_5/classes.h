#ifndef LAB_5_CLASSES_H
#define LAB_5_CLASSES_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include "windows.h"

enum Type{
    CAT,
    DOG,
    WOMBAT,
    RAT
};

class Animal{
protected:
    Type type;
    string name;
    int age;
    int tiredness;
    int satiety;
public:
    Animal(string name, int age, int satiety, int tiredness, Type type) :
    name(name), age(age), satiety(satiety), tiredness(tiredness), type(type){}

    /*
     * Get the type of animal
     *
     * @return type of snimsl
     */
    Type getType(){
        return type;
    }

    /*
     * Get the name of animal
     *
     * @return name of animal
     */
    string getName(){
        return name;
    }

    /*
     * Get the age of animal
     *
     * @return age of animal
     */
    int getAge(){
        return age;
    }

    /*
     * Get the tiredness of animal
     *
     * @return tiredness of animal
     */
    int getTiredness(){
        return tiredness;
    }

    /*
     * Get the satiety of animal
     *
     * @return satiety of animal
     */
    int getSatiety(){
        return satiety;
    }

    /*
     * Playing with an animal
     */
    void play(){}

    /*
     * Feeding the animal
     */
    void eat(){}

    /*
     * Send the animal to sleep
     */
    void sleep(){}

    /*
     * Checking for the need to eat
     *
     * @return True/False
     */
    bool checkEat(){
        if (satiety <= 30){
            cout << "\n" << name << " need to eat..." << endl;
            cout << "Going to feed " << name << "!" << endl;
            return 1;
        }
        else
            return 0;
    }

    /*
     * Checking for the need to sleep
     *
     * @return True/False
     */
    bool checkSleep(){
        if (tiredness <= 80){
            cout << "\n" << name << " need to rest..." << endl;
            cout << "Send " << name << " to sleep!"<< endl;
            return 1;
        }
        else
            return 0;
    }
};

class Cat: public Animal{
public:
    Cat(string name, int age, int satiety, int tiredness) :
    Animal(name, age, satiety, tiredness, CAT)
    {}

    void play(){
        if (tiredness < 10)
            tiredness = 0;
        else
            tiredness -= 10;

        if (satiety < 20)
            satiety = 0;
        else
            satiety -= 20;

        cout << "\n";
        for (int i = 0; i < 5; i++){
            cout << "Playing with " << name << "..." << endl;
            Sleep(1000);
        }
        cout << "\nPlayed enough!" << endl;
    }

    void eat(){
        satiety = 100;
        for (int i = 0; i < 5; i++){
            cout << "Feed " << name << "..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " fed!" << endl;
    }

    void sleep(){
        tiredness = 100;
        for (int i = 0; i < 5; i++){
            cout << name << " sleeping..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " woke up!" << endl;
    }
};

class Dog: public Animal{
public:
    Dog(string name, int age, int satiety, int tiredness) :
    Animal(name, age, satiety, tiredness, DOG)
    {}

    void play(){
        if (tiredness < 15)
            tiredness = 0;
        else
            tiredness -= 15;

        if (satiety < 20)
            satiety = 0;
        else
            satiety -= 20;

        cout << "\n";
        for (int i = 0; i < 5; i++){
            cout << "Playing with " << name << "..." << endl;
            Sleep(1000);
        }
        cout << "\nPlayed enough!" << endl;
    }

    void eat(){
        satiety = 100;
        for (int i = 0; i < 5; i++){
            cout << "Feed " << name << "..." << endl;
            Sleep(1500);
        }
        cout << "\n" << name << " fed!" << endl;
    }

    void sleep(){
        tiredness = 100;
        for (int i = 0; i < 5; i++){
            cout << name << " sleeping..." << endl;
            Sleep(1500);
        }
        cout << "\n" << name << " woke up!" << endl;
    }
};

class Wombat: public Animal{
public:
    Wombat(string name, int age, int satiety, int tiredness) :
    Animal(name, age, satiety, tiredness, WOMBAT)
    {}

    void play(){
        if (tiredness < 20)
            tiredness = 0;
        else
            tiredness -= 20;

        if (satiety < 20)
            satiety = 0;
        else
            satiety -= 20;

        cout << "\n";
        for (int i = 0; i < 5; i++){
            cout << "Playing with " << name << "..." << endl;
            Sleep(1500);
        }
        cout << "\nPlayed enough!" << endl;
    }

    void eat(){
        satiety = 100;
        for (int i = 0; i < 5; i++){
            cout << "Feed " << name << "..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " fed!" << endl;
    }

    void sleep(){
        tiredness = 100;
        for (int i = 0; i < 5; i++){
            cout << name << " sleeping..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " woke up!" << endl;
    }
};

class Rat: public Animal{
public:
    Rat(string name, int age, int satiety, int tiredness) :
    Animal(name, age, satiety, tiredness, RAT)
    {}

    void play(){
        if (tiredness < 5)
            tiredness = 0;
        else
            tiredness -= 5;

        if (satiety < 10)
            satiety = 0;
        else
            satiety -= 10;

        cout << "\n";
        for (int i = 0; i < 5; i++){
            cout << "Playing with " << name << "..." << endl;
            Sleep(1500);
        }
        cout << "\nPlayed enough!" << endl;
    }

    void eat(){
        satiety = 100;
        for (int i = 0; i < 5; i++){
            cout << "Feed " << name << "..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " fed!" << endl;
    }

    void sleep(){
        tiredness = 100;
        for (int i = 0; i < 5; i++){
            cout << name << " sleeping..." << endl;
            Sleep(1000);
        }
        cout << "\n" << name << " woke up!" << endl;
    }

};

class Zoo{
public:
    vector<Animal*> animals;

    /*
     * Checking for the need to sleep and eat
     */
    void check(){
        for (int i = 0; i < animals.size(); i++){
            if (animals[i]->checkEat()){
                switch (animals[i]->getType()){
                    case CAT:
                        ((Cat*)animals[i])->eat();
                        break;
                    case DOG:
                        ((Dog*)animals[i])->eat();
                        break;
                    case WOMBAT:
                        ((Wombat*)animals[i])->eat();
                        break;
                    case RAT:
                        ((Rat*)animals[i])->eat();
                        break;
                }
            }
            if (animals[i]->checkSleep()){
                switch (animals[i]->getType()){
                    case CAT:
                        ((Cat*)animals[i])->sleep();
                        break;
                    case DOG:
                        ((Dog*)animals[i])->sleep();
                        break;
                    case WOMBAT:
                        ((Wombat*)animals[i])->sleep();
                        break;
                    case RAT:
                        ((Rat*)animals[i])->sleep();
                        break;
                }
            }
        }
    }

    /*
     * Output an array of animals
     */
    void print(){
        for (int i = 0; i < animals.size(); i++){
            cout << i+1 << ". \t" << animals[i]->getName() << "\t\t" <<
            animals[i]->getAge() << "\t" <<
            animals[i]->getTiredness() << "\t" <<
            animals[i]->getSatiety() << "\t" << endl;
        }
    }
};


#endif //LAB_5_CLASSES_H
