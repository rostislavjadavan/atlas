#pragma once

#include "../types.hpp"
#include "../../libs/of.hpp"

namespace atlas {
    namespace gui {
        namespace view {
            class Properties {
            public:
                void draw(ofRectangle rect, int selectedLayer);
            };
        }
    }
}
