#ifndef BOBACLIENT_ERRORS_HPP
#define BOBACLIENT_ERRORS_HPP

#include <nlohmann/json.hpp>

#include <string>
#include <optional>

namespace bobaclient {
    class CurlException: public std::runtime_error {
    public:
        CurlException(const std::string &msg);
    };

    // error response from bobashare server
    class BobashareException: public std::runtime_error {
    private:
        const std::optional<nlohmann::json> error = std::nullopt;
    public:
        BobashareException(const std::string &msg);
        BobashareException(const std::string &msg, nlohmann::json backtrace);
        const std::optional<nlohmann::json> backtrace() const noexcept;
    };
}

#endif
