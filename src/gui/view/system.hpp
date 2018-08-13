#pragma once

#include "../types.hpp"
#include "../../libs/of.hpp"

namespace atlas {
    namespace gui {
        namespace view {
            class System {
            public:
                void draw(ofRectangle rect);
            protected:
                char savename[1024];
            };
        }
    }
}
