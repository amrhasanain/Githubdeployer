#include <cstdlib>
#include <iostream>
#include <string>
#include "../src/utils/repo.hpp"
#include "../src/terminal/usage.hpp"
#include "../src/terminal/ansi.hpp"
#include "../src/terminal/banner.hpp"
#include "../src/terminal/color.hpp"

using namespace std;

int main(int argc,char** argv) {
    enableAnsiColors();
    printBanner();
    string name = " ";
    string email = " ";
    string link = " ";
    if (argc == 2) {
        const string option = argv[1];
        if (option == "--version" || option == "-version") {
            cout << "ghdeployer 1.0.0\n";
        }
        else if (option == "--help" || option == "-help") {
            printUsage();
        } 
    }
    if (argc == 8) {
        if (string(argv[1]) == "publish") {
            if (string(argv[2]) == "--name" || string(argv[2]) == "-name") {
                name = argv[3];
                if (string(argv[4]) == "--email" || string(argv[4]) == "-email") {
                    email = argv[5];
                    if (string(argv[6]) == "--repo" || string(argv[6]) == "-repo") {
                        link = argv[7];
                    }
                }
            }
        }
        if (name == " " || email == " " || link == " ") {
            cout << color::red << "Invalid Arguments" << color::reset << '\n';
        }
        else {
            repo(name,email,link);
        }
    }
    if (argc != 8 && argc != 2) {
        cerr << color::red
                << "Error: Invalid arguments.\n\n"
                << color::reset;
        printUsage();
        return 1;
    }
}