#include <iostream>
#include <vector>
#include <algorithm>
#include "classes.h"
using namespace std;

const vector<string> NAME_ARR = {"Вадим", "Максим", "Егор", "Георгий", "Михаил",
                           "Сергей", "Глеб", "Александр", "Анатолий", "Андрей"};
const vector<string> SURNAME_ARR = {"Дмитриев", "Смирнов", "Киселев", "Степанов", "Волков",
                              "Петров", "Леонов", "Шаповалов", "Зубов", "Сидоров"};
const vector<string> PATRONYMIC_ARR = {"Александрович", "Глебович", "Вадимович", "Федорович", "Борисович",
                                 "Игоревич", "Кириллович", "Максимович", "Павлович", "Николаевич"};

/*
 * Generating a class object
 *
 * @return class object
 */
User genArgs();

/*
 * A slice of the array by age
 *
 * @param container vector for selection
 *
 * @return temp resulting vector
 */
vector<User> sliceAge(vector<User> &container);

/*
 * Counting the number of active users
 *
 * @param container vector for selection
 *
 * @return active_users number of active users
 */
int activeCount(vector<User> &container);

/*
 * Counting the number of inactive users
 *
 * @param container vector for selection
 *
 * @return inactive_users number of inactive users
 */
int inactiveCount(vector<User> &container);

/*
 * Search for namesakes
 *
 * @param container vector for selection
 */
void namesakes(vector<User> &container);

/*
 * Search for full namesakes
 *
 * @param container vector for selection
 */
void fullNamesakes(vector<User> &container);

/*
 * Search for users by name, surname and patronymic
 *
 * @param container vector for selection
 */
void searchUser(vector<User> &container);

/*
 * Output the vector
 *
 * @param container vector for selection
 */
void printContainer(vector<User> &container);

/*
 * Sorting the vector
 *
 * @param container vector for selection
 */
void sortUsers(vector<User> &container);

int main() {
    srand(time(0));
    vector<User> users(10);

    // Заполняем контейнер объектами класса
    generate(users.begin(), users.end(), genArgs);
    printContainer(users);

    // Cчитаем активных/неактивных пользователей
    int active_users = activeCount(users);
    int inactive_users = inactiveCount(users);
    cout << "Active users: " << active_users << "\nInactive users: " <<  inactive_users  <<  endl << endl;

    // Однофамильцы и полные тезки
    namesakes(users);
    fullNamesakes(users);

    // Срез контейнера по возрасту
    vector<User> sliced_container = sliceAge(users);
    printContainer(sliced_container);

    // Сортировка контейнера
    sortUsers(users);
    printContainer(users);

    // Поиск пользователя
    searchUser(users);

    return 0;
}

User genArgs(){
    string name = NAME_ARR[rand() % NAME_ARR.size()];
    string surname = SURNAME_ARR[rand() % SURNAME_ARR.size()];
    string patronymic = PATRONYMIC_ARR[rand() % PATRONYMIC_ARR.size()];
    bool activity = rand() % 2;
    int age = 16 + rand() % 40;

    string surname_temp = surname;
    string password = "";
    for (int i = 0; i < surname.size(); i++){
        for (auto it : TRANSLIT){
            if (surname_temp.substr(0, 2) == it.first){
                password += it.second;
                surname_temp.erase(0, 2);
            }
        }
    }

    password += to_string(age);

    return User(name, surname, patronymic, age, password, activity);
}

vector<User> sliceAge(vector<User> &container){
    vector<User> temp;
    int age;
    cout << "\nEnter the age: \n> ";
    cin >> age;
    copy_if(container.begin(), container.end(), back_inserter(temp), [age](User &p){
        return p.getAge() > age;
    });

    if (temp.size() == 0)
        cout << "No objects found!" << endl;

    return temp;
}

int activeCount(vector<User> &container){
    int active_users = count_if(container.begin(), container.end(), [](User &p){
        return p.getActivity() == 1;
    });
    return active_users;
}

int inactiveCount(vector<User> &container){
    int inactive_users = count_if(container.begin(), container.end(), [](User &p){
        return p.getActivity() == 0;
    });
    return inactive_users;
}

void namesakes(vector<User> &container){
    int namesakes_count = 0;
    bool flag = true;
    for (int i = 0; i < SURNAME_ARR.size(); i++){
        namesakes_count = 0;
        namesakes_count = count_if(container.begin(), container.end(), [i](User &p){
            return SURNAME_ARR[i] == p.getSurname();
        });
        if (namesakes_count > 1){
            flag = false;
            cout << SURNAME_ARR[i] << ": " << namesakes_count << endl;
        }
    }

    if (flag)
        cout << "No namesakes found!" << endl;
}

void fullNamesakes(vector<User> &container){
    int full_namesakes_count = 0;
    bool flag = true;
    for (int i = 0; i < SURNAME_ARR.size(); i++){
        for (int j = 0; j < NAME_ARR.size(); j++){
            for (int k = 0; k < PATRONYMIC_ARR.size(); k++){
                full_namesakes_count = 0;
                full_namesakes_count = count_if(container.begin(), container.end(), [&i, &j, &k](User &p){
                    return SURNAME_ARR[i] == p.getSurname() &&
                    NAME_ARR[j] == p.getName() &&
                    PATRONYMIC_ARR[k] == p.getPatronymic();
                });
                if (full_namesakes_count > 1){
                    flag = false;
                    cout << SURNAME_ARR[i] << " " << NAME_ARR[j] << " " <<
                    PATRONYMIC_ARR[k] << ": " << full_namesakes_count << endl;
                }
            }
        }
    }
    if (flag)
        cout << "No full namesakes found!" << endl;
}

void printContainer(vector<User> &container){
    for(int i = 0; i < container.size(); i++)
        cout << container[i] << endl;
}

void sortUsers(vector<User> &container){
    cout << "\nSelect no more than 3 items to sort: \n"
            "(1 - Surname, 2 - Name, 3 - Patronymic, "
            "4 - Age, 5 - Login, 6 - Password, 7 - Activity)" << endl;
    cout << "> ";

    string value;
    cin >> value;
    while (!(all_of(value.begin(), value.end(), ::isdigit)) || (value.size() > 3)){
        cout << "Select no more than 3 items!\n> ";
        cin.clear();
        fflush(stdin);
        cin >> value;
    }

    sort(container.begin(), container.end(), [value](User &left, User &right){
        for (int i = 0; i <= value.size(); i++){
            int operation = value[i] - 48;
            switch (operation){
                case 1:{
                    if (left.getSurname() != right.getSurname())
                        return left.getSurname() < right.getSurname();
                    break;
                }
                case 2:{
                    if (left.getName() != right.getName())
                        return left.getName() < right.getName();
                    break;
                }
                case 3:{
                    if (left.getPatronymic() != right.getPatronymic())
                        return left.getPatronymic() < right.getPatronymic();
                    break;
                }
                case 4:{
                    if (left.getAge() != right.getAge())
                        return left.getAge() < right.getAge();
                    break;
                }
                case 5:{
                    if (left.getLogin() != right.getLogin())
                        return left.getLogin() < right.getLogin();
                    break;
                }
                case 6:{
                    if (left.getPassword() != right.getPassword())
                        return left.getPassword() < right.getPassword();
                    break;
                }
                case 7:{
                    if (left.getActivity() != right.getActivity())
                        return left.getActivity() < right.getActivity();
                    break;
                }
            }
        }
    });
}

void searchUser(vector<User> &container){
    vector<User> temp;
    string surname;
    string name;
    string patronymic;
    cout << "\nEnter the surname: \n> ";
    cin >> surname;
    cout << "Enter the name: \n> ";
    cin >> name;
    cout << "Enter the patronymic: \n> ";
    cin >> patronymic;

    copy_if(container.begin(), container.end(), back_inserter(temp), [&surname, &name, &patronymic](User &p){
        return p.getSurname() == surname && p.getName() == name && p.getPatronymic() == patronymic;
    });

    if (temp.size() != 0){
        printContainer(temp);
    }
    else
        cout << "No objects found!" << endl;
}
