#include "bobaclient.hpp"

#include "errors.hpp"

#include <curl/curl.h>

bobaclient::Bobaclient::Bobaclient() {
    curl = curl_easy_init();
}
bobaclient::Bobaclient::~Bobaclient() {
    curl_easy_cleanup(curl);
}

bobaclient::types::InfoResponse bobaclient::Bobaclient::get_info(std::string const &url) {
    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, std::string *resp) {
        resp->append(ptr, size * nmemb);
        return size * nmemb;
    });
    const CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        throw errors::CurlException(curl_easy_strerror(res));
    }

    long code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
    if (code != 200) {
        // TODO
    }

    // TODO
}

// CurlResponse CurlWrapper::get_url(std::string const &url) {
//     CurlResponse response;
//     curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response.data);
//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, std::string &data) {
//         data.append(ptr, size * nmemb);
//         return size * nmemb;
//     });
//     const CURLcode res = curl_easy_perform(curl);
//     if (res != CURLE_OK) {
//         throw CurlException(curl_easy_strerror(res));
//     }
//     curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.response_code);
//     return response;
// }
