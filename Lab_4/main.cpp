/*
 *
    1. Создайте классы Копье, Меч, Лук со свойствами определяющими урон, прочность, скорость атаки(или время на 1 атаку),
    редкость оружия(Редкость оружия влияет на урон, прочность и скорость атаки, для более редкого либо одна из характеристик будет близка к максимальной,
    либо все характеристики будут превышать средние, сама формула градация превышения определяется разработчиком).

    2. Создайте класс Оружие, который хранит объект оружия за указателем на пустоту и его тип.

    3. Создайте класс Магазин, который хранит в себе массив оружий.

    4. Заполните магазин случайным оружием, так, что бы в нем были все виды оружия, всех видов редкости в количестве соответствующих их редкости.

    5. Добавьте методы посещения магазина, в котором посетителю рассказывают о каждом оружии на его выбор,
    проводя опрос: какой вид оружия ему нужен и какой у него бюджет(влияет на редкость предлагаемых образцов),
    после проводится демонстрация оружия ввиду описания его характеристик сопровождающаяся связным текстом демонстрации.

    6. (Усложнение) Добавьте всем оружия особые навыки, количество и качество навыков должно зависеть от редкости оружия (или наоборот). При демонстрации покупателю оружия, навыки должны будут демонстрироваться так же как списком так и условно визуально(если навык это усиление атаки огнем, то например лезвие меча светится, все это пишется в обрамленное символом *)

 */


#include <iostream>
#include <vector>
#include "classes.h"
using namespace std;

/*
 * Generating a random rarity
 *
 * @return rarity random rarity
 */
int genRarity();

/*
 * Generating a random value based on rarity
 *
 * @param rarity
 * @return random value
 */
int randValue(int rarity);

/* Filling the vector
 *
 * @param object array object to fill
 */
void fillShop(Shop& object);

int main() {
    srand(time(0));

    Shop forge;
    fillShop(forge);
    forge.outPut();
    forge.visit();

    return 0;
}

int genRarity(){
    int rand_index = rand() % 100;
    int rarity;

    if (rand_index < 80){
        rarity = 1;
    }
    else if (rand_index < 95){
        rarity = 2;
    }
    else {
        rarity = 3;
    }
    return rarity;
}

int randValue(int rarity){
    return (10 + rand() % 5)*rarity;
}

void fillShop(Shop& object){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int rarity = genRarity();
            if (j == 0)
                rarity = 3;
            if ((j > 0) && (j < 3))
                rarity = 2;
            if (j > 2)
                rarity = 1;
            switch (i) {
                case 0: {
                    string type = "Spear";
                    Spear* spear_weapon = new Spear(randValue(rarity), randValue(rarity), randValue(rarity), rarity);
                    Weapon item = Weapon(spear_weapon, type);
                    object.weapons.push_back(item);
                    break;
                }
                case 1: {
                    string type = "Sword";
                    Sword* sword_weapon = new Sword(randValue(rarity), randValue(rarity), randValue(rarity), rarity);
                    Weapon item = Weapon(sword_weapon, type);
                    object.weapons.push_back(item);
                    break;
                }
                case 2: {
                    string type = "Bow";
                    Bow* bow_weapon = new Bow(randValue(rarity), randValue(rarity), randValue(rarity), rarity);
                    Weapon item = Weapon(bow_weapon, type);
                    object.weapons.push_back(item);
                    break;
                }
            }
        }
    }
}