#ifndef BOBACLIENT_LIBBOBACLIENT_HPP
#define BOBACLIENT_LIBBOBACLIENT_HPP

#include <string>
#include <curl/curl.h>

#include "types.hpp"

namespace bobaclient {
    class CurlException: public std::exception {
    private:
        std::string msg;
    public:
        CurlException(std::string const &msg);
        const char *what() const noexcept;
    };

    class Bobaclient {
    private:
        CURL *curl;
    public:
        Bobaclient();
        ~Bobaclient();

        // TODO: can these all be const functions
        types::InfoResponse get_info(std::string const &url);
    };
}

#endif
