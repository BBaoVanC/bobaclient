#include "curl.hpp"

#include <iostream>
#include <curl/curl.h>

CurlGlobalHandle::CurlGlobalHandle() {
    curl_global_init(CURL_GLOBAL_ALL);
    std::cout << "global handle created" << std::endl;
}
CurlGlobalHandle::~CurlGlobalHandle() {
    curl_global_cleanup();
    std::cout << "global handle deleted" << std::endl;
}
