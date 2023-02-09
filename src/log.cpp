#include "log.hpp"

namespace logger {
    // used for error message with wrong args to the CLI
    // TODO: figure out how to extend this to work with commmands
    //       (maybe take usage as parameter?)
    void fail_cli(const std::string &msg) {
        std::clog << exec_name << ": " << msg << "\n";
        std::clog << usage << std::flush; // newline already included in usage string
    }
}
