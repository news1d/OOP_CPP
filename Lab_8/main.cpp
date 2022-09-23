#include <iostream>
#include "classes.h"
using namespace std;


int main() {

    LinkedList<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_front(1);
    list.push_back(4);
    list.push_front(0);

    for (auto it : list)
        cout << it << " ";
    cout << endl;

    list.pop_front();
    list.pop_back();

    cout << "Checking if the list is empty: " << list.checkEmpty() << endl;
    cout << "List size: " << list.getLength() << endl;
    cout << "First element: " << list.getFrontElem() << endl;
    cout << "Last element: " << list.getBackElem() << endl;

    for (auto it : list)
        cout << it << " ";

    return 0;
}
