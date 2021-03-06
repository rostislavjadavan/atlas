#pragma once

#include "../types.hpp"
#include "../../libs/of.hpp"

namespace atlas {
    namespace gui {
        namespace view {
            class PropertiesPartials {
            public:
                void createLayerGui(int index);
                void baseLayerPropsGui(int index);
                void bpmLayerPropsGui(int index);
            };
        }
    }
}
