#ifndef BOBACLIENT_TYPES_V1_HPP
#define BOBACLIENT_TYPES_V1_HPP

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
        std::chrono::nanoseconds creation_date;
        std::optional<std::chrono::nanoseconds> expiry_date;
    };
}

#endif
