#pragma once

#include "../types.hpp"
#include "../../libs/of.hpp"

namespace atlas {
    namespace gui {
        namespace view {
            class Layers {
            public:
                void draw(ofRectangle rect, Events events);
                int getSelectedLayer();
            protected:
                int selectedLayer = 0;
            };
        }
    }
}
