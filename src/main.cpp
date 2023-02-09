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
    #include <string.h>
}

char *logger::exec_name;
const char logger::usage[] = 
    "Usage: bobaclient [options] command ...\n";
const char help_main[] =
    "Usage: bobaclient [options] command ...\n"
    "Options:\n"
    "  -h, --help\n"
    "Commands:\n"
    "  info     Get info about an upload\n"
;

typedef int (*CommandFunction)(int, char *argv[]);

int command_help(int argc, char *argv[]);
int command_info(int argc, char *argv[]);

static std::map<std::string, CommandFunction> command_map = {
    { "--help", command_help },
    { "-h",     command_help },
    { "info",   command_info },
};

int command_help(int argc, char *argv[]) {
    std::clog << help_main << std::flush;
    return 0;
}

// XXX: test: https://share.boba.best/api/v1/info/PJpmMIw7
int main(int argc, char *argv[]) {
    // zeroth arg is program name
    logger::exec_name = argv[0];
    argv++; argc--;

    if (argc < 1) {
        logger::fail_usage("argument `command` missing");
        return 1;
    }

    // first arg is the command to do
    const std::string command_str(argv[0]);
    argv++; argc--;
    if (command_map.count(command_str) < 1) {
        logger::fail_usage("invalid command: " + command_str);
        return 1;
    }
    const CommandFunction command = command_map[command_str];

    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;

    return (*command)(argc, argv);
}

const char command_info_usage[] =
    "Usage: bobaclient info [options]\n";
const char command_info_help[] =
    "Usage: bobaclient info [options]\n"
    "  Get metadata about an upload\n"
    "Options:\n"
    "  -h, --help\n"
    "  -r, --raw    Print the raw (JSON) response instead of pretty printing\n"
    "  -i, --id     Set id of upload to look up info about\n"
;

static int command_info_help_flag = 0;
static int command_info_raw_flag = 0;
static const struct option long_options[] = {
    { "help",   no_argument,        &command_info_help_flag,    1   },
    { "raw",    no_argument,        &command_info_raw_flag,     1   },
    { 0, 0, 0, 0 }
};

int command_info(int argc, char *argv[]) {
    if (argc < 1) {
        logger::fail_usage("argument `id` missing", command_info_usage);
        return 1;
    }

    // getopt will expect first arg to be program name, so we need it back
    argv--; argc++;
    argv[0] = logger::exec_name;

    while (true) {
        int opt_idx = 0;
        int c = getopt_long(argc, argv, "hr", long_options, &opt_idx);

        // end of options
        if (c == -1) {
            break;
        }

        switch (c) {
            case 0:
                std::cout << "case 0" << std::endl;
                break;
            case 1:
                std::cout << "case 1" << std::endl;
                break;
            case '?':
                // getopt already printed an error message
                break;
            case 'h':
                command_info_help_flag = 1;
                break;
            case 'r':
                command_info_raw_flag = 1;
                break;
            default:
                abort();
        }
    }

    if (command_info_help_flag) {
        std::clog << command_info_help << std::flush;
        return 0;
    }

    return 10;

    const std::string id(argv[0]);
    argv++; argc--;

    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/" + id);
    return 0;
}
