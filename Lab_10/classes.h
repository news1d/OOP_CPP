#ifndef LAB_10_CLASSES_H
#define LAB_10_CLASSES_H
#include <iostream>
#include <experimental/filesystem>
#include <list>

using namespace std::experimental::filesystem;
using namespace std;

class FileTree{
private:
    vector <string> catalog;
public:
    FileTree(path curr_dir){
        for (directory_entry dir_entry : recursive_directory_iterator(curr_dir)){
           catalog.push_back(dir_entry.path().string());
           cout << dir_entry << endl;
        }
    }
};

class Folder{
    vector <string> folders;
public:
    Folder(path curr_dir){
        string folder = curr_dir.string().substr(curr_dir.string().find_last_of("/\\") + 1);
        folders.push_back(folder);
        for (directory_entry dir_entry : recursive_directory_iterator(curr_dir)){
            string dir_entry_temp = dir_entry.path().string();
            folders.push_back(dir_entry_temp.substr(dir_entry_temp.find(folder), dir_entry_temp.size() - dir_entry_temp.find(folder)));
        }
    }

    void show(){
        for(auto it : folders)
            cout << it << endl;
    }

    class File{
    private:
        string name;
        string description;
        string folder;
    public:
        File(string name, path curr_dir){
            this->name = name;
            this->folder = curr_dir.string().substr(curr_dir.string().find_last_of("/\\") + 1);
        }
    };

};

#endif //LAB_10_CLASSES_H
