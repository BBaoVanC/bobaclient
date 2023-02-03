#ifndef BOBACLIENT_CURL_HPP
#define BOBACLIENT_CURL_HPP

#include <curl/curl.h>

namespace bobaclient {
    struct CurlWrapper {
        CurlWrapper();
        ~CurlWrapper();

        operator CURL*();
    private:
        CURL *curl;
    };
}

#endif
