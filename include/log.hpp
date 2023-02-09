#include <iostream>
#include <string>

namespace logger {
    extern char *exec_name;
    extern const char usage[];
    void fail_cli(const std::string &str);
}
