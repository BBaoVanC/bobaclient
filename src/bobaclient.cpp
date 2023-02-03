#include <iostream>
#include <curl/curl.h>

struct CurlWrapper {
    CurlWrapper() {
        curl = curl_easy_init();
    }
    ~CurlWrapper() {
        curl_easy_cleanup(curl);
    }
    operator CURL*() {
        return curl;
    }
private:
    CURL *curl;
};

int main() {
    std::clog << "Hello\n";

    CurlWrapper curl;
    std::string data;
    curl_easy_setopt(curl, CURLOPT_URL, "https://share.boba.best/api/v1/info/PJpmMIw7");
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, void *userdata) {
        auto output = static_cast<std::string *>(userdata);
        output->append(ptr, size * nmemb);
        return size * nmemb;
    });
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::clog << "failed: " << curl_easy_strerror(res) << std::endl;
    }

    std::clog << "data: " << data << std::endl;

    return 0;
}
