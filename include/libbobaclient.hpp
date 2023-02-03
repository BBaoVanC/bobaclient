#ifndef LIBBOBACLIENT_LIBBOBACLIENT_HPP
#define LIBBOBACLIENT_LIBBOBACLIENT_HPP

#include <curl/curl.h>

namespace bobaclient {
    class Bobaclient {
        // TODO: replace CurlWrapper
        Bobaclient();
    private:
        CURL *curl;
    };
}

#endif
