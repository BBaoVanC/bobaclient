#include <bobaclient/bobaclient.hpp>

#include <bobaclient/errors.hpp>
#include <bobaclient/json.hpp>

#include <nlohmann/json.hpp>

extern "C" {
    #include <curl/curl.h>
}

using json = nlohmann::json;

static constexpr char BOBASHARE_API_V1_INFO[] = "https://share.boba.best/api/v1/info/";

namespace bobaclient {
    Bobaclient::Bobaclient() {
        curl = curl_easy_init();
        if (!curl) {
            throw std::runtime_error("error creating libcurl easy handle");
        }
    }
    Bobaclient::~Bobaclient() {
        curl_easy_cleanup(curl);
    }

    std::string Bobaclient::get_url(const std::string &url) {
        std::string response;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](char *ptr, size_t size, size_t nmemb, std::string *resp) {
            resp->append(ptr, size * nmemb);
            return size * nmemb;
        });
        return response;
    }

    InfoResponse Bobaclient::get_info(const std::string &id) {
        const std::string response = this->get_url(BOBASHARE_API_V1_INFO + id);
        const CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            throw CurlException(curl_easy_strerror(res));
        }

        long code;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
        json data;
        data = json::parse(response); // can throw json::exception

        if (code > 299 || code < 200) {
            throw data.get<BobashareException>();
        }
        return data.get<InfoResponse>();
    }
}
