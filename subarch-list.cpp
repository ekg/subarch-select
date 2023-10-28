#include "utilities.h"

int main(int argc, char** argv) {
    // if the first argument is --help, or -h
    // or if there are no arguments print the help message and exit
    if (argc > 1) {
        std::cout << "Usage: subarch-list" << '\n';
        if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
            return 0;
        }
        return 1;
    }
    for (auto arch : {"x86-64-v2", "x86-64-v3", "x86-64-v4"}) {
        if (has_feature(arch)) {
            std::cout << arch << "\n";
        }
    }
    return 0;
}

