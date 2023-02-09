//#include "main.hpp"
//TODO: mark more stuff const

#include "curl.hpp"

#include "bobaclient.hpp"
#include "log.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

extern "C" {
    #include <getopt.h>
}

char *logger::exec_name;
const char logger::usage[] = 
    "Usage: bobaclient [options] command [-h | --help] ...\n"
    "Options:\n"
    "  -h, --help\n"
    "Commands:\n"
    "  info     Get info about an upload\n"
;

typedef int (*CommandFunction)(int, char *const argv[]);

int command_help(int argc, char *const argv[]);
int command_info(int argc, char *const argv[]);

static std::unordered_map<std::string, CommandFunction> command_map = {
    { "--help", command_help },
    { "-h",     command_help },
    { "info",   command_info },
};

// XXX: test: https://share.boba.best/api/v1/info/PJpmMIw7
int main(int argc, char *argv[]) {
    // zeroth arg is program name
    logger::exec_name = argv[0];
    argv++; argc--;

    if (argc < 1) {
        logger::fail_cli("argument `command` missing");
        return 1;
    }

    // first arg is the command to do
    const std::string command_str(argv[0]);
    argv++; argc--;
    if (command_map.count(command_str) < 1) {
        logger::fail_cli("invalid command: " + command_str);
        return 1;
    }
    const CommandFunction command = command_map[command_str];

    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;

    return (*command)(argc, argv);
}

int command_help(int argc, char *const argv[]) {
    std::clog << logger::usage << std::flush;
    return 0;
}

int command_info(int argc, char *const argv[]) {
    if (argc < 1) {
        logger::fail_cli("argument `id` missing");
        return 1;
    }

    const std::string id(argv[0]);
    argv++; argc--;

    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/" + id);
    return 0;
}
