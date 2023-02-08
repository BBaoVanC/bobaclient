#ifndef BOBACLIENT_JSON_HPP
#define BOBACLIENT_JSON_HPP

#include "types.hpp"

#include <nlohmann/json.hpp>
#include <optional>

NLOHMANN_JSON_NAMESPACE_BEGIN
// https://json.nlohmann.me/features/arbitrary_types/#how-do-i-convert-third-party-types
template <typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(nlohmann::json &j, const std::optional<T> &opt);
    static void from_json(const nlohmann::json &j, std::optional<T> &opt);
};
NLOHMANN_JSON_NAMESPACE_END

namespace bobaclient {
    void from_json(const nlohmann::json &j, InfoResponse &r);
}

#endif
