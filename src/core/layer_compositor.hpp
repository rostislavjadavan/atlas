#pragma once

#include "layer_container.hpp"
#include <memory>

namespace atlas {
    namespace core {
        class LayerCompositor {
        public:
            LayerCompositor(std::shared_ptr<LayerContainer> container, const AppSettings &settings);
            
            void update();
            const ofFbo& getFrame();
            
        private:
            std::shared_ptr<ofFbo> fbo;
            std::shared_ptr<LayerContainer> container;
            
            double lastElapsedTime = 0;
            double delta = 0;
        };
    }
}
