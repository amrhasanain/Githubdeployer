#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void repo(const string name,const string email,const string link) {
    vector<string> commands =  {
        "git config --global user.name \""+name+"\"",
        "git config --global user.email \"" + email + "\"",
        "git init",
        "git add .",
        "git commit -m \"Initial commit\"",
        "git branch -M main",
        "git remote add origin \"" + link + "\"",
        "git push -u origin main"
    };
    for (const auto& command : commands) {
        if (std::system(command.c_str()) != 0) {
            std::cerr << "Failed: " << command << '\n';
            return;
        }
    }
}



int main() {
    repo(
        "Amr",
        "amrhasanain47@gmail.com",
        "https://github.com/amrhasanain/test.git"
    );
    return 0;
}