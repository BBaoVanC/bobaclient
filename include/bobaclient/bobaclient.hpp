#ifndef BOBACLIENT_LIBBOBACLIENT_HPP
#define BOBACLIENT_LIBBOBACLIENT_HPP

#include "types.hpp"

#include <string>


namespace bobaclient {
    class Bobaclient {
    private:
        // this is actually CURL *
        void *curl;

        // helper to make a GET request and get the entire body into string
        std::string get_url(const std::string &url);
    public:
        Bobaclient(const Bobaclient &) = delete;
        Bobaclient &operator=(Bobaclient) = delete;

        Bobaclient();
        ~Bobaclient();

        InfoResponse get_info(const std::string &url);
    };
}

#endif
