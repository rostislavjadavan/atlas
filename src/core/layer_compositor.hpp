#pragma once

#include "layer_container.hpp"
#include "blend_shaders.hpp"
#include <memory>

namespace atlas {
    namespace core {
        class LayerCompositor {
        public:
            LayerCompositor(std::shared_ptr<LayerContainer> container, const AppSettings &settings);
            
            void update();
            const shared_ptr<ofFbo>& getFrame();
            
        private:
            std::shared_ptr<ofFbo> fbo;
            std::shared_ptr<LayerContainer> container;
            
            double lastElapsedTime = 0;
            double delta = 0;
            
            void renderLayer(int index);
            ofVboMesh quad;
            BlendShaders blendShaders;
        };
    }
}
