#include "errors.hpp"

#include <string>

namespace bobaclient {
    CurlException::CurlException(std::string const &msg): std::runtime_error(msg) {}

    BobashareException::BobashareException(std::string const &msg): message(msg) {}
    const char *BobashareException::what() const noexcept {
        return message.c_str();
    }
    const std::optional<nlohmann::json> BobashareException::backtrace() const noexcept {
        return error;
    }
}
