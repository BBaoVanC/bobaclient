#include "curl.hpp"

#include <iostream>
#include <curl/curl.h>

CurlGlobalHandle::CurlGlobalHandle() {
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != 0) {
        throw std::runtime_error("failed curl_global_init with code: " + std::to_string(res));
    }
    // TODO: remove debug
    std::cout << "global handle created" << std::endl;
}
CurlGlobalHandle::~CurlGlobalHandle() {
    curl_global_cleanup();
    // TODO: remove debug
    std::cout << "global handle deleted" << std::endl;
}
