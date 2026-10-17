#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>

int run(const std::string& command) {
    std::cout << "> " << command << '\n';
    return std::system(command.c_str());
}

bool repo(const std::string& name,
          const std::string& email,
          const std::string& link) {
    if (run("git config --global user.name \"" + name + "\"") != 0 ||
        run("git config --global user.email \"" + email + "\"") != 0) {
        return false;
    }

    // Initialize only if this directory is not already a Git repository.
    if (!std::filesystem::exists(".git")) {
        if (run("git init") != 0) return false;
    }

    if (run("git add .") != 0) return false;

    // git diff --cached --quiet returns 0 when there are no staged changes,
    // and 1 when there are changes to commit.
    int changes = std::system("git diff --cached --quiet");

    if (changes == 1) {
        if (run("git commit -m \"Publish project\"") != 0) return false;
    } else if (changes != 0) {
        std::cerr << "Could not check staged changes.\n";
        return false;
    } else {
        std::cout << "No new changes to commit.\n";
    }

    if (run("git branch -M main") != 0) return false;

    // On Windows, redirect the command output to NUL while checking origin.
    int originExists = std::system("git remote get-url origin >NUL 2>&1");

    if (originExists == 0) {
        if (run("git remote set-url origin \"" + link + "\"") != 0) {
            return false;
        }
    } else {
        if (run("git remote add origin \"" + link + "\"") != 0) {
            return false;
        }
    }

    if (run("git push -u origin main") != 0) {
        std::cerr << "Push failed. The GitHub repository may already contain commits.\n";
        return false;
    }

    return true;
}

int main() {
    return repo(
        "Amr",
        "amrhasanain47@gmail.com",
        "https://github.com/amrhasanain/test.git"
    ) ? 0 : 1;
}