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
    private:
        std::string message;
        std::optional<nlohmann::json> error = std::nullopt;
    public:
        RequestException() = default;
        RequestException(const std::string &msg);
        const char *what() const noexcept;
        const std::optional<nlohmann::json> backtrace() const noexcept;

        friend void from_json(const nlohmann::json &j, RequestException &e);
    };
}

#endif
