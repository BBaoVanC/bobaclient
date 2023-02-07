//#include "main.hpp"

#include "curl.hpp"

#include "bobaclient.hpp"

#include <iostream>
#include <unordered_map>
#include <getopt.h>

const static struct option long_options[] = {
};

enum class Action {
    Info,
};
static std::unordered_map<std::string, Action> action_map = {
    { "info", Action::Info },
};

int action_info(bobaclient::Bobaclient &client, int argc, char *const argv[]);

int main(int argc, char *argv[]) {
    // zeroth arg is program name
    const static char *exec_name = argv[0];
    argv++; argc--;
    if (argc < 1) {
        std::cerr << exec_name << ": an argument is required" << std::endl;
        return 1;
    }

    // first arg is the action to do
    const std::string action_str(argv[0]);
    argv++; argc--;
    if (action_map.count(action_str) < 1) {
        std::cerr << exec_name << ": invalid action: " << action_str << std::endl;
        return 1;
    }
    const Action action = action_map[action_str];

    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;
    bobaclient::Bobaclient client;

    switch (action) {
        case Action::Info:
            return action_info(client, argc, argv);
    }

    // shouldn't be reached
    std::cerr << "this shouldn't be reached!" << std::endl;
    return -1;
}

int action_info(bobaclient::Bobaclient &client, int argc, char *const argv[]) {
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/PJpmMIw7");
    return 0;
}
