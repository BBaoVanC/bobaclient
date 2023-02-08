#include <iostream>

class Logger {
public:
    Logger(Logger &) = delete;
    Logger & operator=(Logger) = delete;

    Logger(const char *exec_name);

    void fail(const std::string &str) const;
private:
    const char *exec_name;
};
