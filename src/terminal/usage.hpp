#pragma once

#include "color.hpp"
#include <iostream>


void printUsage() {
    std::cout
        << color::yellow << "Usage:\n" << color::reset
        << "  ghdeployer publish --name \"<your name>\" --email \"<your github email>\" --repo <your repo link>\n"
        << "  ghdeployer --help\n"
        << "  ghdeployer --version\n\n"
        << color::gray
        << "Example:\n"
        << R"(  ghdeployer publish --name "myname" --email "myemail@example.com" --repo myrepolink.git)"
        << color::reset << '\n';
}