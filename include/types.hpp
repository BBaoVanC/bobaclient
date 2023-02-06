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
        // ISO 8601 format
        std::string creation_date;
        std::optional<std::string> expiry_date;
    };

    //void from_json(const nlohmann::json &j, InfoResponse &r);
    //void from_json(const nlohmann::json &j, std::optional<std::string> &r);
}

// TODO: fix this and split it up into .cpp as it should be
using json = nlohmann::json;
NLOHMANN_JSON_NAMESPACE_BEGIN
// https://json.nlohmann.me/features/arbitrary_types/#how-do-i-convert-third-party-types
template <typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(json &j, const std::optional<T> &opt) {
        if (opt == std::nullopt) {
            j = nullptr;
        } else {
            j = *opt; // this will call adl_serializer<T>::to_json which will
                      // find the free function to_json in T's namespace!
        }
    }
    static void from_json(const json &j, std::optional<T> &opt) {
        if (j.is_null()) {
            opt = std::nullopt;
        } else {
            opt = j.get<T>(); // same as above, but with
                              // adl_serializer<T>::from_json
        }
    }
};
NLOHMANN_JSON_NAMESPACE_END

#endif
