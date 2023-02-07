#ifndef BOBACLIENT_ERRORS_HPP
#define BOBACLIENT_ERRORS_HPP

#include <string>

namespace bobaclient {
    class CurlException: public std::exception {
    private:
        std::string msg;
    public:
        CurlException(std::string const &msg);
        const char *what() const noexcept;
    };

    class RequestException: public std::exception {
    private:
        std::string msg;
    public:
        RequestException(std::string const &msg);
        const char *what() const noexcept;
    };
}

#endif
