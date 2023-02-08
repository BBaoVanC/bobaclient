//#include "main.hpp"

#include "curl.hpp"

#include "bobaclient.hpp"
#include "log.hpp"

#include <iostream>
#include <string>
#include <unordered_map>
#include <getopt.h>

// TODO: maybe replace this by making a logger class
char *exec_name;

const static struct option long_options[] = {
};

typedef int (*ActionFunction)(int, char *const argv[]);

int action_info(int argc, char *const argv[]);

static std::unordered_map<std::string, ActionFunction> action_map = {
    { "info", action_info },
};

int main(int argc, char *argv[]) {
    // zeroth arg is program name
    exec_name = argv[0];
    argv++; argc--;

    if (argc < 1) {
        util::fail("argument `action` missing");
        return 1;
    }

    // first arg is the action to do
    const std::string action_str(argv[0]);
    argv++; argc--;
    if (action_map.count(action_str) < 1) {
        util::fail("invalid action: " + action_str);
        return 1;
    }
    const ActionFunction action = action_map[action_str];

    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;

    return (*action)(argc, argv);
}

int action_info(int argc, char *const argv[]) {
    if (argc < 1) {
        util::fail("argument `id` missing");
        return 1;
    }

    const std::string id(argv[0]);
    argv++; argc--;

    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/" + id);
    return 0;
}
