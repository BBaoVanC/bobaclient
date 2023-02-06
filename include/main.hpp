#include <iostream>
#include <curl/curl.h>

class CurlGlobalHandle {
public:
    CurlGlobalHandle() {
        curl_global_init(CURL_GLOBAL_ALL);
        std::cout << "global handle created" << std::endl;
    }
    ~CurlGlobalHandle() {
        curl_global_cleanup();
        std::cout << "global handle deleted" << std::endl;
    }
};
