#ifndef LAB_9_CLASSES_H
#define LAB_9_CLASSES_H

#include <string>
#include <map>
using namespace std;

const map<string, string> TRANSLIT = {{"А", "A"}, {"а", "a"}, {"Б", "B"}, {"б", "b"}, {"В", "V"}, {"в", "v"},
                                      {"Г", "G"}, {"г", "g"}, {"Д", "D"}, {"д", "d"}, {"Е", "E"}, {"е", "e"},
                                      {"Ё", "Yo"}, {"ё", "yo"}, {"Ж", "Zh"}, {"ж", "zh"}, {"З", "Z"}, {"з", "z"},
                                      {"И", "I"}, {"и", "i"}, {"Й", "Y"}, {"й", "y"}, {"К", "K"}, {"к", "k"},
                                      {"Л", "L"}, {"л", "l"}, {"М", "M"}, {"м", "m"}, {"Н", "N"}, {"н", "n"},
                                      {"О", "O"}, {"о", "o"}, {"П", "P"}, {"п", "p"}, {"Р", "R"}, {"р", "r"},
                                      {"С", "S"}, {"с", "s"}, {"Т", "T"}, {"т", "t"}, {"У", "U"}, {"у", "u"},
                                      {"Ф", "F"}, {"ф", "f"}, {"Х", "Kh"}, {"х", "kh"}, {"Ц", "Ts"}, {"ц", "ts"},
                                      {"Ч", "Ch"}, {"ч", "ch"}, {"Ш", "Sh"}, {"ш", "sh"}, {"Щ", "Shch"}, {"щ", "shch"},
                                      {"ъ", "``"}, {"ы", "y"}, {"ь", "`"}, {"Э", "E"}, {"э", "e"}, {"Ю", "Yu"},
                                      {"ю", "yu"}, {"Я", "Ya"}, {"я", "ya"}};

class User{
private:
    string name;
    string surname;
    string patronymic;
    int age;
    string login;
    string password;
    bool activity;
public:
    /*
     * Overloading << operator
     *
     * @param stream
     * @param object of the User class
     *
     * @return stream
     */
    friend ostream &operator<<(ostream &stream, User object);

    /*
     * User constructor
     */
    User(){}

    /*
     * User constructor
     *
     * @param name user name
     * @param surname user surname
     * @param patronymic user patronymic
     * @param age user age
     * @param password user password
     * @param activity user acitivity
     */
    User(string name, string surname, string patronymic, int age, string password, bool activity){
        this->name = name;
        this->surname = surname;
        this->patronymic = patronymic;
        this->age = age;
        genLogin(name, surname, patronymic);
        this->password = password;
        this->activity = activity;
    }

    /*
     * Getting user age
     *
     * @return age user age
     */
    int getAge(){
        return age;
    }

    /*
     * Getting user activity
     *
     * @return activity user activity
     */
    bool getActivity(){
        return activity;
    }

    /*
     * Getting user surname
     *
     * @return surname user surname
     */
    string getSurname(){
        return surname;
    }

    /*
     * Getting user name
     *
     * @return name user name
     */
    string getName(){
        return name;
    }

    /*
     * Getting user patronymic
     *
     * @return patronymic user patronymic
     */
    string getPatronymic(){
        return patronymic;
    }

    /*
     * Getting user login
     *
     * @return login user login
     */
    string getLogin(){
        return login;
    }

    /*
     * Getting user password
     *
     * @return password user password
     */
    string getPassword(){
        return password;
    }

    /*
     * Generating a login
     *
     * @param name user name
     * @param surname user surname
     * @param patronymic user patronymic
     */
    void genLogin(string name, string surname, string patronymic){
        string surname_translit = "";
        string patronymic_temp = "";
        for (auto it : TRANSLIT){
            if (name.substr(0, 2) == it.first)
                login = it.second + ".";
            if (patronymic.substr(0, 2) == it.first)
                patronymic_temp = it.second + ".";
        }

        login += patronymic_temp;

        string surname_temp = surname;
        for (int i = 0; i < surname.size(); i++){
            for (auto it : TRANSLIT){
                if (surname_temp.substr(0, 2) == it.first){
                    surname_translit += it.second;
                    surname_temp.erase(0, 2);
                }
            }
        }

        login += surname_translit;
    }
};

ostream &operator<<(ostream &stream, User object){
    stream << object.surname << " " << object.name << " " << object.patronymic << "\nAge: " << object.age <<
           "\nLogin: " << object.login << "\nPassword: " << object.password << "\nActivity: " <<
           object.activity << "\n------------------------------------------------------";
    return stream;
}
#endif //LAB_9_CLASSES_H
