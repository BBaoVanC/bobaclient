#include <iostream>
#include <string>
#include <curl/curl.h>
#include "curl.hpp"

int main() {
    bobaclient::CurlWrapper curl;
    std::string data;
    curl_easy_setopt(curl, CURLOPT_URL, "https://share.boba.best/api/v1/info/PJpmMIw7");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, void *userdata) {
        auto output = static_cast<std::string *>(userdata);
        output->append(ptr, size * nmemb);
        return size * nmemb;
    });
    const CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::clog << "failed: " << curl_easy_strerror(res) << std::endl;
    }

    std::clog << "data: " << data << std::endl;

    return 0;
}
