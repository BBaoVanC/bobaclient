#ifndef BOBACLIENT_ERRORS_HPP
#define BOBACLIENT_ERRORS_HPP

#include <nlohmann/json.hpp>

#include <string>

namespace bobaclient {
    class CurlException: public std::runtime_error {
    public:
        CurlException(std::string const &msg);
    };

    // error response from bobashare server
    class BobashareException: public std::exception {
    private:
        std::string message;
        std::optional<nlohmann::json> error = std::nullopt;
    public:
        BobashareException() = default;
        BobashareException(const std::string &msg);
        const char *what() const noexcept;
        const std::optional<nlohmann::json> backtrace() const noexcept;

        friend void from_json(const nlohmann::json &j, BobashareException &e);
    };
}

#endif
