#ifndef LAB_10_1_CLASSES_H
#define LAB_10_1_CLASSES_H
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <experimental/filesystem>

using namespace std::experimental::filesystem;
using namespace std;

class Folder{
public:
    class File{
    private:
        string name;
        string description;
        Folder *folder;
    public:
        /*
         * File constructir
         *
         * @param name file name
         * @param *folder pointer to a folder
         */
        File(string name, Folder *folder){
            this->name = name;
            this->folder = folder;
        }

        /*
         * Getting file name
         *
         * @return name file name
         */
        string getName(){
            return name;
        }

        /*
         * Setting file name
         */
        void setName(string new_name){
            name = new_name;
        }
    };
private:
    string name;
    vector<File> files;
    vector<Folder> folders;
public:

    /*
     * Folder constructor
     *
     * @param name folder name
     */
    Folder(string name) : name(name){}

    /*
     * Folder constructor
     */
    Folder() {}

    /*
     * Getting a folder vector
     *
     * @return folders folder vector
     */
    vector<Folder>& getFolders(){
        return folders;
    }

    /*
     * Getting a file vector
     *
     * @return files file vector
     */
    vector<File>& getFiles(){
        return files;
    }

    /*
     * Getting folder name
     *
     * @return name folder name
     */
    string getName(){
        return name;
    }

    /*
     * Setting folder name
     */
    void setName(string set_name){
        name = set_name;
    }
};

class FileTree: public Folder{
private:
    vector <Folder*> catalog;
public:
    /*
     * FileTree constructor
     *
     * @param obj object of the folder class
     */
    FileTree(Folder obj){
        catalog.push_back(&obj);
    }

    /*
     * Output the names of all folders stored in the catalog vector
     */
    void showName(){
        for(auto it : catalog)
            cout << it->getName() << "\\";
    }

    /*
     * Creating a new object of the folder class
     */
    void createDir(string command){
        string dir_name = command.substr(11, command.size() - 11);
        bool valid_name = true;
        for(int i = 0; i < dir_name.size(); i++){
            if (dir_name[i] == '\\' || dir_name[i] == '/' ||
                dir_name[i] == ':' || dir_name[i] == '*' ||
                dir_name[i] == '?' || dir_name[i] == '"' ||
                dir_name[i] == '<' || dir_name[i] == '>' ||
                dir_name[i] == '|'){
                valid_name = false;
                cout << "The name must not contain the following characters: \\ / : * ? \" < > |" << endl;
            }
        }
        if (find_if(catalog.back()->getFolders().begin(), catalog.back()->getFolders().end(), [dir_name](Folder &p){
            return p.getName() == dir_name;
        }) == catalog.back()->getFolders().end() && valid_name){
            Folder obj(dir_name);
            catalog.back()->getFolders().push_back(obj);
            cout << "Directory created!" << endl;
        }
        else if (valid_name)
            cout << "The directory already exists!" << endl;
    }

    /*
     * Creating a new object of the file class
     */
    void createFile(string command){
        path file_name = command.substr(12, command.size() - 12);
        bool valid_name = true;
        for(int i = 0; i < file_name.string().size(); i++){
            if (file_name.string()[i] == '\\' || file_name.string()[i] == '/' ||
                    file_name.string()[i] == ':' || file_name.string()[i] == '*' ||
                    file_name.string()[i] == '?' || file_name.string()[i] == '"' ||
                    file_name.string()[i] == '<' || file_name.string()[i] == '>' ||
                    file_name.string()[i] == '|'){
                valid_name = false;
                cout << "The name must not contain the following characters: \\ / : * ? \" < > |" << endl;
            }
        }
        if (file_name.extension() == "" && valid_name)
            cout << "Enter the file extension!" << endl;
        else if (find_if(catalog.back()->getFiles().begin(), catalog.back()->getFiles().end(), [file_name](File &p){
            return p.getName() == file_name;
        }) == catalog.back()->getFiles().end() && valid_name){
            File obj(file_name.string(), catalog.back());
            catalog.back()->getFiles().push_back(obj);
            cout << "File created!" << endl;
        }
        else if (valid_name)
            cout << "The file already exists!" << endl;
    }

    /*
     * Renaming the object
     */
    void renameObject(string command){
        string new_name;
        path object_name = command.substr(7, command.size() - 7);
        auto folder_it = find_if(catalog.back()->getFolders().begin(), catalog.back()->getFolders().end(), [object_name](Folder &p){
            return p.getName() == object_name;
        });
        auto file_it = find_if(catalog.back()->getFiles().begin(), catalog.back()->getFiles().end(), [object_name](File &p){
            return p.getName() == object_name;
        });
        if (object_name.extension() == "" && folder_it != catalog.back()->getFolders().end()){
            cout << "Enter a new name:\n> ";
            getline(cin, new_name);
            catalog.back()->getFolders()[distance(catalog.back()->getFolders().begin(), folder_it)].setName(new_name);
            cout << "The object has been renamed successfully!" << endl;
        }
        else if (object_name.extension() != "" && file_it != catalog.back()->getFiles().end()){
            cout << "Enter a new name:\n> ";
            getline(cin, new_name);
            path new_name_check = new_name;
            if (new_name_check.extension() == "")
                new_name_check += object_name.extension();
            catalog.back()->getFiles()[distance(catalog.back()->getFiles().begin(), file_it)].setName(new_name_check.string());
            cout << "The object has been renamed successfully!" << endl;
        }
        else
            cout << "The object does not exist!" << endl;
    }

    /*
     * Deleting an object
     */
    void deleteObject(string command){
        path object_name = command.substr(7, command.size() - 7);
        auto folder_it = find_if(catalog.back()->getFolders().begin(), catalog.back()->getFolders().end(), [object_name](Folder &p){
            return p.getName() == object_name;
        });

        auto file_it = find_if(catalog.back()->getFiles().begin(), catalog.back()->getFiles().end(), [object_name](File &p){
            return p.getName() == object_name;
        });

        if (object_name.extension() != "" && file_it != catalog.back()->getFiles().end()) {
            catalog.back()->getFiles().erase(file_it);
            cout << "Deleted!" << endl;
        }
        else if (object_name.extension() == "" && folder_it != catalog.back()->getFolders().end() &&
                (!catalog.back()->getFolders()[distance(catalog.back()->getFolders().begin(), folder_it)].getFolders().empty() ||
                 !catalog.back()->getFolders()[distance(catalog.back()->getFolders().begin(), folder_it)].getFiles().empty())){
            cout << "You can only delete empty directories!" << endl;
        }
        else if (object_name.extension() == "" && folder_it != catalog.back()->getFolders().end()){
            catalog.back()->getFolders().erase(folder_it);
            cout << "Deleted!" << endl;
        }
        else
            cout << "The object was not found!" << endl;
    }

    /*
     * Moving an object
     */
    void moveObject(string command){
        string target_dir = command.substr(command.find_last_of(' ') + 1);
        string object_name = command.substr(command.find_first_of(' ') + 1);
        object_name = object_name.substr(0, object_name.find_last_of(' '));
        path object_name_path = object_name;

        if (target_dir.back() != '\\'){
            target_dir.push_back('\\');
        }

        vector<string> directories;
        while (target_dir.length() != 0){
            directories.push_back(target_dir.substr(0, target_dir.find_first_of('\\')));
            target_dir.erase(0, target_dir.find_first_of('\\') + 1);
        }

        vector<Folder*> temp_catalog;
        bool dir_exists = true;
        if (catalog[0]->getName() == directories[0])
            temp_catalog.push_back(catalog[0]);
        else
            cout << "The '"<< directories[0] << "' directory does not exist!" << endl;

        for (int i = 1; i < directories.size(); i++){
            auto temp_folder_it = find_if(temp_catalog.back()->getFolders().begin(), temp_catalog.back()->getFolders().end(), [directories, i](Folder &p){
                return p.getName() == directories[i];
            });

            if (temp_folder_it != temp_catalog.back()->getFolders().end()){
                temp_catalog.push_back(&temp_catalog.back()->getFolders()[distance(temp_catalog.back()->getFolders().begin(), temp_folder_it)]);
            }
            else{
                dir_exists = false;
                cout << "The '"<< directories[i] << "' directory does not exist!" << endl;
                break;
            }
        }

        auto folder_it = find_if(catalog.back()->getFolders().begin(), catalog.back()->getFolders().end(), [object_name](Folder &p){
            return p.getName() == object_name;
        });

        auto file_it = find_if(catalog.back()->getFiles().begin(), catalog.back()->getFiles().end(), [object_name](File &p){
            return p.getName() == object_name;
        });

        if (object_name_path.extension() != "" && file_it != catalog.back()->getFiles().end() && dir_exists) {
            temp_catalog.back()->getFiles().push_back(catalog.back()->getFiles()[distance(catalog.back()->getFiles().begin(), file_it)]);
            catalog.back()->getFiles().erase(file_it);
            cout << "Moved successfully!" << endl;
        }
        else if (object_name_path.extension() == "" && folder_it != catalog.back()->getFolders().end() && dir_exists){
            temp_catalog.back()->getFolders().push_back(catalog.back()->getFolders()[distance(catalog.back()->getFolders().begin(), folder_it)]);
            catalog.back()->getFolders().erase(folder_it);
            cout << "Moved successfully!" << endl;
        }
        else
            cout << "The object was not found!" << endl;
    }

    /*
     * Moving to a subfolder
     */
    void changeDir(string command){
        string dir_name = command.substr(11, command.size() - 11);
        auto folder_it = find_if(catalog.back()->getFolders().begin(), catalog.back()->getFolders().end(), [dir_name](Folder &p){
            return p.getName() == dir_name;
        });
        if (dir_name == ".." && catalog.size() != 1){
            catalog.pop_back();
            showName();
        }
        else if (dir_name == ".." && catalog.size() == 1){
            cout << "This is the root directory!" << endl;
        }
        else if (folder_it != catalog.back()->getFolders().end()){
            catalog.push_back(&(*folder_it));
            showName();
        }
        else
            cout << "The directory does not exist!" << endl;
    }

    /*
     * Output all objects contained in the folder
     */
    void showTree(string command){

        if (catalog.back()->getFolders().empty() && catalog.back()->getFiles().empty())
            cout << "The directory is empty!" << endl;
        else if (catalog.back()->getName() == command.substr(10, command.size() - 10)){
            for(auto it : catalog.back()->getFolders())
                cout << it.getName() << endl;
            for(auto it : catalog.back()->getFiles())
                cout << it.getName() << endl;
            cout << endl;
        }
        else
            cout << "Enter the name of the current directory!" << endl;
    }
};

#endif //LAB_10_1_CLASSES_H
