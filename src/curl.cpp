#include <iostream>
#include <string>
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

bobaclient::CurlResponse bobaclient::CurlWrapper::get_url(std::string const& url) {
    bobaclient::CurlResponse response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, void *userdata) {
        auto output = static_cast<std::string *>(userdata);
        output->append(ptr, size * nmemb);
        return size * nmemb;
    });
    const CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        // TODO: error handling
        std::clog << "failed: " << curl_easy_strerror(res) << std::endl;
    }
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.response_code);
    return response;
}
