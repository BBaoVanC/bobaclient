#include "errors.hpp"

#include <string>

bobaclient::errors::CurlException::CurlException(std::string const &msg): msg(msg) {}
const char *bobaclient::errors::CurlException::what() const noexcept {
    return msg.c_str();
}

bobaclient::errors::RequestException::RequestException(std::string const &msg): msg(msg) {}
const char *bobaclient::errors::RequestException::what() const noexcept {
    return msg.c_str();
}
