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
                void disableSelections() {
                    this->selectEnabled = false;
                }
                void enableSelections() {
                    this->selectEnabled = true;
                }
            protected:
                int selectedLayer = 0;
                bool selectEnabled = true;
            };
        }
    }
}
