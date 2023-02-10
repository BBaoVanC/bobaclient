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
    class BobashareException: public std::runtime_error {
    private:
        std::optional<nlohmann::json> error = std::nullopt;
    public:
        // TODO: https://json.nlohmann.me/features/arbitrary_types/#how-can-i-use-get-for-non-default-constructiblenon-copyable-types
        BobashareException(const std::string &msg);
        BobashareException(const std::string &msg, nlohmann::json backtrace);
        const std::optional<nlohmann::json> backtrace() const noexcept;
    };
}

#endif
