#ifndef LAB_6_CLASSES_H
#define LAB_6_CLASSES_H
using namespace std;
#include <string>
#include <istream>
#include <iostream>
#include <algorithm>
#include <cstring>

class Reader {
public:
    virtual void read(istream&) = 0;

};
istream& operator>>(istream& in, Reader* r){
    r->read(in);
    return in;
}
istream& operator>>(istream& in, Reader& r){
    return in >> &r;
}


class Validator{
public:
    virtual bool addValidator() = 0;
};


class IntReader: public Reader{
protected:
    int intData;
public:

    void read(istream&){

        string line;
        cout << "Enter a value with the int type: " << endl;

        cin >> line;
        while (!(all_of(line.begin(), line.end(), ::isdigit)) && !cin.eof()){
            cout << "Invalid type! Repeat the input: " << endl;
            cin.clear();                //сбрасываем коматозное состояние cin
            fflush(stdin);              //очищаем поток ввода
            cin >> line;
        }

        if (cin.eof()){
            cout << "Program is over!" << endl;
            exit(0);
        }
        else
            intData = stoi(line);
            cout << "Value = " << intData << endl;
    }

};



class DoubleReader: public Reader{
private:
    double doubleData;
public:

    void read(istream&){

        cout << "Enter a value with the double type: " << endl;

        while (!(cin >> doubleData) && !cin.eof()){
            cout << "Invalid type! Repeat the input: " << endl;
            cin.clear();
            fflush(stdin);
        }

        if (cin.eof()){
            cout << "Program is over!" << endl;
            exit(0);
        }
        else
            cout << "Value = " << showpoint << doubleData << endl;
    }
};

class StrReader: public Reader{
private:
    string stringData;
public:

    void read(istream&){

        cout << "Enter a value with the string type: " << endl;

        while (!(cin >> stringData) && !cin.eof()){
            cout << "Invalid type! Repeat the input: " << endl;
            cin.clear();
            fflush(stdin);
        }

        if (cin.eof()){
            cout << "Program is over!" << endl;
            exit(0);
        }
        else
            cout << "Value = " << stringData << endl;
    }
};



class CharReader: public Reader{
private:
    char charData;
public:
    void read(istream&){

        string line;
        cout << "Enter a value with the char type: " << endl;

        cin >> line;
        while (!cin.eof() && (line.length() != 1)){
            if (line.length() != 1)
                cout << "Enter one character!" << endl;
            else
                cout << "Invalid type! Repeat the input: " << endl;
            cin.clear();
            fflush(stdin);
            cin >> line;
        }

        if (cin.eof()){
            cout << "Program is over!" << endl;
            exit(0);
        }
        else{
            charData = line[0];
            cout << "Value = " << charData << endl;
        }
    }
};

#endif //LAB_6_CLASSES_H
