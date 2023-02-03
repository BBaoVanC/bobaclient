#ifndef LIBBOBACLIENT_CURL_HPP
#define LIBBOBACLIENT_CURL_HPP

#include <string>
#include <curl/curl.h>

namespace bobaclient {
    class CurlException: public std::exception {
    private:
        std::string msg;
    public:
        CurlException(std::string const &msg);
        // TODO: does this need to be virtual
        const char *what() const noexcept;
    };

    struct CurlResponse {
        long response_code;
        std::string data;
    };

    class CurlWrapper {
    private:
        // TODO: can/should this be a reference instead?
        CURL *curl;
    public:
        CurlWrapper();
        ~CurlWrapper();
        operator CURL*();

        CurlResponse get_url(std::string const& url);
    };
}

#endif
