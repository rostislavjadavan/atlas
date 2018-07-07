#pragma once

#include "layer/base.hpp"
#include <memory>

namespace atlas {
    namespace core {
        
        class LayerContainer {
        public:
            static const int NUM_LAYERS_X = 4;
            static const int NUM_LAYERS_Y = 4;
            static const int NUM_LAYERS = NUM_LAYERS_X * NUM_LAYERS_Y;
            LayerContainer();
            ~LayerContainer();
            
            const std::shared_ptr<atlas::layer::Base>& getLayer(int index);
            
        private:
            std::shared_ptr<atlas::layer::Base> layers[NUM_LAYERS];
        };
    }
}
