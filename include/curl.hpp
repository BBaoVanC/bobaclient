#ifndef BOBACLIENT_CURL_HPP
#define BOBACLIENT_CURL_HPP

#include <string>
#include <curl/curl.h>

namespace bobaclient {
    struct CurlResponse {
        long response_code;
        std::string data;
    };

    class CurlWrapper {
    private:
        CURL *curl;
    public:
        CurlWrapper();
        ~CurlWrapper();
        operator CURL*();

        CurlResponse get_url(std::string const& url);
    };
}

#endif
