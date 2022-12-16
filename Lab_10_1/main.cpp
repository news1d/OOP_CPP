#include <iostream>
#include "classes.h"

using namespace std;

int main() {

    Folder root("RootDir");
    FileTree catalog(root);

    cout << "Current directory: ";
    catalog.showName();
    cout << endl;

    string command;
    catalog.showName();
    cout << "> ";
    getline(cin, command);


    do{
        if (command.substr(0, 11) == "create_dir "){
            catalog.createDir(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command.substr(0, 12) == "create_file "){
            catalog.createFile(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command.substr(0, 7) == "rename "){
            catalog.renameObject(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command.substr(0, 7) == "delete "){
            catalog.deleteObject(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command.substr(0, 5) == "move "){
            catalog.moveObject(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command.substr(0, 11) == "change_dir "){
            catalog.changeDir(command);
            cout << "> ";
            getline(cin, command);
        }

        else if (command.substr(0, 10) == "show_tree "){
            catalog.showTree(command);
            catalog.showName();
            cout << "> ";
            getline(cin, command);
        }
        else if (command == "Exit")
            break;
        else {
            cout << "Repeat input!\n> ";
            getline(cin, command);
        }
    } while(true);

    return 0;
}
