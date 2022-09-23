using namespace std;
#include <iostream>
#include <cstdlib>      // rand

/*
 * Allocate memory for the array N
 *
 * @param arr pointer to pointer of array
 * @param n size of array
 */
void allocMem(int **arr, int n);

/*
 * Free memory allocated for array
 *
 * @param arr pointer of array
 */
void freeMem(int *arr);

/*
 * Fill array with random numbers in range from 0 to 20
 *
 * @param arr pointer of array
 * @param n size of array
 */
void fillArr(int *arr, int n);

/*
 * Search and output sequences in ascending order
 *
 * @param arr pointer of array
 * @param n size of array
 */
void ascending(int *arr, int n);

/*
 * Search and output sequences in descending order
 *
 * @param arr pointer of array
 * @param n size of array
 */
void descending(int *arr, int n);

/*
 * Searching for and outputting alternating sequences
 *
 * @param arr pointer of array
 * @param n size of array
 */
void alternating(int *arr, int n);

/*
 * Search for the Max, Min, Arith avg and Med value
 *
 * @param arr pointer of array
 * @param n size of array
 */
void minMaxOth(int *arr, int n);

/*
 * Forming a cut of the array
 *
 * @param arr pointer of array
 * @param a start of cut index
 * @param b end of cut index
 */
void theCut(int *arr, int a, int b);

/*
 * Method of sorting by insertion
 *
 * @param arr pointer of array
 * @param n size of array
 */
void inserSort(int *arr, int n);

int main() {
    srand(time(0));
    int n;
    cout << "Enter the N value:\n> ";
    cin >> n;

    int *array;
    allocMem(&array, n);
    fillArr(array, n);

    cout << "\nGenerated array: " << endl;
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";

    int operation = 0;
    bool flag = true;
    while (flag){
        cout << "\n\nSelect operation:\n"
                "[1] Sequence Search \n"
                "[2] Max, Min, Arith avg and Med value\n"
                "[3] Shape the cut\n"
                "[4] Sorting by inserts\n"
                "[0] Exit" << endl;
        cout << "> ";
        cin >> operation;
        switch (operation){
            case 1: {
                int operation1 = 0;
                bool flag1 = true;
                while (flag1){
                    cout << "\nSelect operation:\n"
                            "[1] Ascending\n"
                            "[2] Descending\n"
                            "[3] Alternating\n"
                            "[O] Exit" << endl;
                    cout << "> ";
                    cin >> operation1;
                    switch (operation1){
                        case 1:
                            cout << "Selected Ascending...\n" << endl;
                            ascending(array, n);
                            break;
                        case 2:
                            cout << "Selected Descending...\n" << endl;
                            descending(array, n);
                            break;
                        case 3:
                            cout << "Selected Alternating...\n" << endl;
                            alternating(array, n);
                            break;
                        case 0:
                            flag1 = false;
                            break;
                    }
                }
                break;
            }
            case 2:
                minMaxOth(array, n);
                break;
            case 3:
                int a;
                int b;
                cout << "\nEnter the A value:\n> ";
                cin >> a;
                cout << "Enter the B value:\n> ";
                cin >> b;
                theCut(array, a, b);
                break;
            case 4:
                inserSort(array, n);
                break;
            case 0:
                flag = false;
                break;
        }
    }

    freeMem(array);

    return 0;
}

void allocMem(int **arr, int n){
    *arr = new int[n];
}

void fillArr(int *arr, int n){
    const int MIN = 0;
    const int MAX = 20;
    for (int i = 0; i < n; i++){
        arr[i] = MIN + (rand() % (MAX - MIN + 1));
    }
}

void ascending(int *arr, int n){
    int start = 0;
    int end = 0;
    for (int i = 0; i < n-2; i++){
        if ((arr[i] < arr[i+1]) && (arr[i+1] < arr[i+2])){
            start = i;
            while ((arr[i+1] > arr[i]) && ((i+1) < n))
                i++;
            end = i;
            if (end != 0){
                for (int k = start; k <= end; k++)
                    cout << arr[k] << " ";
                cout << endl;
            }
        }
    }
}

void descending(int *arr, int n){
    int start = 0;
    int end = 0;
    for (int i = 0; i < n-2; i++){
        if ((arr[i] > arr[i+1]) && (arr[i+1] > arr[i+2])){
            start = i;
            while ((arr[i+1] < arr[i]) && ((i+1) < n))
                i++;
            end = i;
            if (end != 0){
                for (int k = start; k <= end; k++)
                    cout << arr[k] << " ";
                cout << endl;
            }
        }
    }
}

void alternating(int *arr, int n){
    int start = 0;
    int end = 0;
    for (int i = 0; i < n-2; i++){
        if ((arr[i] > arr[i+1]) && (arr[i+1] < arr[i+2])){
            start = i;
            bool flag = true; // true - ожидаем меньшее значение, false - ожидаем большее
            while ((flag) && (arr[i] > arr[i+1])){
                i++;
                flag = false;
                if ((!flag) && (arr[i] < arr[i+1])){
                    i++;
                    flag = true;
                }
            }
            end = i;
            if (end != 0) {
                for (int k = start; k <= end; k++)
                    cout << arr[k] << " ";
                cout << endl;
            }
            i++;
        }
        if ((arr[i] < arr[i+1]) && (arr[i+1] > arr[i+2])){
            start = i;
            bool flag = false; // true - ожидаем меньшее значение, false - ожидаем большее
            while ((!flag) && (arr[i] < arr[i+1])){
                i++;
                flag = true;
                if ((flag) && (arr[i] > arr[i+1])){
                    i++;
                    flag = false;
                }
            }
            end = i;
            if (end != 0) {
                for (int k = start; k <= end; k++)
                    cout << arr[k] << " ";
                cout << endl;
            }
            i++;
        }
    }
}

void minMaxOth(int *arr, int n){

    // Создаем копию массива
    int *arrCopy = new int[n];
    for (int i = 0; i < n; i++)
        arrCopy[i] = arr[i];

    // Сортируем пузырьком
    int temp = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            if (arrCopy[j] > arrCopy[j+1]){
                temp = arrCopy[j];
                arrCopy[j] = arrCopy[j + 1];
                arrCopy[j+1] = temp;
            }
        }
    }

    // Находим медиану
    double median;
    if (n % 2 == 1)
        median = arrCopy[n/2];
    else
        median = (arrCopy[n/2-1] + arrCopy[n/2]) / 2;

    // Находим макс. и мин. значения
    int min = arr[0];
    int max = arr[0];
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] >= max){
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] <= min){
            min = arr[i];
            minIndex = i;
        }
    }

    // Находим среднее арифметическое
    int count = 0;
    for (int i = 0; i < n; i++)
        count += arr[i];
    double arAvg = count / n;

    cout << "\nMax value: "<< max << "\tIndex: " << maxIndex <<
    "\nMin value: " << min << "\tIndex: " << minIndex <<
    "\nArith avg: " << arAvg <<
    "\nMed value: " << median << endl;

    delete[] arrCopy;
}

void theCut(int *arr, int a, int b){
    // Создаем копию массива и формируем срез
    int length = b - a;

    int cut[length];
    int temp = 0;
    for (int i = a; i < b; i++){
        cut[temp] = arr[i];
        temp++;
    }

    cout << "\nThe Cut: " << endl;
    for (int i = 0; i < length; i++)
        cout << cut[i] << " ";
}

void inserSort(int *arr, int n){
    int newArr[n];

    for (int i = 0; i < n; i++)
        newArr[i] = arr[i];

    int temp;
    int prevIndex;
    for (int i = 1; i < n; i++){
        temp = newArr[i];
        prevIndex = i-1;
        while (prevIndex >= 0 && newArr[prevIndex] > temp){ // пока индекс не равен 0 и предыдущий элемент массива больше текущего
            newArr[prevIndex+1] = newArr[prevIndex];
            newArr[prevIndex] = temp;
            prevIndex--;
        }
    }

    cout << "\nSorted array: " << endl;
    for(int i = 0; i < n; i++)
        cout << newArr[i] << " ";
}

void freeMem(int *arr){
    delete[] arr;
}