#ifndef BOBACLIENT_LIBBOBACLIENT_HPP
#define BOBACLIENT_LIBBOBACLIENT_HPP

#include "types.hpp"

#include <string>

namespace bobaclient {
    class Bobaclient {
    private:
        // this is actually CURL *
        void *curl;
    public:
        Bobaclient();
        ~Bobaclient();

        // TODO: can these all be const functions
        InfoResponse get_info(std::string const &url);
    };
}

#endif
