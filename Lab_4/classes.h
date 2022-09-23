#ifndef LAB_4_CLASSES_H
#define LAB_4_CLASSES_H

using namespace std;
#include <string>
#include <vector>
#include <iomanip>



class Spear {
public:
    int damage;
    int durability;
    int speed;
    int rarity;

    /*
     * Assignment constructor
     */
    Spear(int damage, int durability, int speed, int rarity){
        this->damage = damage;
        this->durability = durability;
        this->speed = speed;
        this->rarity = rarity;
    };
};

class Sword {
public:
    int damage;
    int durability;
    int speed;
    int rarity;

    /*
     * Assignment constructor
     */
    Sword(int damage, int durability, int speed, int rarity){
        this->damage = damage;
        this->durability = durability;
        this->speed = speed;
        this->rarity = rarity;
    }
};

class Bow{
public:
    int damage;
    int durability;
    int speed;
    int rarity;

    /*
     * Assignment constructor
     */
    Bow(int damage, int durability, int speed, int rarity){
        this->damage = damage;
        this->durability = durability;
        this->speed = speed;
        this->rarity = rarity;
    };
};

class Weapon{
public:
    void* weapon_object;
    string type;

    /*
     * Assignment constructor
     */
    Weapon(void* weapon_object, string type){
        this->weapon_object = weapon_object;
        this->type = type;
    }

    /*
     * Enter all the contents of the Weapon class into the console
     */
    void weaponOutPut(){
        Bow* weapon_object = (Bow*)this->weapon_object;

        cout << "Type weapon: " + (this->type) << "\n"
             << "Damage: " << weapon_object->damage << "\n"
             << "Durability: " << weapon_object->durability << "\n"
             << "Attack speed: " << weapon_object->speed << "\n"
             << "Rarity: " << weapon_object->rarity << "\n"<< endl;

        //cout << this->type << "\t" << weapon_object->damage << "\t" << weapon_object->durability << "\t" << weapon_object->speed << "\t" << weapon_object->rarity << endl;
    }

    /*
     * Enter demonstrating weapons
     */
    void demOutPut(){
        Bow* weapon_object = (Bow*)this->weapon_object;

        cout << "\nWeapons of the type " + (this->type) << " have " << weapon_object->damage
             << " damage as well as " << weapon_object->durability << " durability and " << weapon_object->speed
             << " attack speed. \nRarity of Weapons " << weapon_object->rarity;
    }

    /*
     * Calculating the price of a weapon
     *
     * @return sum the price of weapons
     */
    int checkPrice(){
        Bow* weapon_object = (Bow*)this->weapon_object;
        int sum = (weapon_object->damage + weapon_object->durability + weapon_object->speed) * weapon_object->rarity;
        return sum;
    }
};

class Shop{
public:
    vector<Weapon> weapons;

    /*
     * Output an array of weapons
     */
    void outPut(){
        for (int i = 0; i < weapons.size(); i++)
            weapons[i].weaponOutPut();
    }

    /*
     * Choosing a weapon for demonstration
     */
    void visit(){
        int selected_weapon = 0;
        bool flag = true;
        while (flag){
            cout << "\n\nWhat kind of weapon do you need?\n"
                    "[1] SPEAR\n"
                    "[2] SWORD\n"
                    "[3] BOW\n"
                    "[0] Exit"<< endl;
            cout << "> ";
            cin >> selected_weapon;
            switch (selected_weapon){
                case 1:
                    selectWeapon(selected_weapon);
                    break;
                case 2:
                    selectWeapon(selected_weapon);
                    break;
                case 3:
                    selectWeapon(selected_weapon);
                    break;
                case 0:
                    flag = false;
                    break;
            }
        }
    }

    /*
     * Demonstrating weapons
     *
     * @param selected_weapons selected weapon category
     */
    void selectWeapon(int selected_weapon){
        int budget = 0;
        cout << "\nWhat is your budget?" << endl;
        cout << "> ";
        cin >> budget;

        string type_weapon;

        if (selected_weapon == 1)
            type_weapon = "Spear";
        else if (selected_weapon == 2)
            type_weapon = "Sword";
        else if (selected_weapon == 3)
            type_weapon = "Bow";

        int lot = 0;
        cout << "\nSelect a weapon to inspect:\n" << endl;
        int count = 0;
        for (int i = 0; i < weapons.size(); i++){
            if ((weapons[i].type == type_weapon) && (budget >= weapons[i].checkPrice())){
                cout << "---------------\n" << "Lot #" << i << endl;
                weapons[i].weaponOutPut();
                //cout << "Price: " << weapons[i].checkPrice() << endl;
                count++;
            }
        }
        if (count == 0){
            cout << "No matching weapons were found!" << endl;
        }
        else {
            cout << "Enter the lot number for inspection:" << endl;
            cout << "> ";
            cin >> lot;
            if ((weapons[lot].type == type_weapon) && (budget >= weapons[lot].checkPrice())){
                weapons[lot].demOutPut();
                cout << " and price is " << weapons[lot].checkPrice() << ".\n";
            }
            else{
                cout << "\n Invalid lot number" << endl;
            }
        }
    }


};

#endif //LAB_4_CLASSES_H