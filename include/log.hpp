#include <iostream>
#include <string>

namespace logger {
    extern char *exec_name;
    extern const char usage[];
    void fail_usage(const std::string &str);
    void fail_usage(const std::string &str, const std::string &usage);
}
