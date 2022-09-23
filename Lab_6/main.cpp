#include <iostream>
#include "classes.h"

using namespace std;


int main() {
    int operation = 0;
    bool flag = true;
    while (flag){
        cout << "\n\nSelect operation:\n"
                "[1] INT TYPE\n"
                "[2] DOUBLE TYPE\n"
                "[3] CHAR TYPE\n"
                "[4] STRING TYPE\n"
                "[0] Exit" << endl;
        cout << "> ";
        cin >> operation;
        switch (operation){
            case 1: {
                IntReader reader;
                cin >> reader;
                break;
            }
            case 2: {
                DoubleReader reader;
                cin >> reader;
                break;
            }
            case 3: {
                CharReader reader;
                cin >> reader;
                break;
            }
            case 4: {
                StrReader reader;
                cin >> reader;
                break;
            }
            case 0:
                flag = false;
                break;
        }
    }

    return 0;
}
