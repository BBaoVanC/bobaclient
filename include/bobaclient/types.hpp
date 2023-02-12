#ifndef BOBACLIENT_TYPES_HPP
#define BOBACLIENT_TYPES_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <chrono>
#include <optional>
#include <iostream>

namespace bobaclient {
    struct InfoResponse {
        std::string id;
        std::string url;
        std::string direct_url;
        std::string filename;
        std::string mimetype;
        // ISO 8601 format
        std::string creation_date;
        std::optional<std::string> expiry_date;

        //std::ostream & operator<<(std::ostream &os) const;
    };
}

#endif
