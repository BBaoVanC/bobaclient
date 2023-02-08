#include "log.hpp"

Logger::Logger(char *exec_name): exec_name(exec_name) {}

void Logger::fail(const std::string &msg) {
    std::cerr << exec_name << ": " << msg << std::endl;
}
