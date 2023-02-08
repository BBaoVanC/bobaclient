#include <iostream>

class Logger {
public:
    Logger(char *exec_name);
    void fail(const std::string &str);
private:
    char *exec_name;
};
