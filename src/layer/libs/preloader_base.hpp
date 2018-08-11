#pragma once

#include "../../libs/of.hpp"

namespace atlas {
    namespace layer {
        namespace libs {
            class PreloaderBase {
            public:
                static const int WAITING = 0;
                static const int LOADING = 1;
                static const int PREPARED = 2;
            };
        }
    }
}
