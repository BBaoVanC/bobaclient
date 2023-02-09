#include "curl.hpp"

#include <iostream>

extern "C" {
    #include <curl/curl.h>
}

CurlGlobalHandle::CurlGlobalHandle() {
    CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != 0) {
        throw std::runtime_error("failed curl_global_init with code: " + std::to_string(res));
    }
}
CurlGlobalHandle::~CurlGlobalHandle() {
    curl_global_cleanup();
}
