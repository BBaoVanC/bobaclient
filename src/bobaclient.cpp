#include <iostream>
#include <string>
#include <curl/curl.h>
#include "curl.hpp"

using namespace bobaclient;

int main() {
    CurlWrapper curl;
    std::string data;

    const CurlResponse resp = curl.get_url("https://share.boba.best/api/v1/info/PJpmMIw7");
    std::clog << "data: " << resp.data << std::endl;
    std::clog << "response code: " << resp.response_code << std::endl;

    const CurlResponse abc = curl.get_url("htps://share.boba.best/api/v1/info/nfr");
    std::clog << "data: " << abc.data << std::endl;

    return 0;
}
