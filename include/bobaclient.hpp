#ifndef BOBACLIENT_LIBBOBACLIENT_HPP
#define BOBACLIENT_LIBBOBACLIENT_HPP

#include <string>
#include <curl/curl.h>

namespace bobaclient {
    class CurlException: public std::exception {
    private:
        std::string msg;
    public:
        CurlException(std::string const &msg);
        const char *what() const noexcept;
    };

    class Bobaclient {
        // TODO: replace CurlWrapper
        Bobaclient();
        ~Bobaclient();
    private:
        CURL *curl;
    };
}

#endif
