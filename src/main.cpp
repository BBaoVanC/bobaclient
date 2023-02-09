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

typedef int (*CommandFunction)(int, char *const argv[]);

int command_help(int argc, char *const argv[]);
int command_info(int argc, char *const argv[]);

static std::unordered_map<std::string, CommandFunction> command_map = {
    { "--help", command_help },
    { "-h",     command_help },
    { "info",   command_info },
};

int command_help(int argc, char *const argv[]) {
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

const char usage_info[] =
    "Usage: bobaclient info [options]\n";
const char help_info[] =
    "Usage: bobaclient info [options]\n"
    "  Get metadata about an upload\n"
    "Options:\n"
    "  -h, --help\n"
    "  -r, --raw    Print the raw (JSON) response instead of pretty printing\n"
    "  -i, --id     Set the id of the upload to get info about\n"
;

static int help_info_flag = 0;

static const struct option long_options[] = {
    { "help",   no_argument,        &help_info_flag,    1   },
    { "raw",    no_argument,        nullptr,           'r' },
    { "id",     required_argument,  nullptr,            'i' },
};

int command_info(int argc, char *const argv[]) {
    if (argc < 1) {
        logger::fail_usage("argument `id` missing", usage_info);
        return 1;
    }

    int c;
    while (true) {
        int opt_idx = 0;
        c = getopt_long(argc, argv, "hri:", long_options, &opt_idx);

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
                std::cout << "case '?'" << std::endl;
            case 'h':
                std::cout << "case 'h'" << std::endl;
            case 'r':
                std::cout << "case 'r'" << std::endl;
            case 'i':
                std::cout << "case 'i'" << std::endl;
                std::cout << optarg << std::endl;
            default:
                abort();
        }
    }

    if (help_info_flag) {
        std::clog << help_info << std::flush;
        return 0;
    }

    return 10;

    const std::string id(argv[0]);
    argv++; argc--;

    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/" + id);
    return 0;
}
