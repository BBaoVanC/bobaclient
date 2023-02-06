#include "errors.hpp"

bobaclient::errors::CurlException::CurlException(std::string const &msg) {
    this->msg = msg;
}
const char *bobaclient::errors::CurlException::what() const noexcept {
    return msg.c_str();
}
