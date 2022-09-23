/*
 *
    1. Будет реализована структура "Банкнота" с полями:
            Наименование
            Номинал (из списка заданного перечислением 1, 5, 10, 20, 50, 100, 1000)
            Курс к рублю
    2. Создан массив хранящий N банкнот, который будем называть кошельком, кол-во считывается с клавиатуры.
    3. Заполнено или сгенерировано N банкнот.
    4. Написаны функции которые:
            Подсчитывают общую сумму хранимую в кошельке.
            Формирует срез банкнот с номиналом больше выбранного пользователя и выводит их количество.
            Выводит состав кошелька отсортированный по валютам и номиналу с количеством каждой существующей банкноты.
            Конвертирует все банкноты в рубль через курс набирая итог банкнотами с максимальным номиналом, в случае неровной суммы округляем в большую сторону.

 */
using namespace std;

#include <iostream>
#include "banknote.h"
#include <cstdlib>      // rand
#include <fstream>
#include <algorithm>
#include <vector>

/*
 * Filling in the wallet vector
 *
 * @param wallet array to fill
 */
void fillWallet(vector<Banknote>& wallet);

/*
 * Reads line from file of given number
 *
 * @param filename name of file
 * @param line number of line
 * @return line
 */
string readLine(string filename, int line);

/*
 * Output the full structure
 *
 * @param array with banknotes
 */
void printWallet(vector<Banknote>& wallet);

/*
 * Count the number of lines in the file
 *
 * @param filename name of file
 * @return result number of lines in the file
 */
int countLines(string filename);

/*
 * Counting the amount of money in your wallet
 *
 * @param array with banknotes
 */
void totalAmount(vector<Banknote>& wallet);

/*
 * Finding banknotes above a certain denomination
 *
 * @param array with banknotes
 * @param nominal certain denominations of banknotes
 */
void theCut(vector<Banknote>& wallet, int nominal);

/*
 * Convert all banknotes to rubles
 *
 * @param array with banknotes
 */
void convert(vector<Banknote>& wallet);

/*
 * Sort the array and output the number of different banknotes
 *
 * @param array with banknotes
 */
void sortWallet(vector<Banknote>& wallet);

/*
 * Compramator sorting array
 *
 * @param left i element of the array
 * @param right i+1 element of the array
 */
bool sorter(Banknote const& left, Banknote const& right);

int main() {
    srand(time(0));

    int n = 0;
    cout << "Enter the N value:\n> ";
    cin >> n;

    vector<Banknote> wallet(n);
    fillWallet(wallet);
    printWallet(wallet);

    int operation = 0;
    bool flag = true;
    while (flag){
        cout << "\n\nSelect operation:\n"
                "[1] Total amount\n"
                "[2] Shape the cut\n"
                "[3] Sorting\n"
                "[4] Convert to rubles\n"
                "[0] Exit" << endl;
        cout << "> ";
        cin >> operation;
        switch (operation){
            case 1:
                totalAmount(wallet);
                break;
            case 2: {
                int nominal = 0;
                cout << "\nEnter the nominal value of the banknote: \n" << "> ";
                cin >> nominal;
                if ((nominal == 1) || (nominal == 5) || (nominal == 10) || (nominal == 20)
                    || (nominal == 50) || (nominal == 100) || (nominal == 1000)){
                    theCut(wallet, nominal);
                    break;
                }
                else{
                    cout << "\nERROR - Wrong number entered!";
                    break;
                }
            }
            case 3:
                sortWallet(wallet);
                break;
            case 4:
                convert(wallet);
                break;
            case 0:
                flag = false;
                break;
        }
    }

    return 0;
}

int countLines(string filename) {
    ifstream f(filename);
    if (!f) return -1;
    int count = 0;
    string s;
    while (!f.eof()) {
        f >> s;
        count++;
    }
    return count;
}

string readLine(string filename, int line){
    ifstream f(filename);
    string result;
    for (int i = 0; i < line; i++)
        f >> result;
    return result;
}

void fillWallet(vector<Banknote>& wallet) {
    string banknoteFile = "banknote.txt";
    string courseFile = "course.txt";
    int banknote_count = countLines(banknoteFile);
    int line = 0;

    for (int i = 0; i < wallet.size(); i++){
        line = 1 + (rand() % banknote_count);
        string name = readLine(banknoteFile, line);
        Nominal nominal = Nominal(rand() % nom_1000 + 1);
        int course = stoi(readLine(courseFile, line));

        wallet[i].name = name;
        wallet[i].nominal = nominal;
        wallet[i].course = course;
    }
}

void printWallet(vector<Banknote>& wallet) {
    for (int i = 0; i < wallet.size(); i++) {
        cout << "\n" << i + 1 << ". " << wallet[i].name << "\t" << nomValue(wallet[i].nominal) << "\t" << wallet[i].course;
    }
}

void totalAmount(vector<Banknote>& wallet){
    int sum = 0;
    for (int i = 0; i < wallet.size(); i++)
        sum += nomValue(wallet[i].nominal) * wallet[i].course;
    cout << "\nTotal amount in the wallet: " << sum << " RUB";
}

void theCut(vector<Banknote>& wallet, int nominal){
    vector<Banknote> cut;
    int count = 0;
    for (int i = 0; i < wallet.size(); i++){
        if (nomValue(wallet[i].nominal) > nominal)
            count++;
    }

    for (int i = 0; i < wallet.size(); i++){
        if (nomValue(wallet[i].nominal) > nominal)
            cut.push_back(wallet[i]);
    }

    cout << "\nThe Cut: ";
    printWallet(cut);
    cout << "\n\nTotal banknotes: " << count;

}

void convert(vector<Banknote>& wallet){
    vector<Banknote> newWallet;

    int sum = 0;
    for (int i = 0; i < wallet.size(); i++)
        sum += nomValue(wallet[i].nominal) * wallet[i].course;

    cout << "\nTotal sum: " << sum << endl;

    for (int i = nom_1000; i>=0; i--){
        while (sum >= nomValue(Nominal(i))){
            sum -= nomValue(Nominal(i));
            Banknote temp;
            temp.name = "RUB";
            temp.nominal = Nominal(i);
            temp.course = 1;
            newWallet.push_back(temp);
        }
    }

    printWallet(newWallet);
}

void sortWallet(vector<Banknote>& wallet){
    vector<Banknote> sorted;

    for (int i = 0; i < wallet.size(); i++)
        sorted.push_back(wallet[i]);

    sort(sorted.begin(), sorted.end(), &sorter);

    cout << "\n   NAME\tNOMINAL\tAMOUNT" << endl;
    for (int i = 0; i < sorted.size(); i++){
        int count = 1;
        for (int j = i+1; j < sorted.size() - 1; j++){
            if ((sorted[i].name == sorted[j].name) && (sorted[i].nominal == sorted[j].nominal)){
                sorted.erase(sorted.begin() + j);
                count++;
            }
        }
        cout << i+1 << ". " << sorted[i].name << "\t" << nomValue(sorted[i].nominal) << "\t" << count << endl;
    }
}

bool sorter(Banknote const& left, Banknote const& right) {
    if (left.name != right.name)
        return left.name < right.name;
    if (left.nominal != right.nominal)
        return left.nominal < right.nominal;
}