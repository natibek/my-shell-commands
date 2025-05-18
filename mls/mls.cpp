#include <iostream>
#include <dirent.h>
#include <string>
#include <filesystem>
#include <vector>
#include <ranges>
#include <algorithm>

// color for dotfiles, executables, soft and hard links, directories
// print rows if it allows
// remove the dot files

namespace fs = std::filesystem;
class Directory {
public:
    std::string dirname;
    fs::path path;
    std::vector<fs::directory_entry> dir_entries;
    
    Directory(std::string dirname):
        path {dirname} {
        if (!fs::is_directory(path)) {
            exit(1);
        }
        dir_entries = std::vector<fs::directory_entry>(fs::directory_iterator(path), fs::directory_iterator());
        std::sort(dir_entries.begin(), dir_entries.end());
    }

    void print_contents() {
        for(auto entry: dir_entries) {
            std::cout << entry.path().filename().string() << "\n";
        }
    }

};

int main(int argc, char* argv[]) {

    Directory dir {std::filesystem::current_path()};
    dir.print_contents();
    
}
