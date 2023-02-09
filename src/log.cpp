#include "log.hpp"

namespace logger {
    // used for error message with wrong args to the CLI
    void fail_usage(const std::string &msg) {
        // flush because newline already in string
        std::clog << exec_name << ": " << msg << "\n" << usage << std::flush;
    }
    void fail_usage(const std::string &msg, const std::string &usage) {
        std::clog << exec_name << ": " << msg << "\n" << usage << std::flush;
    }
}
