#ifndef BOBACLIENT_LIBBOBACLIENT_HPP
#define BOBACLIENT_LIBBOBACLIENT_HPP

#include "types.hpp"

#include <string>
#include <curl/curl.h>

namespace bobaclient {
    class Bobaclient {
    private:
        CURL *curl;
    public:
        Bobaclient();
        ~Bobaclient();

        // TODO: can these all be const functions
        types::InfoResponse get_info(std::string const &url);
    };
}

#endif
