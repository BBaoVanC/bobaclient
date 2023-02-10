#include "json.hpp"

#include "types.hpp"

#include <nlohmann/json.hpp>

using json = nlohmann::json;

// TODO: get this working
//namespace bobaclient {
//    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(InfoResponse, id, url, direct_url, filename, mimetype, creation_date, expiry_date)
//}

namespace bobaclient {
    void from_json(const json &j, InfoResponse &r) {
        j.at("id").get_to(r.id);
        j.at("url").get_to(r.url);
        j.at("direct_url").get_to(r.direct_url);
        j.at("filename").get_to(r.filename);
        j.at("mimetype").get_to(r.mimetype);
        j.at("creation_date").get_to(r.creation_date);
        j.at("expiry_date").get_to(r.expiry_date);
    }
}
