#include "json.hpp"

#include "errors.hpp"
#include "types.hpp"

#include <nlohmann/json.hpp>

// TODO: get this working
//namespace bobaclient {
//    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(InfoResponse, id, url, direct_url, filename, mimetype, creation_date, expiry_date)
//}

namespace bobaclient {
    void from_json(const nlohmann::json &j, InfoResponse &r) {
        j.at("id").get_to(r.id);
        j.at("url").get_to(r.url);
        j.at("direct_url").get_to(r.direct_url);
        j.at("filename").get_to(r.filename);
        j.at("mimetype").get_to(r.mimetype);
        j.at("creation_date").get_to(r.creation_date);
        j.at("expiry_date").get_to(r.expiry_date);
    }
    void from_json(const nlohmann::json &j, RequestException &e) {
        j.at("message").get_to(e.message);
        j.at("error").get_to(e.error);
    }
}

NLOHMANN_JSON_NAMESPACE_BEGIN
// no static: see https://stackoverflow.com/a/31305772
template <typename T>
void adl_serializer<std::optional<T>>::to_json(nlohmann::json &j, const std::optional<T> &opt) {
    if (opt == std::nullopt) {
        j = nullptr;
    } else {
        j = *opt; // this will call adl_serializer<T>::to_json which will
                  // find the free function to_json in T's namespace!
    }
}
template <typename T>
void adl_serializer<std::optional<T>>::from_json(const nlohmann::json &j, std::optional<T> &opt) {
    if (j.is_null()) {
        opt = std::nullopt;
    } else {
        opt = j.get<T>(); // same as above, but with
                          // adl_serializer<T>::from_json
    }
}
NLOHMANN_JSON_NAMESPACE_END
