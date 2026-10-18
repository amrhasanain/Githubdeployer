#pragma once
#include <iostream>
#include <cstdlib>

int run(const std::string& command) {
    std::cout << "> " << command << '\n';
    return std::system(command.c_str());
}

