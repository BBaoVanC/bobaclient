#ifndef BOBACLIENT_JSON_HPP
#define BOBACLIENT_JSON_HPP

#include "errors.hpp"
#include "types.hpp"

#include <nlohmann/json.hpp>
#include <optional>

NLOHMANN_JSON_NAMESPACE_BEGIN
    // https://json.nlohmann.me/features/arbitrary_types/#how-do-i-convert-third-party-types
    template <typename T>
    struct adl_serializer<std::optional<T>> {
        static void to_json(nlohmann::json &j, const std::optional<T> &opt) {
            if (opt == std::nullopt) {
                j = nullptr;
            } else {
                j = *opt; // this will call adl_serializer<T>::to_json which will
                          // find the free function to_json in T's namespace!
            }
        }
        static void from_json(const nlohmann::json &j, std::optional<T> &opt) {
            if (j.is_null()) {
                opt = std::nullopt;
            } else {
                opt = j.get<T>(); // same as above, but with
                                  // adl_serializer<T>::from_json
            }
        }
    };

    // https://json.nlohmann.me/features/arbitrary_types/#how-can-i-use-get-for-non-default-constructiblenon-copyable-types
    template <>
    struct adl_serializer<bobaclient::BobashareException> {
        static bobaclient::BobashareException from_json(const nlohmann::json &j) {
            return bobaclient::BobashareException(j.at("message").get<std::string>(), j.at("error"));
        }
    };
NLOHMANN_JSON_NAMESPACE_END

namespace bobaclient {
    void from_json(const nlohmann::json &j, InfoResponse &r);
}

#endif
