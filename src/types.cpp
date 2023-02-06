#include "types.hpp"

#include <nlohmann/json.hpp>

//NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bobaclient::types::InfoResponse, id, url, direct_url, filename, mimetype, creation_date, expiry_date)

using json = nlohmann::json;

void bobaclient::types::from_json(const json &j, bobaclient::types::InfoResponse &r) {
    j.at("id").get_to(r.id);
    j.at("url").get_to(r.url);
    j.at("direct_url").get_to(r.direct_url);
    j.at("filename").get_to(r.filename);
    j.at("mimetype").get_to(r.mimetype);
    j.at("creation_date").get_to(r.creation_date);
    r.expiry_date = j.at("expiry_date").get<std::optional<std::string>>();
}

/*
void bobaclient::types::from_json(const json &j, std::optional<std::string> &r) {
    if (j.is_null()) {
        r = std::nullopt;
    } else {
        r = j.get<std::string>();
    }
}
*/
