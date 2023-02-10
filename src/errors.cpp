#include "errors.hpp"

#include <nlohmann/json.hpp>
#include <string>

namespace bobaclient {
    CurlException::CurlException(std::string const &msg): std::runtime_error(msg) {}

    BobashareException::BobashareException(std::string const &msg): std::runtime_error(msg) {}
    BobashareException::BobashareException(std::string const &msg, nlohmann::json backtrace): std::runtime_error(msg) {
        this->error = backtrace;
    }
    const std::optional<nlohmann::json> BobashareException::backtrace() const noexcept {
        return error;
    }
}
