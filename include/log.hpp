#include <iostream>

extern char *exec_name;

namespace util {
    // mainly intended for arg parsing
    template <typename T>
    void fail(T str) {
        std::cerr << exec_name << ": " << str << std::endl;
    }
}
