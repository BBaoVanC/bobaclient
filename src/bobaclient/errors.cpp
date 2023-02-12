#include <bobaclient/errors.hpp>

#include <nlohmann/json.hpp>
#include <string>
#include <optional>

using json = nlohmann::json;

namespace bobaclient {
    CurlException::CurlException(const std::string &msg): std::runtime_error(msg) {}

    BobashareException::BobashareException(const std::string &msg): std::runtime_error(msg) {}
    BobashareException::BobashareException(const std::string &msg, json backtrace): std::runtime_error(msg), error(backtrace) {}
    const std::optional<json> BobashareException::backtrace() const noexcept {
        return error;
    }
}
