using namespace std;
#include <iostream>     // cout
#include <cstdlib>      // rand

const int A_LETTER = 97; // ASCII код английской буквы 'a'
const int Z_LETTER = 122; // ASCII код английской буквы 'z'
const int COUNT_LETTER = Z_LETTER - A_LETTER + 1; // считаем общее кол-во англ. букв
const int N = 10000; // задаем размер строки

/*
 * Генерирует строку из случайных английских букв
 *
 * @param str строка для заполнения.
 * @param size размер строки.
 */
void RandStr(string& str, int size);

int main() {
    srand(time(0));
    string str; // объявляем строку
    RandStr(str, N); // вызываю функцию, входе которой, строка заполняется случайными английскими символами

    int arr_count[COUNT_LETTER]; // объявляем массив с кол-вом ячеек равным кол-ву англ. букв
    // обнуляем каждую ячейку массива
    for (int i = 0; i < COUNT_LETTER; i++)
        arr_count[i] = 0;

    // считаем кол-во повторений каждой буквы
    for (int i = 0; i < N; i++)
        arr_count[int(str[i]) - A_LETTER]++;

    // выводим в консоль результат работы
    for (int i = 0; i < COUNT_LETTER; i++)
        cout << char(A_LETTER + i) << " - " << arr_count[i] << endl;

    return 0;
}

void RandStr(string& str, int size) {
    // заполняем строку случайными буквами из диапазона от 'a' до 'z'
    for (int i = 0; i < size; i++) {
        int rand_letter = A_LETTER + rand() % (Z_LETTER - A_LETTER + 1);
        str += (char)rand_letter;
    }
}
