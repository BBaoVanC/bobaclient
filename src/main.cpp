//TODO: mark more stuff const

#include "curl.hpp"

#include "bobaclient.hpp"

#include <iostream>
#include <string>
#include <map>

extern "C" {
    #include <getopt.h>
}

static char *exec_name;
static const char try_help_flag_message[] = "Use the '--help' option to display help page\n";
static const char main_usage[] = "Usage: bobaclient [options] command ...\n";
static const char main_help[] =
    "Options:\n"
    "  -h, --help\n"
    "Commands:\n"
    "  info     Get info about an upload\n"
;

static int main_help_flag = 0;
static const struct option main_long_options[] = {
    { "help",   no_argument,    &main_help_flag,    1 },
    { 0, 0, 0, 0 }
};

typedef int (*CommandFunction)(int, char *argv[]);

int command_help(int argc, char *argv[]);
int command_info(int argc, char *argv[]);

static std::map<std::string, CommandFunction> command_map = {
    { "--help", command_help },
    { "-h",     command_help },
    { "info",   command_info },
};

int command_help(int argc, char *argv[]) {
    std::cerr << main_help;
    return 0;
}

// XXX: test: https://share.boba.best/api/v1/info/PJpmMIw7
int main(int argc, char *argv[]) {
    // store this so we can add it back later in subcommands
    exec_name = argv[0];

    bool exit_for_invalid_args = false;
    int opt_idx = 0;
    int c;
    while ((c = getopt_long(argc, argv, "+h", main_long_options, &opt_idx)) != -1) {

        switch (c) {
            case -1:
                // the loop will end after this
                break;
            case 0:
                // do nothing else if flag was set
                if (main_long_options[opt_idx].flag != 0) {
                    break;
                }
            case '?':
                exit_for_invalid_args = true;
                break;
            case 'h':
                main_help_flag = 1;
                break;
            default:
                std::cout << "abort" << std::endl;
                abort();
        }
    }
    if (exit_for_invalid_args) {
        std::cerr << main_usage << try_help_flag_message;
        return 1;
    }
    if (main_help_flag) {
        std::cerr << main_usage << main_help;
        return 0;
    }

    if (optind >= argc) { // if index of last arg < index where getopt stopped (end of args, or first non-flag)
        std::cerr << exec_name << ": no command provided\n" << main_usage << try_help_flag_message;
        return 1;
    }

    const std::string command_str(argv[optind]);
    if (command_map.count(command_str) < 1) {
        std::cerr << exec_name << ": invalid command: " << command_str << "\n" << main_usage << try_help_flag_message;
        return 1;
    }
    const CommandFunction command = command_map[command_str];

    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;

    optind++; // move past the command arg
    return (*command)(argc, argv);
}

static const char command_info_usage[] = "Usage: bobaclient info [options] ID\n";
static const char command_info_help[] =
    "  Get metadata about an upload by its ID\n"
    "Options:\n"
    "  -h, --help\n"
    "  -r, --raw    Print the raw (JSON) response instead of pretty printing\n"
    "  -i, --id     Set id of upload to look up info about\n"
;

static int command_info_help_flag = 0;
static int command_info_raw_flag = 0;
static const struct option command_info_long_options[] = {
    { "help",   no_argument,        &command_info_help_flag,    1   },
    { "raw",    no_argument,        &command_info_raw_flag,     1   },
    { 0, 0, 0, 0 }
};

int command_info(int argc, char *argv[]) {
    bool exit_for_invalid_args = false;
    int opt_idx = 0;
    int c;
    while ((c = getopt_long(argc, argv, "hr", command_info_long_options, &opt_idx)) != -1) {
        switch (c) {
            case 0:
                std::cout << "case 0" << std::endl;
                break;
            case '?':
                // getopt already prints an error message
                exit_for_invalid_args = true;
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
    if (exit_for_invalid_args) {
        std::cerr << command_info_usage << try_help_flag_message;
        return 1;
    }
    if (command_info_help_flag) {
        std::cerr << command_info_usage << command_info_help;
        return 0;
    }

    int id_idx = optind;
    if (id_idx >= argc) {
        std::cerr << exec_name << ": missing ID argument\n";
        return 1;
    }

    const std::string id(argv[id_idx]);
    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/" + id);
    return 0;
}
