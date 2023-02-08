#include "errors.hpp"

#include <string>

namespace bobaclient {
    CurlException::CurlException(std::string const &msg): msg(msg) {}
    const char *CurlException::what() const noexcept {
        return msg.c_str();
    }

    RequestException::RequestException(std::string const &msg): msg(msg) {}
    const char *RequestException::what() const noexcept {
        return msg.c_str();
    }
}
