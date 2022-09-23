#ifndef LAB_3_BANKNOTE_H
#define LAB_3_BANKNOTE_H
#endif //LAB_3_BANKNOTE_H
//using namespace std;
#include <string>

enum Nominal{
    nom_1,
    nom_5 ,
    nom_10,
    nom_20,
    nom_50,
    nom_100,
    nom_1000
};

struct Banknote{
    string name;
    Nominal nominal;
    int course;
};

/*
 * Get the numerical value of the banknote denomination
 *
 * @param i element of the enum
 * @return result numerical value of the banknote denomination
 */
int nomValue(Nominal nominal){
    int result = 0;
    switch (nominal){
        case nom_1:
            result = 1;
            break;
        case nom_5:
            result = 5;
            break;
        case nom_10:
            result = 10;
            break;
        case nom_20:
            result = 20;
            break;
        case nom_50:
            result = 50;
            break;
        case nom_100:
            result = 100;
            break;
        case nom_1000:
            result = 1000;
            break;
    }
    return result;
}