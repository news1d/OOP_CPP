#ifndef LAB_7_CLASSES_H
#define LAB_7_CLASSES_H

using namespace std;
#include <vector>
#include <map>
#include <iomanip>
#include "windows.h"

class Book {
private:
    string name;
    int size;
    int age_limit;
    vector<double> scores;
    string genre;
    string author;
public:

    Book(string name, int size, int age_limit, string genre, string author) :
    name(name), size(size), age_limit(age_limit), genre(genre), author(author){}

    string getName(){
        return name;
    }

    int getSize(){
        return size;
    }

    int getLimit(){
        return age_limit;
    }

    string getGenre(){
        return genre;
    }

    string getAuthor(){
        return author;
    }

};

class Visitor {
private:
    int age;
    string pref_size;
    string pref_genre;
    int reading_speed;
public:

    Visitor(int age, string pref_size, string pref_genre, int reading_speed) :
    age(age), pref_size(pref_size), pref_genre(pref_genre), reading_speed(reading_speed){}

    int getAge(){
        return age;
    }

    string getPrefSize(){
        return pref_size;
    };

    string getPrefGenre(){
        return pref_genre;
    };

    int getReadingSpeed(){
        return reading_speed;
    }

    void reading(Book& object){
        for (int i = 0; i < object.getSize(); i++){
            cout << "Read page " << i + 1 << "..."<< endl;
            Sleep(reading_speed * 1000);
        }
        cout << "The book is read!" << endl;
    }
};

class Library{
private:
    vector<Book> catalog;
    int max_books = 30;
public:
    void createCatalog(){
        int arr_age_limit[5] = {0, 6, 12, 16, 18};
        string arr_genre[4] = {"Detective", "Romance", "Fantasy", "Fiction"};
        map<string, string> book_names = {{"Becoming The Elements", "Ricky Henry"}, {"Question The Angels", "Richard Jenkins"},
                                              {"Write About The Darkness", "Thomas Lopez"},{"Healing The Abyss", "Steven Hubbard"},
                                              {"Still Breathing In The Town", "Scott Turner"}, {"Punished By The Depths", "Carl Jenkins"},
                                              {"Battling In The Nation", "Billy Vargas"}, {"Healing The King", "Michael Ward"},
                                              {"Separated In The Fires", "Peter Davis"}, {"Battling In My Wife", "Jeffrey Green"},
                                              {"Pleasing The End", "Glen Soto"}, {"Separated By The Nation", "Bruce Hughes"},
                                              {"Learning From The Fog", "Alvin Watson"}, {"Death In The King", "John Norris"},
                                              {"Smiles In My Nightmares", "Richard Martin"}, {"Invited By My Family", "Kevin Andrews"},
                                              {"Pleasing The King", "Joseph Reese"}, {"Amusing The Ocean", "Thomas Moreno"},
                                              {"Blinded By The Fog", "Benjamin Oliver"}, {"Remember The Depths", "Phillip Williams"},
                                              {"Leading History", "Matthew Brown"}, {"Promises Of The Universe", "Ray Flores"},
                                              {"Searching In My Family", "Dennis Gross"}, {"Bathing In The Emperor", "Jerry Perez"},
                                              {"Going To The Commander", "Clarence Wheeler"}, {"Blacksmiths With Determination", "Jesse Tucker"},
                                              {"Bound To The Fires", "Walter Robinson"}, {"Faith Of Eternity", "James McLaughlin"},
                                              {"Bathing In Time", "Charles Barnett"}, {"Running In The Elements", "David Davidson"}};
        map<string, string> :: iterator it = book_names.begin();
        for (int i = 0; i < max_books; it++, i++){
            int book_size = 50 + rand() % 950;
            int genre_type = rand() % 4;
            int gen_age_limit = rand() % 5;
            catalog.push_back(Book(it->first, book_size, arr_age_limit[gen_age_limit], arr_genre[genre_type], it->second));
        }
    }

    Book seacrhBook(Visitor& object){
        bool flag = false;
        for (int i = 0; i < catalog.size(); i++){

            string temp_size = "";
            if (catalog[i].getSize() < 100)
                temp_size = "Small";
            else if (catalog[i].getSize() < 300)
                temp_size = "Medium";
            else
                temp_size = "Large";

            if (catalog[i].getLimit() <= object.getAge() && temp_size == object.getPrefSize() && catalog[i].getGenre() == object.getPrefGenre()){
                flag = true;
                cout << "\nThe book is found!" << endl;
                cout << left << setw(35) << catalog[i].getName() << setw(10) << catalog[i].getSize() <<
                setw(15) << catalog[i].getLimit() << setw(15) << catalog[i].getGenre() << catalog[i].getAuthor() << endl;
                return catalog[i];
                break;
            }
        }

        if (!flag){
            cout << "\nThe book was not found!" << endl;
            Book error("ERROR", 0, 0, "ERROR", "ERROR");
            return error;
        }
    }

    void searchNread(Visitor& object){
        Book found = seacrhBook(object);
        if (found.getName() != "ERROR"){
            object.reading(found);
        }
    }

    void print(){
        cout << left << setw(35) << "TITLE OF THE BOOK" << setw(10) << "SIZE" <<
        setw(15) << "AGE LIMIT" << setw(15) << "GENRE" << "AUTHOR" << endl;
        for (int i = 0; i < catalog.size(); i++)
            cout << left << i + 1 <<  setw(35) << catalog[i].getName() << setw(10) << catalog[i].getSize() <<
            setw(15) << catalog[i].getLimit() << setw(15) << catalog[i].getGenre() << catalog[i].getAuthor() << endl;
    }
};

#endif //LAB_7_CLASSES_H
