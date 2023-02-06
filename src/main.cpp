#include "main.hpp"

#include "bobaclient.hpp"

#include <iostream>
#include <string>

int main() {
    // just a guard to run curl_global_init and curl_global_cleanup
    const CurlGlobalHandle _curl_global_handle;

    bobaclient::Bobaclient client;
    const auto resp = client.get_info("https://share.boba.best/api/v1/info/PJpmMIw7");

    return 0;
}
