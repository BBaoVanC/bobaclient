#include "log.hpp"

Logger::Logger(const char *exec_name): exec_name(exec_name) {}

void Logger::fail(const std::string &msg) const {
    std::cerr << exec_name << ": " << msg << std::endl;
}
