#pragma once

#include "layer_container.hpp"
#include <memory>

namespace atlas {
    namespace core {
        class LayerCompositor {
        public:
            LayerCompositor(std::shared_ptr<LayerContainer> container);
            
        private:
            std::shared_ptr<LayerContainer> container;
        };
    }
}
