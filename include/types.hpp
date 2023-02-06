#ifndef BOBACLIENT_TYPES_HPP
#define BOBACLIENT_TYPES_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <chrono>
#include <optional>

NLOHMANN_JSON_NAMESPACE_BEGIN
// https://json.nlohmann.me/features/arbitrary_types/#how-do-i-convert-third-party-types
template <typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(nlohmann::json &j, const std::optional<T> &opt);
    static void from_json(const nlohmann::json &j, std::optional<T> &opt);
};
NLOHMANN_JSON_NAMESPACE_END

namespace bobaclient::types {
    struct InfoResponse {
        std::string id;
        std::string url;
        std::string direct_url;
        std::string filename;
        std::string mimetype;
        // ISO 8601 format
        std::string creation_date;
        std::optional<std::string> expiry_date;
    };

    void from_json(const nlohmann::json &j, InfoResponse &r);
}

#endif
