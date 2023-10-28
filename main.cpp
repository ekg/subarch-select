#include "utilities.h"

int main(int argc, char** argv) {
    // if the first argument is --help, or -h
    // or if there are no arguments print the help message and exit
    if (argc == 1 || std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        std::cout << "Usage: subarch-select [features] [path] ... [--] [program arguments]" << '\n';
        std::cout << "Example: subarch-select avx2,sse4_2 /path/to/program-avx2 avx,sse2 /path/to/program-avx -- --arg1 --arg2 --arg3" << '\n';
        return 0;
    }

    // if env variable SUBARCH_DEBUG is set then we print debug messages
    bool debug = false;
    if (std::getenv("SUBARCH_DEBUG") != NULL) {
        debug = true;
    }
    // logging function
    auto log = [&](const std::string& msg) {
        if (debug) {
            std::cerr << "[subarch-select] " << msg << '\n';
        }
    };

    // parse the command line arguments
    // if we find a double dash, then we're done parsing the arguments
    int i = 1;
    std::string path;
    for ( ; i < argc; ) {
        // copy from argv into strings
        std::string features = argv[i];
        if (features == "--") {
            // we're done parsing the arguments
            //std::cerr << "Hi" << std::endl;
            i += 1;
            break;
        }
        if (path.empty() && is_matching_features(features)) {
            log("has features: " + features);
            path = argv[i+1];
        }
        i += 2;
    }
    if (!path.empty()) {
        std::stringstream ss;
        for (int j = i; j < argc; ++j) {
            ss << " " << argv[j];
        }
        log("executing: " + path + ss.str());
        execv(path.c_str(), argv+i-1);
    } else {
        return 1;
    }
}

