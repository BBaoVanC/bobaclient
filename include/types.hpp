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
        //std::chrono::nanoseconds creation_date;
        // TODO: these should not be std::chrono::nanoseconds, find an actual datetime type
        int creation_date;
        std::optional<std::chrono::nanoseconds> expiry_date;
    };

    void from_json(const nlohmann::json &j, InfoResponse &r);
}

#endif
