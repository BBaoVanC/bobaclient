#ifndef BOBACLIENT_ERRORS_HPP
#define BOBACLIENT_ERRORS_HPP

#include <nlohmann/json.hpp>

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
    public:
        std::string message;
        std::optional<nlohmann::json> error = std::nullopt;
        //RequestException(const std::string &msg);
        const char *what() const noexcept;
    };
}

#endif
