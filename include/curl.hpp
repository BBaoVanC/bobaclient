#ifndef BOBACLIENT_CURL_HPP
#define BOBACLIENT_CURL_HPP

#include <string>
#include <curl/curl.h>

namespace bobaclient {
    class CurlException: public std::exception {
    private:
        std::string msg;
    public:
        CurlException(std::string const &msg);
        // TODO: Fix this
        const char *what() const throw() {return msg.c_str();}
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
