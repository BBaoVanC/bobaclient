// #ifndef BOBACLIENT_CLI_HPP
// #define BOBACLIENT_CLI_HPP

#include <curl/curl.h>

namespace cli {
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
}

// #endif
