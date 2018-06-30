#pragma once

#include "layer/base.hpp"
#include <memory>

namespace atlas {
    namespace core {
        
        class LayerContainer {
        public:
            static const int NUM_LAYERS = 16;
            LayerContainer();
            ~LayerContainer();
            
        private:
            std::shared_ptr<atlas::layer::Base> layers[NUM_LAYERS];
        };
    }
}
