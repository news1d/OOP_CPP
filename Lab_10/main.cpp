#include <iostream>
#include <fstream>
#include "classes.h"
#include <string>
using namespace std::experimental::filesystem;
using namespace std;

void createDir(path curr_dir, string command);
void createFile(path curr_dir, string command);
void renameObject(path curr_dir, string command);
void deleteObject(path curr_dir, string command);
void moveObject(path curr_dir, string command);
void changeDir(path& curr_dir, string command);
void showTree(path curr_dir, string command);

int main() {

    path curr_dir = "C:\\Users\\news1d\\Desktop\\Folder_1";

    cout << "Current directory: " << curr_dir << endl;

    string command;
    cout << "> ";
    getline(cin, command);

    do{
        try{
            if (command.substr(0, 11) == "create_dir "){
                createDir(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command.substr(0, 12) == "create_file "){
                createFile(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command.substr(0, 7) == "rename "){
                renameObject(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command.substr(0, 7) == "delete "){
                deleteObject(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command.substr(0, 5) == "move "){
                moveObject(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command.substr(0, 11) == "change_dir "){
                changeDir(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }

            else if (command.substr(0, 10) == "show_tree "){
                showTree(curr_dir, command);
                cout << "> ";
                getline(cin, command);
            }
            else if (command == "Exit"){
                break;
            }
            else{
                cout << "Repeat input!\n> ";
                getline(cin, command);
            }
        }
        catch (filesystem_error& e)
        {
            cout << e.what() << "\n" << "> ";
            getline(cin, command);
        }
    } while (true);

    return 0;
}

void createDir(path curr_dir, string command){
    if (create_directory(curr_dir / command.substr(11, command.size() - 11)))
        cout << "Directory created!" << endl;
    else
        cout << "Failed!" << endl;
}

void createFile(path curr_dir, string command){
    string curr_dir_temp = (curr_dir / command.substr(12, command.size() - 12)).string();
    ofstream file(curr_dir_temp);
    file.close();
    cout << "File created!" << endl;
}

void renameObject(path curr_dir, string command){
    string new_name;
    if (exists(curr_dir / command.substr(7, command.size() - 7))){
        cout << "Enter a new name:\n> ";
        getline(cin, new_name);
        path old_path = curr_dir / command.substr(7, command.size() - 7);
        path new_path = curr_dir / new_name;
        rename(old_path, new_path);
        cout << "The object has been renamed successfully!" << endl;
    }
    else if (command.substr(7, command.size() - 7) == curr_dir.string().substr(curr_dir.string().find_last_of("/\\") + 1)){
        cout << "Enter a new name:\n> ";
        getline(cin, new_name);
        path new_path = curr_dir.string().substr(0, curr_dir.string().find_last_of("/\\") + 1) / new_name;
        rename(curr_dir, new_path);
        cout << "The object has been renamed successfully!" << endl;
    }
    else
        cout << "The object does not exist!" << endl;
}

void deleteObject(path curr_dir, string command){
    if (remove_all(curr_dir / command.substr(7, command.size() - 7)))
        cout << "Deleted!" << endl;
    else
        cout << "Failed!" << endl;
}

void moveObject(path curr_dir, string command){
    string target_dir = command.substr(command.find_last_of(' ') + 1);
    string object = command.substr(command.find_first_of(' ') + 1);
    object = object.substr(0, object.find_first_of(' '));

    if (exists(curr_dir / object) && exists(target_dir)){
        copy(curr_dir / object, target_dir / object, copy_options::overwrite_existing | copy_options::recursive);
        remove_all(curr_dir / object);
        cout << "Moved successfully!" << endl;
    }
    else
        cout << "The specified object or directory does not exist!" << endl;
}

void changeDir(path& curr_dir, string command){
    if (command.substr(11, command.size() - 11) == ".."){
        curr_dir = curr_dir.string().substr(0, curr_dir.string().find_last_of("/\\"));
        cout << "Current directory: " << curr_dir << endl;
    }
    else if (exists(curr_dir / command.substr(11, command.size() - 11)) && command.substr(11, command.size() - 11) != "."){
        curr_dir /= command.substr(11, command.size() - 11);
        cout << "Current directory: " << curr_dir << endl;
    }
    else
        cout << "The directory does not exist!" << endl;
}

void showTree(path curr_dir, string command){
    string folder = command.substr(10, command.size() - 10);
    path curr_dir_temp = curr_dir.string().substr(0, curr_dir.string().find(folder)) / folder;
    if (exists(curr_dir_temp)){
        Folder tree(curr_dir_temp);
        tree.show();
    }
    else
        cout << "The directory does not exist!" << endl;
}

