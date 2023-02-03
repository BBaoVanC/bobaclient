#include "curl.hpp"

bobaclient::CurlWrapper::CurlWrapper() {
    curl = curl_easy_init();
}
bobaclient::CurlWrapper::~CurlWrapper() {
    curl_easy_cleanup(curl);
}
bobaclient::CurlWrapper::operator CURL *() {
    return curl;
}
