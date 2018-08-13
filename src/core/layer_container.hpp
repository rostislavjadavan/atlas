#pragma once

#include "layer/base.hpp"
#include "../layer/base.hpp"
#include "../layer/empty.hpp"
#include "../layer/gif_directory.hpp"
#include "../layer/gif.hpp"
#include "../layer/text.hpp"
#include "../layer/image.hpp"
#include "../layer/image_slideshow.hpp"
#include "../libs/json.hpp"
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
            void setLayer(int index, int layerType);
            
            json saveJson();
            void loadJson(const json &j);
            
        private:
            std::shared_ptr<atlas::layer::Base> layers[NUM_LAYERS];
        };
    }
}
