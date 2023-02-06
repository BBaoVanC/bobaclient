#ifndef BOBACLIENT_TYPES_HPP
#define BOBACLIENT_TYPES_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <chrono>
#include <optional>

namespace bobaclient::types {
    struct InfoResponse {
        std::string id;
        std::string url;
        std::string direct_url;
        std::string filename;
        std::string mimetype;
        std::chrono::time_point<std::chrono::system_clock> creation_date;
        std::optional<std::chrono::time_point<std::chrono::system_clock>> expiry_date;
    };

    void from_json(const nlohmann::json &j, InfoResponse &r);
    void from_json(const nlohmann::json &j, std::chrono::time_point<std::chrono::system_clock> &r);
    void from_json(const nlohmann::json &j, std::optional<std::chrono::time_point<std::chrono::system_clock>> &r);
}

#endif
