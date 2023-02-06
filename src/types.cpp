#include "types.hpp"

#include <nlohmann/json.hpp>

//NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(bobaclient::types::InfoResponse, id, url, direct_url, filename, mimetype, creation_date, expiry_date)

void bobaclient::types::from_json(const nlohmann::json &j, bobaclient::types::InfoResponse &r) {
    j.at("id").get_to(r.id);
    j.at("url").get_to(r.url);
    j.at("direct_url").get_to(r.direct_url);
    j.at("filename").get_to(r.filename);
    j.at("mimetype").get_to(r.mimetype);
    // TODO: give these real values
    //j.at("creation_date").get_to(r.creation_date);
    //j.at("expiry_date").get_to(r.expiry_date);
    //r.creation_date = 0;
    //r.expiry_date = std::nullopt;
}
void bobaclient::types::from_json(const nlohmann::json &j, std::chrono::time_point<std::chrono::system_clock> &r) {
    std::string val = j.get<std::string>();
    val >> std::chrono::parse("%F%z", r);
}
void bobaclient::types::from_json(const nlohmann::json &j, std::optional<std::chrono::time_point<std::chrono::system_clock>> &r) {
    if (j.is_null()) {
        r = std::nullopt;
    } else {
        //r = j.get();
    }
}
